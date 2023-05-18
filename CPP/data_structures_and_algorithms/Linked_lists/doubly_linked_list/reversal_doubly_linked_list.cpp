#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

void reverseLinkedList(Node** head) {
    Node* current = *head;
    Node* temp = nullptr;

    // Swap prev and next pointers of each node
    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;  // Move to the next node
    }

    // Update the head pointer
    if (temp != nullptr) {
        *head = temp->prev;
    }
}

void printLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);

    // Create the doubly linked list: 1 <-> 2 <-> 3 <-> 4
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;

    cout << "Original Linked List: ";
    printLinkedList(head);

    reverseLinkedList(&head);

    cout << "Reversed Linked List: ";
    printLinkedList(head);

    return 0;
}

/**
 * @brief Reversing a doubly linked list explanation
 * 
 * In this program, the Node struct represents a node in the doubly linked list. 
 * The reverseLinkedList function takes a pointer to the head of the linked list as 
 * an argument and reverses the order of the nodes by swapping the prev and next pointers of each node. 
 * The printLinkedList function is used to print the elements of the linked list.
 * 
 * In the example given, the original doubly linked list is created with 
 * nodes containing values 1, 2, 3, and 4. 
 * After calling reverseLinkedList, the order of the nodes is reversed. 
 * The program prints both the original and reversed linked lists to demonstrate the reversal process.
 * 
 */
