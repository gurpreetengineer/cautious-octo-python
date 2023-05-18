#include <iostream>
#include <map>

using namespace std;

void addContact(map<string, string>& phoneBook, const string& name, const string& phoneNumber) {
    phoneBook[name] = phoneNumber;
    cout << "Contact added successfully." << endl;
}

void searchContact(const map<string, string>& phoneBook, const string& name) {
    auto it = phoneBook.find(name);
    if (it != phoneBook.end()) {
        cout << "Name: " << it->first << "\tPhone Number: " << it->second << endl;
    } else {
        cout << "Contact not found." << endl;
    }
}

void deleteContact(map<string, string>& phoneBook, const string& name) {
    auto it = phoneBook.find(name);
    if (it != phoneBook.end()) {
        phoneBook.erase(it);
        cout << "Contact deleted successfully." << endl;
    } else {
        cout << "Contact not found." << endl;
    }
}

void displayPhoneBook(const map<string, string>& phoneBook) {
    if (phoneBook.empty()) {
        cout << "Phone book is empty." << endl;
        return;
    }

    cout << "Phone Book:" << endl;
    for (const auto& entry : phoneBook) {
        cout << "Name: " << entry.first << "\tPhone Number: " << entry.second << endl;
    }
}

int main() {
    map<string, string> phoneBook;

    // Add contacts to the phone book
    addContact(phoneBook, "Alice", "1234567890");
    addContact(phoneBook, "Bob", "9876543210");
    addContact(phoneBook, "Charlie", "5555555555");

    // Search for a contact
    searchContact(phoneBook, "Bob");

    // Delete a contact
    deleteContact(phoneBook, "Alice");

    // Display the phone book
    displayPhoneBook(phoneBook);

    return 0;
}

/**
 * @brief Phone book using maps explanation
 * 
 * In this program, we define a phoneBook map with names as keys and corresponding phone numbers as values. 
 * The program provides functions for adding a contact, searching for a contact, deleting a contact, and displaying the phone book.
 * 
 * The addContact function inserts a new contact into the phone book map. 
 * The searchContact function looks up a contact by name and displays the corresponding phone number if found. 
 * The deleteContact function removes a contact from the phone book if it exists. 
 * The displayPhoneBook function prints all the contacts in the phone book.
 * 
 * In the example given, we add three contacts, 
 * search for a contact, 
 * delete a contact, and 
 * display the phone book to demonstrate the phone book application using a map.
 * 
 * Remember to modify and enhance the program as per your specific requirements, 
 * such as adding additional fields or functionalities for each contact.
 * 
 */
