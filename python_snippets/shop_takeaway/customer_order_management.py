import sqlite3

# Connect to the database
conn = sqlite3.connect('menu.db')

# Define the function to display the menu
def display_menu():
    cursor = conn.execute("SELECT item_name, item_price FROM menu")
    for row in cursor:
        print(row[0], '-', row[1])

# Define the function to take the customer's order
def take_order():
    order = {}
    while True:
        item_name = input("Enter the name of the item you want to order (or 'done' to finish): ")
        if item_name.lower() == 'done':
            break
        cursor = conn.execute("SELECT item_price FROM menu WHERE item_name=?", (item_name,))
        row = cursor.fetchone()
        if row is None:
            print("Invalid item name, please try again")
            continue
        item_price = row[0]
        item_quantity = int(input("Enter the quantity of the item: "))
        order[item_name] = (item_price, item_quantity)
    return order

# Define the function to create an order
def create_order(order):
    total_price = 0
    for item_name, (item_price, item_quantity) in order.items():
        total_price += item_price * item_quantity
    return total_price

# Define the function to deliver the order
def deliver_order(total_price):
    print("Your total order price is:", total_price)

# Define the main program loop
def main():
    display_menu()
    order = take_order()
    total_price = create_order(order)
    deliver_order(total_price)

# Run the main program loop
if __name__ == '__main__':
    main()
