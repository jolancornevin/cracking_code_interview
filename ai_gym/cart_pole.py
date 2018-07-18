import gym
import time

import torch
import torch.nn as nn
import torch.nn.functional as F

class NeuralNet(nn.Module):
    def __init__(self):
        super(NeuralNet, self).__init__()
        
        self.fc1 = nn.Linear(4, 30)
        self.fc2 = nn.Linear(30, 2)

    def forward(self, state):
        x = F.relu(self.fc1(state))
        return self.fc2(x)
    

env = gym.make('CartPole-v0')
env.reset()

for i in range(100):
    env.render()
    state, reward, done, _ = env.step(0) 

    time.sleep(0.2)

    # The cart is too far from the center
    if done:
        break

    print state

env.done()
