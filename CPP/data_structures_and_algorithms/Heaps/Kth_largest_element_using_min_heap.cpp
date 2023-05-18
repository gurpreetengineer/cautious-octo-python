#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int findKthLargest(vector<int> &nums, int k)
{
    // Create a min heap
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Insert the first k elements into the min heap
    for (int i = 0; i < k; i++)
    {
        minHeap.push(nums[i]);
    }

    // For the remaining elements, if the current element is larger than the root of the min heap,
    // replace the root with the current element and adjust the heap
    for (int i = k; i < nums.size(); i++)
    {
        if (nums[i] > minHeap.top())
        {
            minHeap.pop();
            minHeap.push(nums[i]);
        }
    }

    // The root of the min heap will be the kth largest element
    return minHeap.top();
}

int main()
{
    vector<int> nums = {3, 1, 6, 2, 8, 5};
    int k = 3;

    int kthLargest = findKthLargest(nums, k);

    cout << "The " << k << "th largest element is: " << kthLargest << endl;

    return 0;
}

/**
 * @brief kth largest element in an array using a min heap explanation
 *
 * In this program, we use a min heap to efficiently find the kth largest element in the given array.
 * We create a min heap using the priority_queue container from the C++ Standard Library.
 * We insert the first k elements into the min heap.
 * Then, for the remaining elements, if the current element is larger than the root of the min heap,
 * we replace the root with the current element and adjust the heap to maintain the k largest elements.
 * Finally, the root of the min heap will be the kth largest element.
 *
 * In the example given, the program finds the 3rd largest element in the array {3, 1, 6, 2, 8, 5} using the findKthLargest function.
 * The program prints the kth largest element, which is 5 in this case.
 *
 */
