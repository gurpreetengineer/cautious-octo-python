#include <iostream>
#include <deque>

using namespace std;

int main() {
    deque<int> myDeque;
    
    // Adding elements to the back of the deque
    myDeque.push_back(10);
    myDeque.push_back(20);
    myDeque.push_back(30);
    
    // Adding elements to the front of the deque
    myDeque.push_front(5);
    myDeque.push_front(15);
    myDeque.push_front(25);
    
    // Removing elements from the front of the deque
    myDeque.pop_front();
    myDeque.pop_front();
    
    // Removing elements from the back of the deque
    myDeque.pop_back();
    myDeque.pop_back();
    
    // Printing the elements of the deque
    for (int i : myDeque) {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}
