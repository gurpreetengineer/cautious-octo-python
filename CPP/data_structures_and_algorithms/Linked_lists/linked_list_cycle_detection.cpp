#include <iostream>

using namespace std;

// Definition of a linked list node
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int value) : val(value), next(nullptr) {}
};

bool hasCycle(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}

ListNode* detectCycle(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr;
    }

    ListNode* slow = head;
    ListNode* fast = head;
    bool hasCycle = false;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            hasCycle = true;
            break;
        }
    }

    if (!hasCycle) {
        return nullptr;
    }

    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

int main() {
    // Create a linked list with a cycle
    ListNode* head = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node2;  // Creates a cycle: 5 -> 2

    // Check if the linked list has a cycle
    bool cycleExists = hasCycle(head);
    cout << "Cycle exists: " << (cycleExists ? "Yes" : "No") << endl;

    // Find the starting point of the cycle
    ListNode* cycleStart = detectCycle(head);
    if (cycleStart != nullptr) {
        cout << "Cycle starts at node with value: " << cycleStart->val << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    // Clean up the memory
    delete head;
    delete node2;
    delete node3;
    delete node4;
    delete node5;

    return 0;
}

/**
 * @brief Linked list cycle detection explanation
 * 
 * In this program, we define a ListNode struct to represent a node in the linked list. 
 * The hasCycle function uses the Floyd's cycle detection algorithm with two pointers, 
 * a slow pointer and a fast pointer, to determine if the linked list contains a cycle. 
 * The detectCycle function extends the hasCycle logic to find the starting point of the cycle if one exists.
 * 
 * In the example given, we create a linked list with a cycle between nodes 5 and 2. 
 * The program checks if the linked list has a cycle and, if so, finds the starting point of the cycle. 
 * Finally, the program outputs whether a cycle exists and the value of the node where the cycle starts.
 * 
 * Remember to properly deallocate the memory used by the linked list to avoid memory leaks.
 * 
 */
