import random

# Define the card suits and ranks
suits = ['hearts', 'diamonds', 'clubs', 'spades']
ranks = ['2', '3', '4', '5', '6', '7', '8', '9', '10', 'Jack', 'Queen', 'King', 'Ace']

# Define the deck of cards
deck = [(rank, suit) for suit in suits for rank in ranks]

# Define the starting hand size and the number of community cards
hand_size = 2
community_cards_size = 5

# Define the functions to shuffle and deal the cards
def shuffle_deck():
    random.shuffle(deck)

def deal_hand():
    return [deck.pop() for _ in range(hand_size)]

def deal_community_cards():
    return [deck.pop() for _ in range(community_cards_size)]

# Define the function to evaluate a hand
def evaluate_hand(hand, community_cards):
    # Combine the hand and community cards
    all_cards = hand + community_cards
    # TODO: Implement hand evaluation logic
    # For example, you can use the library "poker" to get the best hand possible in Hold'em
    return "High card"

# Define the main game loop
def play_poker():
    print("Welcome to Python Poker!")
    while True:
        # Shuffle the deck and deal the cards
        shuffle_deck()
        hand = deal_hand()
        community_cards = deal_community_cards()
        print("Your hand:", hand)
        print("Community cards:", community_cards)

        # Evaluate the hand and print the result
        hand_rank = evaluate_hand(hand, community_cards)
        print("Your hand rank:", hand_rank)

        # Ask the player if they want to play again
        play_again = input("Do you want to play again? (y/n)")
        if play_again.lower() != 'y':
            break

# Start the game
play_poker()
