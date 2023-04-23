import random

def play_hangman():
    # initialize the game
    wordlist = ["python", "java", "javascript", "ruby", "csharp", "php", "swift", "kotlin"]
    secret_word = random.choice(wordlist)
    word_length = len(secret_word)
    guesses = []
    max_attempts = 6
    attempts_left = max_attempts
    
    # loop until the player wins or loses
    while True:
        # show the current state of the word with underscores for unguessed letters
        word_state = ""
        for letter in secret_word:
            if letter in guesses:
                word_state += letter
            else:
                word_state += "_"
        print("Word: " + word_state)
        
        # get a guess from the player
        guess = input("Guess a letter: ")
        if guess in guesses:
            print("You already guessed that letter. Try again.")
            continue
        guesses.append(guess)
        
        # check if the guess is correct and update the number of attempts left
        if guess in secret_word:
            print("Correct!")
        else:
            print("Wrong!")
            attempts_left -= 1
        
        # check if the player has won or lost
        if attempts_left == 0:
            print("You lose! The word was " + secret_word)
            break
        elif "_" not in word_state:
            print("You win! The word was " + secret_word)
            break
        
        print("Attempts left: " + str(attempts_left))

play_hangman()
