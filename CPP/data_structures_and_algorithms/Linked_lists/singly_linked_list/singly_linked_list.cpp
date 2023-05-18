#include <iostream>

using namespace std;

class Node
{
public:
  int data;
  Node *next;

  Node(int value)
  {
    data = value;
    next = nullptr;
  }
};

class LinkedList
{
private:
  Node *head;

public:
  LinkedList()
  {
    head = nullptr;
  }

  void insertAtBeginning(int value)
  {
    Node *newNode = new Node(value);
    newNode->next = head;
    head = newNode;
  }

  void insertAtEnd(int value)
  {
    Node *newNode = new Node(value);

    if (head == nullptr)
    {
      head = newNode;
      return;
    }

    Node *current = head;
    while (current->next != nullptr)
    {
      current = current->next;
    }

    current->next = newNode;
  }

  void deleteNode(int value)
  {
    if (head == nullptr)
    {
      cout << "Linked list is empty. Deletion failed." << endl;
      return;
    }

    if (head->data == value)
    {
      Node *temp = head;
      head = head->next;
      delete temp;
      return;
    }

    Node *current = head;
    Node *prev = nullptr;

    while (current != nullptr && current->data != value)
    {
      prev = current;
      current = current->next;
    }

    if (current == nullptr)
    {
      cout << "Value not found. Deletion failed." << endl;
      return;
    }

    prev->next = current->next;
    delete current;
  }

  bool search(int value)
  {
    Node *current = head;

    while (current != nullptr)
    {
      if (current->data == value)
      {
        return true;
      }
      current = current->next;
    }

    return false;
  }

  void display()
  {
    Node *current = head;

    cout << "Linked List: ";
    while (current != nullptr)
    {
      cout << current->data << " ";
      current = current->next;
    }
    cout << endl;
  }
};

int main()
{
  LinkedList linkedList;

  linkedList.insertAtBeginning(5);
  linkedList.insertAtBeginning(10);
  linkedList.insertAtEnd(15);
  linkedList.insertAtEnd(20);
  linkedList.display();

  linkedList.deleteNode(10);
  linkedList.display();

  cout << "Search 15: " << (linkedList.search(15) ? "Found" : "Not Found") << endl;
  cout << "Search 25: " << (linkedList.search(25) ? "Found" : "Not Found") << endl;

  return 0;
}

/**
 * @brief Singly linked list explanation
 * 
 * In this program, the Node class represents a node of the linked list. 
 * Each node has a data value and a pointer to the next node. 
 * The LinkedList class implements the singly linked list data structure with operations like 
 * insertAtBeginning for inserting a node at the beginning, 
 * insertAtEnd for inserting a node at the end, 
 * deleteNode for deleting a node with a specific value, 
 * search for searching a value in the linked list, and display for printing the linked list.
 * 
 * In the example given, the program demonstrates the usage of the linked list by 
 * inserting nodes at the 
 * beginning and 
 * the end, 
 * deleting a node, 
 * searching for values, and 
 * displaying the linked list after each operation.
 *
 */
