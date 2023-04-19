import random

# Define the target phrase that we want to evolve to
target = "Hello, world!"

# Define the length of each individual's chromosome
chromosome_length = len(target)

# Define the size of the population
population_size = 100

# Define the probability of mutation
mutation_probability = 0.01

# Define the maximum number of generations
max_generations = 1000

# Define the fitness function
def fitness(chromosome):
    # Compute the fitness of the chromosome as the number of matching characters
    # between the chromosome and the target phrase
    fitness = 0
    for i in range(chromosome_length):
        if chromosome[i] == target[i]:
            fitness += 1
    return fitness

# Initialize the population with random chromosomes
population = []
for i in range(population_size):
    chromosome = ''.join(random.choice('abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ,.!') for j in range(chromosome_length))
    population.append(chromosome)

# Iterate through the generations
for generation in range(max_generations):

    # Evaluate the fitness of each individual in the population
    fitness_values = [fitness(chromosome) for chromosome in population]

    # Select the parents for the next generation using tournament selection
    parents = []
    for i in range(population_size):
        tournament_size = 5
        tournament = random.sample(range(population_size), tournament_size)
        tournament_fitness = [fitness_values[j] for j in tournament]
        winner = tournament[tournament_fitness.index(max(tournament_fitness))]
        parents.append(population[winner])

    # Create the offspring for the next generation using crossover and mutation
    offspring = []
    for i in range(population_size):
        parent1 = random.choice(parents)
        parent2 = random.choice(parents)
        crossover_point = random.randint(0, chromosome_length-1)
        child = parent1[:crossover_point] + parent2[crossover_point:]
        if random.random() < mutation_probability:
            mutation_point = random.randint(0, chromosome_length-1)
            child = child[:mutation_point] + random.choice('abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ,.!') + child[mutation_point+1:]
        offspring.append(child)

    # Replace the current population with the offspring for the next generation
    population = offspring

    # Check if we have reached the target phrase
    best_fitness = max(fitness_values)
    best_chromosome = population[fitness_values.index(best_fitness)]
    if best_chromosome == target:
        print("Generation:", generation)
        print("Best chromosome:", best_chromosome)
        break


# This script implements a genetic algorithm to evolve a population of strings towards a target phrase. 
# The algorithm starts by initializing a population of random strings and then iterates through a series 
# of generations, each time selecting parents, creating offspring through crossover and mutation, 
# and replacing the current population with the offspring. 

# The fitness of each individual is evaluated using a simple function that computes the number of 
# matching characters between the individual's chromosome and the target phrase. 
# The algorithm stops when the best individual in the population matches the target phrase.
