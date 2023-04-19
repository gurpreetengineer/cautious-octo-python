# Annealing :means: The process or art of treating substances by means of heat, so as to remove their
# brittleness and at the same time render them tough and more or less elastic.


import math
import random

def f(x):
    """The function to be minimized"""
    return math.sin(x) * (1 / (1 + math.exp(-x)))

def simulated_annealing(f, x_min, x_max, T, alpha):
    """Simulated annealing algorithm"""
    x = random.uniform(x_min, x_max)
    while T > 0.1:
        x_new = random.uniform(x_min, x_max)
        delta = f(x_new) - f(x)
        if delta < 0:
            x = x_new
        else:
            p = math.exp(-delta / T)
            if random.random() < p:
                x = x_new
        T *= alpha
    return x

# Example usage
result = simulated_annealing(f, -10, 10, 100, 0.95)
print("Result:", result)


# In this example, we define a function f(x) that we want to minimize using simulated annealing. 
# We then define the simulated_annealing function that takes the function to be minimized, 
# the minimum and maximum values of x, the initial temperature T, and the cooling factor alpha. 
# 
# The function starts at a random value of x and then iteratively generates new random values and 
# either accepts them if they improve the function value or accepts them with a probability 
# based on the temperature and the magnitude of the change. 
# 
# The temperature is reduced by multiplying by alpha at each iteration until it reaches a small value. 
# 
# Finally, the function returns the value of x that produced the minimum function value found during the search.

