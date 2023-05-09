import sqlite3

# Refer cautious-octo-python/Documentations/bank_account_management_code_explanation.txt for more info.

# Connect to the SQLite database
conn = sqlite3.connect('bank_accounts.db')

# Create a table for the bank accounts
conn.execute('''CREATE TABLE IF NOT EXISTS accounts
             (id INTEGER PRIMARY KEY AUTOINCREMENT,
              name TEXT NOT NULL,
              balance REAL NOT NULL);''')

# Define a function to create a new bank account
def create_account(name, balance):
    # Insert the new account into the database
    conn.execute("INSERT INTO accounts (name, balance) VALUES (?, ?)", (name, balance))
    conn.commit()
    print(f"Account created for {name} with balance {balance}.")

# Define a function to deposit money into a bank account
def deposit(id, amount):
    # Get the current balance of the account
    cursor = conn.execute("SELECT balance FROM accounts WHERE id = ?", (id,))
    balance = cursor.fetchone()[0]
    
    # Update the balance in the database
    new_balance = balance + amount
    conn.execute("UPDATE accounts SET balance = ? WHERE id = ?", (new_balance, id))
    conn.commit()
    print(f"Deposited {amount} into account {id}. New balance is {new_balance}.")

# Define a function to withdraw money from a bank account
def withdraw(id, amount):
    # Get the current balance of the account
    cursor = conn.execute("SELECT balance FROM accounts WHERE id = ?", (id,))
    balance = cursor.fetchone()[0]
    
    # Check if the account has enough balance to withdraw the amount
    if balance < amount:
        print("Insufficient balance. Withdrawal cancelled.")
        return
    
    # Update the balance in the database
    new_balance = balance - amount
    conn.execute("UPDATE accounts SET balance = ? WHERE id = ?", (new_balance, id))
    conn.commit()
    print(f"Withdrew {amount} from account {id}. New balance is {new_balance}.")

# Define a function to check the balance of a bank account
def check_balance(id):
    # Get the current balance of the account
    cursor = conn.execute("SELECT balance FROM accounts WHERE id = ?", (id,))
    balance = cursor.fetchone()[0]
    
    # Print the balance
    print(f"Balance of account {id} is {balance}.")

# Define a function to view the transaction history of a bank account
def view_history(id):
    # Get the transaction history of the account
    cursor = conn.execute("SELECT * FROM transactions WHERE account_id = ?", (id,))
    history = cursor.fetchall()
    
    # Print the transaction history
    print(f"Transaction history of account {id}:")
    for transaction in history:
        print(transaction)

# Create a table for the transaction history
conn.execute('''CREATE TABLE IF NOT EXISTS transactions
             (id INTEGER PRIMARY KEY AUTOINCREMENT,
              account_id INTEGER NOT NULL,
              type TEXT NOT NULL,
              amount REAL NOT NULL,
              timestamp TIMESTAMP DEFAULT CURRENT_TIMESTAMP);''')

# Define a function to record a transaction
def record_transaction(account_id, type, amount):
    # Insert the transaction into the database
    conn.execute("INSERT INTO transactions (account_id, type, amount) VALUES (?, ?, ?)", (account_id, type, amount))
    conn.commit()

# Sample usage
create_account("Alice", 1000)
create_account("Bob", 500)
deposit(1, 500)
withdraw(2, 200)
check_balance(1)
view_history(1)

# Close the database connection
conn.close()

