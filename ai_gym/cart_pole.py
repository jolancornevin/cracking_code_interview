import gym
env = gym.make('CartPole-v0')
env.reset()

for i in range(1000):
    env.render()
    state, reward, done, _ = env.step(1) 
