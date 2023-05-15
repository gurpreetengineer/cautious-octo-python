#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    deque<int> myDeque = {5, 3, 1, 4, 2};
    
    // Sorting the deque using the sort function from the algorithm header
    sort(myDeque.begin(), myDeque.end());
    
    // Printing the elements of the sorted deque
    for (int i : myDeque) {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}
