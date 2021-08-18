import gym 
import numpy as np
import random
from IPython.display import clear_output
from time import sleep

def print_frames(frames):
    for i, frame in enumerate(frames):
        clear_output(wait=True)
        print(frame['frame'])
        print(f"Timestep: {i + 1}")
        print(f"State: {frame['state']}")
        print(f"Action: {frame['action']}")
        print(f"Reward: {frame['reward']}")
        sleep(.1)

env = gym.make("Taxi-v3").env 

env.s = 328  # set environment to illustration's state

q_table = np.zeros([env.observation_space.n, env.action_space.n])

alpha = 0.1 
gamma = 0.6 
epsilon = 0.1 

all_epochs = [] 
all_penalties = []

epochs = 0
penalties, reward = 0, 0

frames = [] # for animation

state = env.reset() 
epochs, penalties, reward = 0, 0, 0
done = False 

while not done:

    if random.uniform(0, 1) < epsilon: 
        action = env.action_space.sample() 
    else: 
        action = np.argmax(q_table[state])            

    next_state, reward, done, info = env.step(action)        

    frames.append({
    'frame': env.render(mode='ansi'),
    'state': state,
    'action': action,
    'reward': reward
    })
        
    if reward == -10:
        penalties += 1
    
    old_value = q_table[state, action] 
    next_max = np.max(q_table[next_state])
    new_value = (1-alpha) * old_value + alpha * (reward + gamma * next_max)

    q_table[state, action] = new_value

    state = next_state
    epochs += 1 

print_frames(frames)

