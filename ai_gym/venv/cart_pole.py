import gym
import numpy as np

import torch
import torch.nn as nn
import torch.optim as optim
from torch.autograd import Variable

import matplotlib.pyplot as plt

# Hyperparameters
learning_rate = 0.01
gamma = 0.99

env = gym.make('CartPole-v0')
eps = np.finfo(np.float32).eps.item()


class Policy(nn.Module):
    def __init__(self):
        super(Policy, self).__init__()
        self.state_space = env.observation_space.shape[0]
        self.action_space = env.action_space.n

        self.l1 = nn.Linear(self.state_space, 128)
        self.l2 = nn.Linear(128, self.action_space)

        self.gamma = gamma

        # Episode policy and reward history
        self.policy_history = Variable(torch.Tensor())
        self.reward_episode = []

    def forward(self, x):
        model = torch.nn.Sequential(
            self.l1,
            nn.Dropout(p=0.6),
            nn.ReLU(),
            self.l2,
            nn.Softmax(dim=-1)
        )
        return model(x)

    def reset_var(self):
        self.policy_history = Variable(torch.Tensor())
        self.reward_episode = []


policy = Policy()
optimizer = optim.Adam(policy.parameters(), lr=learning_rate)


def select_action(initial_state):
    """
    The inital state is the output of the gym env. We apply the NN to it an
    then select the action that we want and return it.

    We also keep track of the log of the probability of the action
    that we've selected in order to backward it later.
    """
    # Select an action (0 or 1) by running policy model and choosing based on the probabilities in state
    state = torch.from_numpy(initial_state).type(torch.FloatTensor)
    state = policy(Variable(state))
    categorical = torch.distributions.Categorical(state)
    # Select an action based on the probabilities contains in the state.
    action = categorical.sample()

    # Add log probability of our chosen action to our history
    if len(policy.policy_history.size()) and policy.policy_history.size()[0] >= 1:
        # Calling view just to be able to use the cat method
        # This line is just basically adding the categorical.log_prob(action) to our policy.policy_history tensor.
        # log_prob return the log of the probability of the selected action.
        policy.policy_history = torch.cat([policy.policy_history, categorical.log_prob(action).view(1)])
    else:
        # log_prob construct an equivalent loss function of the the network
        policy.policy_history = torch.Tensor(categorical.log_prob(action).view(1))

    return action


def update_policy():
    R = 0
    rewards = []

    # Discount future rewards back to the present using gamma
    # This is specific to the Monte-Carlo method
    for r in policy.reward_episode[::-1]:
        R = r + policy.gamma * R
        rewards.insert(0, R)

    # Scale rewards
    rewards = torch.FloatTensor(rewards)

    # normalize the reward vector to guarantee stable convergence of weight and biases.
    # std is the standard derivation for the rewards.reward
    rewards = (rewards - rewards.mean()) / (rewards.std() + eps)

    # Calculate loss, which is the sum of the log of each selected action times the associated normalised reward time -1.
    loss = torch.sum(torch.mul(policy.policy_history, Variable(rewards)).mul(-1))

    # Update network weights
    optimizer.zero_grad()
    loss.backward()
    optimizer.step()


def main(episodes):
    running_reward = 10

    average_times = []
    episodes_list = []

    for episode in range(episodes):
        state = env.reset()  # Reset environment and record the starting state
        done = False

        for time in range(10000):
            action = select_action(state)
            # Step through environment using chosen action
            state, reward, done, _ = env.step(action.item())
            # Save reward
            policy.reward_episode.append(reward)
            if done:
                break

        # Used to determine when the environment is solved.
        running_reward = (running_reward * 0.99) + (time * 0.01)

        update_policy()
        policy.reset_var()


        if episode % 10 == 0:
            average_times.append(running_reward)
            episodes_list.append(episode)
            print('Episode {}\tLast length: {:5d}\tAverage length: {:.2f}'.format(episode, time, running_reward))
        if running_reward > env.spec.reward_threshold:
            print("Solved! Running reward is now {} and the last episode runs to {} time steps!".format(running_reward, time))
            break

    # Save and intialize episode history counters
    policy.policy_history = Variable(torch.Tensor())
    policy.reward_episode = []

    plt.plot(episodes_list, average_times)
    plt.title('Cart Pole challenge \n %s nn, %s learning_rate, %s gamma and %s dropout' % (hidden_layer_length, learning_rate, gamma, dropout))
    plt.xlabel('Episode')
    plt.ylabel('Average time')
    plt.show()


main(1000)
