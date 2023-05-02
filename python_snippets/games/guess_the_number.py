import random

# Generate a random number between 1 and 100
number = random.randint(1, 100)

# Initialize the number of guesses
num_guesses = 0

# Loop until the user guesses the number
while True:
    # Get the user's guess
    guess = int(input("Guess a number between 1 and 100: "))
    
    # Increment the number of guesses
    num_guesses += 1
    
    # Check if the guess is correct
    if guess == number:
        print(f"Congratulations! You guessed the number in {num_guesses} guesses.")
        break
    
    # Give hints if the guess is too high or too low
    elif guess < number:
        print("Too low. Guess again.")
    else:
        print("Too high. Guess again.")
