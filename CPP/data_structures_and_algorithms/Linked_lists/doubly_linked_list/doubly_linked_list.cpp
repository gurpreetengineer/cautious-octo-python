#include <iostream>

using namespace std;

class Node
{
public:
  int data;
  Node *prev;
  Node *next;

  Node(int value)
  {
    data = value;
    prev = nullptr;
    next = nullptr;
  }
};

class DoublyLinkedList
{
private:
  Node *head;
  Node *tail;

public:
  DoublyLinkedList()
  {
    head = nullptr;
    tail = nullptr;
  }

  void insertAtBeginning(int value)
  {
    Node *newNode = new Node(value);

    if (head == nullptr)
    {
      head = newNode;
      tail = newNode;
    }
    else
    {
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
    }
  }

  void insertAtEnd(int value)
  {
    Node *newNode = new Node(value);

    if (head == nullptr)
    {
      head = newNode;
      tail = newNode;
    }
    else
    {
      newNode->prev = tail;
      tail->next = newNode;
      tail = newNode;
    }
  }

  void deleteNode(int value)
  {
    Node *current = head;

    while (current != nullptr)
    {
      if (current->data == value)
      {
        if (current == head)
        {
          head = current->next;
          if (head != nullptr)
          {
            head->prev = nullptr;
          }
        }
        else if (current == tail)
        {
          tail = current->prev;
          if (tail != nullptr)
          {
            tail->next = nullptr;
          }
        }
        else
        {
          current->prev->next = current->next;
          current->next->prev = current->prev;
        }

        delete current;
        return;
      }

      current = current->next;
    }

    cout << "Node with value " << value << " not found in the linked list." << endl;
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

    if (current == nullptr)
    {
      cout << "Linked list is empty." << endl;
      return;
    }

    cout << "Linked list: ";
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
  DoublyLinkedList dll;

  dll.insertAtBeginning(5);
  dll.insertAtBeginning(3);
  dll.insertAtEnd(7);
  dll.insertAtEnd(9);
  dll.display();

  dll.deleteNode(3);
  dll.deleteNode(10);
  dll.display();

  cout << "Search 7: " << (dll.search(7) ? "Found" : "Not Found") << endl;
  cout << "Search 10: " << (dll.search(10) ? "Found" : "Not Found") << endl;

  return 0;
}

/**
 * @brief doubly linked list explanation
 *
 * In this program, the Node class represents a node in the doubly linked list,
 * with a prev pointer pointing to the previous node and a next pointer pointing to the next node.
 * The DoublyLinkedList class encapsulates the operations on the linked list,
 * including inserting nodes at the beginning and end, deleting nodes, searching for a value, and displaying the linked list.
 *
 * The program demonstrates the usage of the doubly linked list by
 * performing various operations such as
 * inserting nodes at the beginning and end,
 * deleting nodes,
 * searching for values, and
 * displaying the linked list after each operation.
 *
 * Note that the program handles cases where the linked list is empty,
 * deleting the head or tail node, and
 * searching for a value that is not present in the linked list.
 *
 */
