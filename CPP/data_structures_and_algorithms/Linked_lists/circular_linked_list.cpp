#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* curr = head;
            while (curr->next != head) {
                curr = curr->next;
            }
            curr->next = newNode;
            newNode->next = head;
            head = newNode;
        }
        cout << "Inserted " << data << " at the beginning." << endl;
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* curr = head;
            while (curr->next != head) {
                curr = curr->next;
            }
            curr->next = newNode;
            newNode->next = head;
        }
        cout << "Inserted " << data << " at the end." << endl;
    }

    void deleteNode(int data) {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }

        Node* curr = head;
        Node* prev = nullptr;

        while (curr->next != head) {
            if (curr->data == data) {
                break;
            }
            prev = curr;
            curr = curr->next;
        }

        // If the node to be deleted is the head node
        if (curr == head) {
            Node* last = head;
            while (last->next != head) {
                last = last->next;
            }
            head = head->next;
            last->next = head;
        } else {
            prev->next = curr->next;
        }

        delete curr;
        cout << "Deleted " << data << " from the list." << endl;
    }

    bool search(int data) {
        if (head == nullptr) {
            cout << "List is empty. Cannot search." << endl;
            return false;
        }

        Node* curr = head;
        do {
            if (curr->data == data) {
                cout << data << " is found in the list." << endl;
                return true;
            }
            curr = curr->next;
        } while (curr != head);

        cout << data << " is not found in the list." << endl;
        return false;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        cout << "Circular Linked List: ";
        Node* curr = head;
        do {
            cout << curr->data << " ";
            curr = curr->next;
        } while (curr != head);
        cout << endl;
    }
};

int main() {
    CircularLinkedList cll;

    cll.insertAtBeginning(5);
    cll.insertAtBeginning(10);
    cll.insertAtEnd(15);
    cll.insertAtEnd(20);
    cll.display();

    cll.deleteNode(10);
    cll.display();

    cll.search(15);
    cll.search(25);

    return 0;
}

/**
 * @brief Circular linked list explanation
 * 
 * In this program, the Node class represents a node in the circular linked list. 
 * The CircularLinkedList class encapsulates the circular linked list and 
 * provides methods for insertion at the beginning and end, deletion of a node, 
 * searching for a value, and displaying the list.
 * 
 * The program demonstrates the usage of the circular linked list by 
 * inserting elements at the beginning and end, 
 * deleting a node, 
 * searching for values, and 
 * displaying the list after each operation.
 * 
 * Note that the circular linked list maintains a circular connection where 
 * the last node points back to the first node, forming a circle.
 * 
 */
