import random

print("Welcome to Rock, Paper, Scissors game!")

# Possible choices
choices = ["rock", "paper", "scissors"]

# Ask for user's choice
player_choice = input("Choose rock, paper or scissors: ").lower()

# Make computer's choice
computer_choice = random.choice(choices)

# Print choices
print("You chose:", player_choice)
print("Computer chose:", computer_choice)

# Determine the winner
if player_choice == computer_choice:
    print("It's a tie!")
elif player_choice == "rock":
    if computer_choice == "paper":
        print("Computer wins!")
    else:
        print("You win!")
elif player_choice == "paper":
    if computer_choice == "scissors":
        print("Computer wins!")
    else:
        print("You win!")
elif player_choice == "scissors":
    if computer_choice == "rock":
        print("Computer wins!")
    else:
        print("You win!")
else:
    print("Invalid choice, please choose rock, paper, or scissors.")
