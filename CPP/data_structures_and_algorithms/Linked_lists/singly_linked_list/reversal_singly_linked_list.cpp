#include <iostream>

using namespace std;

struct Node
{
  int data;
  Node *next;
};

Node *reverseLinkedList(Node *head)
{
  Node *prev = nullptr;
  Node *current = head;
  Node *next = nullptr;

  while (current != nullptr)
  {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }

  return prev;
}

void printLinkedList(Node *head)
{
  Node *current = head;

  while (current != nullptr)
  {
    cout << current->data << " ";
    current = current->next;
  }

  cout << endl;
}

int main()
{
  // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
  Node *head = new Node();
  head->data = 1;

  Node *second = new Node();
  second->data = 2;
  head->next = second;

  Node *third = new Node();
  third->data = 3;
  second->next = third;

  Node *fourth = new Node();
  fourth->data = 4;
  third->next = fourth;

  Node *fifth = new Node();
  fifth->data = 5;
  fourth->next = fifth;
  fifth->next = nullptr;

  cout << "Original Linked List: ";
  printLinkedList(head);

  // Reverse the linked list
  Node *reversedHead = reverseLinkedList(head);

  cout << "Reversed Linked List: ";
  printLinkedList(reversedHead);

  // Clean up memory
  Node *current = reversedHead;
  while (current != nullptr)
  {
    Node *temp = current;
    current = current->next;
    delete temp;
  }

  return 0;
}

/**
 * @brief Reversing a singly linked list explanation
 * 
 * In this program, we define a struct Node representing a node in the linked list. 
 * The reverseLinkedList function takes the head of the linked list as input and reverses the list 
 * by iteratively changing the next pointers of each node. 
 * The function returns the new head of the reversed list. 
 * The printLinkedList function is used to print the elements of the linked list.
 * 
 * In the example given, we create a linked list with elements 1, 2, 3, 4, 5. 
 * The program prints the original linked list and then reverses it using the reverseLinkedList function. 
 * 
 * Finally, it prints the reversed linked list.
 * 
 * Note that this program assumes a singly linked list. 
 * If you want to reverse a doubly linked list, you need to modify the node structure accordingly and 
 * adjust the reversal logic to handle the previous pointers in addition to the next pointers.
 * 
 */
