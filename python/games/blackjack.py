import random

class Card:
    def __init__(self, suit, value):
        self.suit = suit
        self.value = value
    
    def __str__(self):
        return f"{self.value} of {self.suit}"
    
class Deck:
    def __init__(self):
        self.cards = []
        self.build_deck()
    
    def build_deck(self):
        for suit in ["Hearts", "Diamonds", "Clubs", "Spades"]:
            for value in range(2, 11):
                self.cards.append(Card(suit, str(value)))
            for value in ["Jack", "Queen", "King", "Ace"]:
                self.cards.append(Card(suit, value))
    
    def shuffle(self):
        random.shuffle(self.cards)
    
    def deal(self):
        return self.cards.pop(0)
    
class Hand:
    def __init__(self):
        self.cards = []
        self.value = 0
        self.aces = 0
    
    def add_card(self, card):
        self.cards.append(card)
        if card.value in ["Jack", "Queen", "King"]:
            self.value += 10
        elif card.value == "Ace":
            self.value += 11
            self.aces += 1
        else:
            self.value += int(card.value)
        while self.value > 21 and self.aces:
            self.value -= 10
            self.aces -= 1
    
    def __str__(self):
        return ", ".join(str(card) for card in self.cards)
    
class Blackjack:
    def __init__(self):
        self.deck = Deck()
        self.deck.shuffle()
        self.player_hand = Hand()
        self.dealer_hand = Hand()
    
    def play(self):
        print("Welcome to Blackjack!\n")
        
        # Deal initial cards
        for _ in range(2):
            self.player_hand.add_card(self.deck.deal())
            self.dealer_hand.add_card(self.deck.deal())
        
        # Show hands
        print("Dealer's hand: X,", self.dealer_hand.cards[1])
        print("Your hand:", self.player_hand, "(value:", self.player_hand.value, ")\n")
        
        # Player's turn
        while self.player_hand.value < 21:
            action = input("Hit or stand? ").lower()
            if action == "hit":
                self.player_hand.add_card(self.deck.deal())
                print("Your hand:", self.player_hand, "(value:", self.player_hand.value, ")")
            elif action == "stand":
                break
        
        # Check if player busts
        if self.player_hand.value > 21:
            print("Busted! You lose.")
            return
        
        # Dealer's turn
        while self.dealer_hand.value < 17:
            self.dealer_hand.add_card(self.deck.deal())
        print("Dealer's hand:", self.dealer_hand, "(value:", self.dealer_hand.value, ")")
        
        # Check for winner
        if self.dealer_hand.value > 21:
            print("Dealer busted! You win!")
        elif self.dealer_hand.value > self.player_hand.value:
            print("Dealer wins!")
        elif self.dealer_hand.value < self.player_hand.value:
            print("You win!")
        else:
            print("It's a tie!")
        
blackjack = Blackjack()
blackjack.play()
