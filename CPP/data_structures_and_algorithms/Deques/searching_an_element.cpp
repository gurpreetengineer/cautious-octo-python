#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    deque<int> myDeque = {1, 2, 3, 4, 5};
    
    // Finding the first occurrence of the element 3 using the find function from the algorithm header
    deque<int>::iterator it = find(myDeque.begin(), myDeque.end(), 3);
    if (it != myDeque.end()) {
        cout << "Element found at index " << it - myDeque.begin() << "." << endl;
    } else {
        cout << "Element not found." << endl;
    }
    
    return 0;
}
