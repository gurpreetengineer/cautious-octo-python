#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    deque<int> deque1 = {1, 3, 5};
    deque<int> deque2 = {2, 4, 6};
    
    // Merging the two deques using the merge function from the algorithm header
    deque<int> mergedDeque;
    merge(deque1.begin(), deque1.end(), deque2.begin(), deque2.end(), back_inserter(mergedDeque));
    
    // Printing the elements of the merged deque
    for (int i : mergedDeque) {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}
