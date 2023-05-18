#include <iostream>

using namespace std;

// Linked list node
class ListNode {
public:
    int val;
    ListNode* next;
    
    ListNode(int value) : val(value), next(nullptr) {}
};

// Function to find the length of a linked list
int getLinkedListLength(ListNode* head) {
    int length = 0;
    ListNode* curr = head;
    while (curr) {
        length++;
        curr = curr->next;
    }
    return length;
}

// Function to find the intersection point of two linked lists
ListNode* findIntersection(ListNode* head1, ListNode* head2) {
    int len1 = getLinkedListLength(head1);
    int len2 = getLinkedListLength(head2);
    
    ListNode* curr1 = head1;
    ListNode* curr2 = head2;
    
    // Align the pointers to the same starting position
    while (len1 > len2) {
        curr1 = curr1->next;
        len1--;
    }
    
    while (len2 > len1) {
        curr2 = curr2->next;
        len2--;
    }
    
    // Move both pointers until they meet at the intersection point
    while (curr1 != curr2) {
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    
    return curr1; // or curr2, as both pointers will be at the intersection point
}

int main() {
    // Create the first linked list: 1 -> 2 -> 3 -> 4 -> 5 -> nullptr
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);
    
    // Create the second linked list: 7 -> 8 -> 5 -> nullptr
    ListNode* head2 = new ListNode(7);
    head2->next = new ListNode(8);
    head2->next->next = head1->next->next->next; // Intersection point at node with value 5
    
    // Find the intersection point of the two linked lists
    ListNode* intersectionPoint = findIntersection(head1, head2);
    
    // Print the value of the intersection point
    if (intersectionPoint) {
        cout << "Intersection Point: " << intersectionPoint->val << endl;
    } else {
        cout << "No Intersection Point" << endl;
    }
    
    // Clean up memory
    delete head1;
    delete head2;
    
    return 0;
}

/**
 * @brief Linked lists intersection explanation
 * 
 * In this program, we have a ListNode class that represents a node in a linked list. 
 * The getLinkedListLength function is used to calculate the length of a linked list. 
 * The findIntersection function takes two linked lists as input and finds the intersection point by 
 * aligning the pointers at the same starting position and then moving both pointers until they meet at the intersection point.
 * 
 * In the example given, we create two linked lists with an intersection point at the node with a value of 5. 
 * The program then finds the intersection point and prints its value. 
 * If there is no intersection, it will indicate that there is no intersection point.
 * 
 * Remember to deallocate the memory for the linked lists after their use to avoid memory leaks.
 * 
 */
