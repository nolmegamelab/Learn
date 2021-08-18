import gym 

env = gym.make("Taxi-v3").env 

env.render()

print("Action Space {}".format(env.action_space))
print("State Space {}".format(env.observation_space))

