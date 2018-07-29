## Cart Pole problem - Policy Gradient
The solution is highly inspired from this website: https://medium.com/@ts1829/policy-gradient-reinforcement-learning-in-pytorch-df1383ea0baf

This problem is solved with a Neural Network and reinforcement learning. 

Lexique:
- `π`: a Policy or the probability to take a certain action, given the state.
- `θ` represents parameters that we use to learn this function or, in other words, the weights of the network.
- `α`: the learning rate
- `∇θ`: the derivative of the weights
- `vt`: the total reward
- `∆θt = α ∇θ log πθ(st, at)vt`: The Monte-Carlo formula

The notions that are used here are:
- **Policy Gradients**: which is useful when solving a problem that is not from the classification class. The main assumption is an episodic setting where an agent engages in multiple **trajectories** in its environment from start to end where a trajectory would be a tuple of state, action, reward.
    - The **Monte Carlo** method says that we should group our trajectories by episode (that is to say by games).
    - if we know the gradient of parameters to make the probability of taking action A from state S more likely, we adjust the parameters in that direction to the scale of the return for taking the action. So, like this: `θ = θ + α * ∇θ * vt` we are going to update, for each step, our weight and we are pondering so changes by the total reward left. So a bad action will lead to an end of the episode and thus a smaller reward, whereas a good action would do the contrary.
- **Dropout**: small trick that consists in dropping out some part of the NN at each step to avoid overfitting. It required more steps, but epoch are faster. It takes a probability as a parameter which is going to used to keep or not Neurons.
- **Adam Optimiser**: the algorithm is an extension to stochastic gradient descent.
- **Reward trick**: as the reward is constant for each step, what we do instead is use a long-term reward vt where vt is the discounted sum of all future rewards for the length of the episode. In this way, the longer the episode runs into the future, the greater the reward for a particular state-action pair in the present. We also discount the reward the further we go in the future: if an episode lasts 5 steps and the discount factor is 0.99, the reward for each step will be [4.90, 3.94, 2.97, 1.99, 1]

### Experiments on parameters, with 1000 episodes:
- Increasing the **size of the hidden layers** leads to a slower learn but a better score, until a point where the NN stop learning at all.
- In a general way, the NN always overfit and stop performing after a certain among of episodes.
- The **dropout** has a huge influence on the result. Disabling it leads to very bad results. But of course, the higher the dropout is, the slower the NN learns.
- Decreasing the **gamma rate** has a bad influence over the network. Decreasing it with more than 1 kills the NN.
- Increasing the learning rate:
    - from 0.001 to 0.005 **solved the problem**!
    - with an order of magnitude higher than one has a bad influence over the NN, although not as much as the gamma parameter.
    - learning rate thare decreasing over episodes
        - Decreasing the learning rate from a small number often dommage the NN but it still solve the pb
        - Decreasing the learning rate a lot but one time also dommage the NN but it still solve the pb
    - learning rate that drops every fixed number of episodes by a percentage.
        - Decreasing the learning rate by a percentage after a certain number of episodes break the NN
- Increasing the hidden layer:
    - to 2 seems to lead to a higher resistance to over fitting, but slower learning and no reach of a solution. Also, way more less and less neurons are required.
    - to 3 same. Also, we can note that those NN are way more resilient to changes of the dropout. The learning also seems to be slower. With more episodes, 


#### Playing with Hidden layer size
1024 Hidden layer, not lucky

![Example 1](https://github.com/jolancornevin/loving_algorithm/blob/master/docs/img/cart_pole_1.png)

1024 Hidden layer

![Example 2](https://github.com/jolancornevin/loving_algorithm/blob/master/docs/img/cart_pole_2.png)

512 Hidden layer

![Example 3](https://github.com/jolancornevin/loving_algorithm/blob/master/docs/img/cart_pole_3.png)

256 Hidden layer

![Example 4](https://github.com/jolancornevin/loving_algorithm/blob/master/docs/img/cart_pole_4.png)

128 Hidden layer

![Example 5](https://github.com/jolancornevin/loving_algorithm/blob/master/docs/img/cart_pole_5.png)

#### Playing with dropout
Dropout = 0.4

![Example 6](https://github.com/jolancornevin/loving_algorithm/blob/master/docs/img/cart_pole_6.png)

Dropout = 0.6

![Example 5](https://github.com/jolancornevin/loving_algorithm/blob/master/docs/img/cart_pole_5.png)

Dropout = 0.8

![Example 7](https://github.com/jolancornevin/loving_algorithm/blob/master/docs/img/cart_pole_7.png)

#### Playing with Gamma

Gamma = 0.9

![Example 8](https://github.com/jolancornevin/loving_algorithm/blob/master/docs/img/cart_pole_8.png)

#### Playing with the Learning Rate
Learning rate = 0.01

![Example 9](https://github.com/jolancornevin/loving_algorithm/blob/master/docs/img/cart_pole_9.png)

Learning rate = 0.005 **SOLVED with 640 episodes**

![Example 10](https://github.com/jolancornevin/loving_algorithm/blob/master/docs/img/cart_pole_10.png)

#### Playing with Layers
2 Hidden layers

![Example 11](https://github.com/jolancornevin/loving_algorithm/blob/master/docs/img/cart_pole_11.png)

3 Hidden layers **SOLVED with 3690 episodes**

![Example 12](https://github.com/jolancornevin/loving_algorithm/blob/master/docs/img/cart_pole_12.png)

#### Playing with dynamic learning rate

![Example 13](https://github.com/jolancornevin/loving_algorithm/blob/master/docs/img/cart_pole_13.png)
