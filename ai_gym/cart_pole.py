import gym
env = gym.make('CartPole-v0')
env.reset()

def is_over(state):
    pos = state[0]
    angle = state[2]

    # The cart is too far from the center
    if pos > 2.4 or pos < -2.4:
        return True
    if angle > 1.5 or angle < -1.5:
        return True
    return False

for i in range(100):
    env.render()
    state, reward, done, _ = env.step(0) 
    
    # The cart is too far from the center
    if is_over(state):
        env.close()
        break

    print state
