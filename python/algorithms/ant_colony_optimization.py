import random

# Define the problem
cities = ['A', 'B', 'C', 'D', 'E']
distances = {
    ('A', 'B'): 2, ('A', 'C'): 4, ('A', 'D'): 5, ('A', 'E'): 3,
    ('B', 'C'): 1, ('B', 'D'): 3, ('B', 'E'): 2,
    ('C', 'D'): 2, ('C', 'E'): 4,
    ('D', 'E'): 1
}

# Define parameters
num_ants = 10
num_iterations = 100
evaporation_rate = 0.5
alpha = 1
beta = 2
q = 100
pheromone_deposit = {}

# Initialize pheromone deposit
for city1 in cities:
    for city2 in cities:
        if city1 != city2:
            pheromone_deposit[(city1, city2)] = 1

# Define helper functions
def select_next_city(current_city, unvisited_cities):
    # Calculate the probabilities of moving to each unvisited city
    probabilities = []
    for city in unvisited_cities:
        numerator = (pheromone_deposit[(current_city, city)] ** alpha) * ((1 / distances[(current_city, city)]) ** beta)
        probabilities.append(numerator)
    total_probability = sum(probabilities)
    probabilities = [p / total_probability for p in probabilities]
    
    # Select the next city based on the probabilities
    next_city_index = random.choices(range(len(unvisited_cities)), weights=probabilities)[0]
    return unvisited_cities[next_city_index]

# Run the algorithm
best_path = None
best_distance = float('inf')
for iteration in range(num_iterations):
    for ant in range(num_ants):
        # Initialize the ant's path and visited cities
        path = []
        current_city = random.choice(cities)
        unvisited_cities = set(cities)
        unvisited_cities.remove(current_city)
        
        # Build the ant's path
        while unvisited_cities:
            next_city = select_next_city(current_city, unvisited_cities)
            path.append((current_city, next_city))
            unvisited_cities.remove(next_city)
            current_city = next_city
        path.append((current_city, path[0][0])) # Complete the loop
        
        # Update the pheromone deposit
        distance = sum([distances[pair] for pair in path])
        if distance < best_distance:
            best_distance = distance
            best_path = path
        for pair in path:
            pheromone_deposit[pair] = (1 - evaporation_rate) * pheromone_deposit[pair] + q / distance
    
    # Evaporate the pheromone deposit
    for pair in pheromone_deposit:
        pheromone_deposit[pair] *= evaporation_rate

# Print the best path and distance
print("Best path:", best_path)
print("Best distance:", best_distance)


# Ant Colony Optimization (ACO) is a metaheuristic algorithm inspired by the foraging behavior of ants.

# This script implements the Ant Colony Optimization algorithm to find the shortest path that visits all cities 
# in a given set of cities and distances between them. 
# 
# The script defines the problem by specifying the cities 
# and distances between them, and then initializes the parameters and pheromone deposit. 
# It also defines helper functions for selecting the next city and updating the pheromone deposit.



