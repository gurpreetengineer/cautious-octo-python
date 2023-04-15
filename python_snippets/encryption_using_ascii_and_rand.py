import random

def encrypt(message):
    # Generate a random key
    key = random.randint(1, 26)
    
    # Convert the message to a list of ASCII codes
    ascii_codes = [ord(char) for char in message]
    
    # Shift each ASCII code by the key and convert back to characters
    encrypted_chars = [chr(code + key) for code in ascii_codes]
    
    # Concatenate the encrypted characters into a string and return the key and message
    encrypted_message = "".join(encrypted_chars)
    return key, encrypted_message

def decrypt(key, encrypted_message):
    # Convert the encrypted message to a list of ASCII codes
    ascii_codes = [ord(char) for char in encrypted_message]
    
    # Shift each ASCII code back by the key and convert back to characters
    decrypted_chars = [chr(code - key) for code in ascii_codes]
    
    # Concatenate the decrypted characters into a string and return the message
    decrypted_message = "".join(decrypted_chars)
    return decrypted_message
