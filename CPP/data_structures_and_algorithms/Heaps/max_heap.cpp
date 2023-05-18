#include <iostream>
#include <vector>

using namespace std;

class MaxHeap
{
private:
  vector<int> heap;

  void heapifyUp(int index)
  {
    while (index > 0 && heap[index] > heap[parent(index)])
    {
      swap(heap[index], heap[parent(index)]);
      index = parent(index);
    }
  }

  void heapifyDown(int index)
  {
    int maxIndex = index;
    int left = leftChild(index);
    int right = rightChild(index);

    if (left < heap.size() && heap[left] > heap[maxIndex])
    {
      maxIndex = left;
    }

    if (right < heap.size() && heap[right] > heap[maxIndex])
    {
      maxIndex = right;
    }

    if (maxIndex != index)
    {
      swap(heap[index], heap[maxIndex]);
      heapifyDown(maxIndex);
    }
  }

public:
  int parent(int index)
  {
    return (index - 1) / 2;
  }

  int leftChild(int index)
  {
    return (2 * index) + 1;
  }

  int rightChild(int index)
  {
    return (2 * index) + 2;
  }

  void insert(int value)
  {
    heap.push_back(value);
    heapifyUp(heap.size() - 1);
  }

  int extractMax()
  {
    if (heap.empty())
    {
      cout << "Heap is empty." << endl;
      return -1;
    }

    int maxElement = heap[0];
    swap(heap[0], heap[heap.size() - 1]);
    heap.pop_back();
    heapifyDown(0);

    return maxElement;
  }

  int getMax()
  {
    if (heap.empty())
    {
      cout << "Heap is empty." << endl;
      return -1;
    }

    return heap[0];
  }

  void display()
  {
    cout << "Max Heap: ";
    for (int i = 0; i < heap.size(); i++)
    {
      cout << heap[i] << " ";
    }
    cout << endl;
  }
};

int main()
{
  MaxHeap maxHeap;

  maxHeap.insert(10);
  maxHeap.insert(20);
  maxHeap.insert(15);
  maxHeap.insert(30);
  maxHeap.insert(25);

  maxHeap.display();

  cout << "Max Element: " << maxHeap.getMax() << endl;

  cout << "Extracted Max Element: " << maxHeap.extractMax() << endl;

  maxHeap.display();

  return 0;
}

/**
 * @brief Max heap explanation
 *
 * In this program, the MaxHeap class represents a max heap data structure.
 * The heap vector is used to store the elements of the heap.
 * The heapifyUp function is used to maintain the max heap property by swapping elements upwards when a new element is inserted.
 * The heapifyDown function is used to maintain the max heap property by swapping elements downwards when an element is removed or replaced.
 * The class also provides functions like insert to insert an element into the heap,
 * extractMax to remove and return the maximum element,
 * getMax to retrieve the maximum element without removing it, and
 * display to print the elements of the max heap.
 *
 * In the main function, we create a MaxHeap object, insert elements into the heap, and
 * demonstrate the functionality of the max heap by displaying the heap, retrieving the maximum element, and
 * extracting the maximum element.
 *
 */
