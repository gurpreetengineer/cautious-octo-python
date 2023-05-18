#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>> maxHeap;
    
    // Insert elements into the max heap
    for (int num : nums) {
        maxHeap.push(num);
    }
    
    // Extract the kth largest element
    while (k > 1) {
        maxHeap.pop();
        k--;
    }
    
    return maxHeap.top();
}

int main() {
    vector<int> nums = {3, 1, 4, 2, 5, 6};
    int k = 3;
    
    int kthLargest = findKthLargest(nums, k);
    
    cout << "The " << k << "th largest element is: " << kthLargest << endl;
    
    return 0;
}

/**
 * @brief kth largest element in an array using a max heap explanation
 * 
 * In this program, we use a max heap (priority queue) to find the kth largest element in the given array.
 * We insert all the elements into the max heap, which automatically arranges them in descending order.
 * Then, we repeatedly remove the top element from the max heap until we reach the kth largest element.
 * The findKthLargest function takes an input array nums and an integer k as parameters.
 * It initializes a max heap using a priority_queue container.
 * The elements of nums are inserted into the max heap using the default comparison function, which arranges them in descending order.
 * 
 * Next, we perform k-1 iterations of removing the top element from the max heap using the pop function.
 * After these iterations, the max heap will contain the kth largest element at the top.
 * We retrieve this element using the top function and return it as the result.
 * 
 * In the main function, we provide a sample input array nums and the value of k.
 * We call the findKthLargest function with these inputs and print the result, which represents the kth largest element in the array.
 * 
 * Note that the time complexity of this program is O(n log n), where n is the size of the input array.
 * The max heap construction takes O(n log n) time, and the extraction of the kth largest element takes O(k log n) time.
 * 
 */
