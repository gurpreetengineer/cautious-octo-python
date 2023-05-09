import random

# Create a list of card pairs
cards = ["A", "A", "B", "B", "C", "C", "D", "D", "E", "E", "F", "F", "G", "G", "H", "H"]
random.shuffle(cards)

# Define a function to display the game board
def display_board(board):
    print("-------------")
    print("|", board[0], "|", board[1], "|", board[2], "|", board[3], "|")
    print("-------------")
    print("|", board[4], "|", board[5], "|", board[6], "|", board[7], "|")
    print("-------------")
    print("|", board[8], "|", board[9], "|", board[10], "|", board[11], "|")
    print("-------------")
    print("|", board[12], "|", board[13], "|", board[14], "|", board[15], "|")
    print("-------------")

# Define a function to play the game
def play_game():
    # Create an empty board
    board = [" "] * 16
    
    # Keep track of the number of matches found
    matches = 0
    
    while matches < 8:
        # Display the game board
        display_board(board)
        
        # Get the player's first guess
        print("Enter the location of your first card (0-15):")
        guess1 = int(input())
        while board[guess1] != " ":
            print("That card has already been flipped. Choose a different card:")
            guess1 = int(input())
        board[guess1] = cards[guess1]
        display_board(board)
        
        # Get the player's second guess
        print("Enter the location of your second card (0-15):")
        guess2 = int(input())
        while board[guess2] != " ":
            print("That card has already been flipped. Choose a different card:")
            guess2 = int(input())
        board[guess2] = cards[guess2]
        display_board(board)
        
        # Check if the cards match
        if cards[guess1] == cards[guess2]:
            print("You found a match!")
            matches += 1
        else:
            print("Sorry, those cards do not match.")
            board[guess1] = " "
            board[guess2] = " "
        
    print("Congratulations, you found all the matches!")

# Play the game
play_game()
