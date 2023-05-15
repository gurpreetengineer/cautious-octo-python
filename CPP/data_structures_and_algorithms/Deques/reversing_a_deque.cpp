#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    deque<int> myDeque = {1, 2, 3, 4, 5};
    
    // Reversing the deque using the reverse function from the algorithm header
    reverse(myDeque.begin(), myDeque.end());
    
    // Printing the elements of the deque
    for (int i : myDeque) {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}
