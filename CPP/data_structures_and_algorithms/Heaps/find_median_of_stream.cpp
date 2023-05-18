#include <iostream>
#include <queue>
#include <vector>

using namespace std;

double findMedian(vector<int>& nums) {
    priority_queue<int> maxHeap;  // Stores the lower half of the numbers
    priority_queue<int, vector<int>, greater<int>> minHeap;  // Stores the upper half of the numbers
    
    for (int num : nums) {
        if (maxHeap.empty() || num < maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }
        
        // Rebalance the heaps if necessary
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    // Calculate the median
    if (maxHeap.size() == minHeap.size()) {
        return (maxHeap.top() + minHeap.top()) / 2.0;
    } else {
        return maxHeap.top();
    }
}

int main() {
    vector<int> stream = {1, 4, 2, 6, 8, 3, 7, 5};
    
    double median = findMedian(stream);
    
    cout << "Median of the stream: " << median << endl;
    
    return 0;
}

/**
 * @brief Find median of stream using heaps explanation
 * C++ program that calculates the median of a stream of numbers using two heaps: 
 *   * one max heap for the lower half and 
 *   * one min heap for the upper half.
 * 
 * In this program, the findMedian function takes a vector of integers representing the stream of numbers and calculates the median. 
 * It uses two heaps: a max heap to store the lower half of the numbers and a min heap to store the upper half of the numbers.
 * 
 * As we iterate through the numbers in the stream, we insert them into the appropriate heap based on their values. 
 * We ensure that the size difference between the two heaps is at most 1 to maintain balance.
 * 
 * After processing all the numbers, we calculate the median based on the sizes of the heaps. 
 * If the sizes are equal, we take the average of the top elements of both heaps. 
 * Otherwise, we take the top element of the max heap as the median.
 * 
 * In the example given, the program calculates the median of the stream [1, 4, 2, 6, 8, 3, 7, 5] and prints the result.
 * 
 */
