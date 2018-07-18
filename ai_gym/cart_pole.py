import gym
env = gym.make('CartPole-v0')
env.reset()

for i in range(100):
    env.render()
    state, reward, done, _ = env.step(0) 
    
    # The cart is too far from the center
    if done:
        break

    print state

env.done()
