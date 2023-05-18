#include <iostream>
#include <queue>

using namespace std;

int main() {
    // Create a priority queue (max heap) of integers
    priority_queue<int> pq;

    // Insert elements into the priority queue
    pq.push(10);
    pq.push(30);
    pq.push(50);
    pq.push(20);
    pq.push(40);

    // Print the top element (maximum)
    cout << "Top element: " << pq.top() << endl;

    // Pop the top element
    pq.pop();

    // Print the top element again
    cout << "Top element after pop: " << pq.top() << endl;

    // Check if the priority queue is empty
    if (pq.empty()) {
        cout << "Priority queue is empty" << endl;
    } else {
        cout << "Priority queue is not empty" << endl;
    }

    // Get the size of the priority queue
    cout << "Size of priority queue: " << pq.size() << endl;

    // Print all elements in the priority queue
    cout << "Elements in the priority queue: ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    return 0;
}

/**
 * @brief Priority queue using heaps explanation
 * 
 * In this program, the priority_queue container from the Standard Template Library (STL) 
 * is used to create a priority queue based on a max heap. 
 * Elements are inserted into the priority queue using the push function, and 
 * the top (maximum) element is accessed using the top function. 
 * The top element can be removed using the pop function, and 
 * the empty function is used to check if the priority queue is empty. 
 * The size function returns the number of elements in the priority queue.
 * 
 * In the program, elements are inserted into the priority queue, and 
 * the top element is printed. After popping the top element, the new top element is printed. 
 * The program then checks if the priority queue is empty and prints its size. 
 * Finally, all elements are printed by repeatedly popping the top element until the priority queue becomes empty.
 * 
 */
