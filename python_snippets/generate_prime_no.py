import random

# Function to check if a number is prime
def is_prime(num):
    if num <= 1:
        return False
    for i in range(2, int(num**0.5)+1):
        if num % i == 0:
            return False
    return True

# Generate a random number of 100 digits
num = random.randint(10**(100-1), 10**100-1)

# Check if the number is prime
while not is_prime(num):
    num += 1

print(num)
