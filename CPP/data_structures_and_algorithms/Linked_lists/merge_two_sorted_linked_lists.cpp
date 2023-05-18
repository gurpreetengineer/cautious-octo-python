#include <iostream>

using namespace std;

// Definition of a singly linked list node
struct ListNode
{
  int val;
  ListNode *next;

  ListNode(int value) : val(value), next(nullptr) {}
};

// Function to insert a new node at the end of a linked list
void insert(ListNode *&head, int value)
{
  ListNode *newNode = new ListNode(value);
  if (head == nullptr)
  {
    head = newNode;
  }
  else
  {
    ListNode *curr = head;
    while (curr->next != nullptr)
    {
      curr = curr->next;
    }
    curr->next = newNode;
  }
}

// Function to merge two sorted linked lists into a single sorted linked list
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
  if (l1 == nullptr)
  {
    return l2;
  }
  if (l2 == nullptr)
  {
    return l1;
  }

  ListNode *dummy = new ListNode(0);
  ListNode *tail = dummy;

  while (l1 != nullptr && l2 != nullptr)
  {
    if (l1->val <= l2->val)
    {
      tail->next = l1;
      l1 = l1->next;
    }
    else
    {
      tail->next = l2;
      l2 = l2->next;
    }
    tail = tail->next;
  }

  if (l1 != nullptr)
  {
    tail->next = l1;
  }
  if (l2 != nullptr)
  {
    tail->next = l2;
  }

  ListNode *mergedList = dummy->next;
  delete dummy;

  return mergedList;
}

// Function to display the linked list
void displayList(ListNode *head)
{
  ListNode *curr = head;
  while (curr != nullptr)
  {
    cout << curr->val << " ";
    curr = curr->next;
  }
  cout << endl;
}

int main()
{
  // Create the first sorted linked list: 1 -> 3 -> 5
  ListNode *l1 = nullptr;
  insert(l1, 1);
  insert(l1, 3);
  insert(l1, 5);

  // Create the second sorted linked list: 2 -> 4 -> 6
  ListNode *l2 = nullptr;
  insert(l2, 2);
  insert(l2, 4);
  insert(l2, 6);

  // Merge the two sorted linked lists
  ListNode *mergedList = mergeTwoLists(l1, l2);

  // Display the merged linked list
  cout << "Merged List: ";
  displayList(mergedList);

  return 0;
}

/**
 * @brief Merge 2 sorted linked list into a single sorted linked list
 *
 * In this program, the ListNode struct represents a node in the singly linked list.
 * The insert function is used to insert a new node at the end of the linked list.
 * The mergeTwoLists function takes two sorted linked lists l1 and l2 as input and merges them into a single sorted linked list.
 * It uses a dummy node and a tail pointer to build the merged list by comparing the values of the nodes in l1 and l2.
 * The displayList function is used to display the elements of the linked list.
 *
 * In the example given, we create two sorted linked lists: 1 -> 3 -> 5 and 2 -> 4 -> 6.
 * We then merge these two lists using the mergeTwoLists function,
 * resulting in a single sorted linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6.
 *
 * Finally, we display the merged list.
 *
 */
