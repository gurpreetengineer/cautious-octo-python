#include <iostream>
#include <vector>

using namespace std;

class MinHeap
{
private:
  vector<int> heap;

  int getParent(int i)
  {
    return (i - 1) / 2;
  }

  int getLeftChild(int i)
  {
    return 2 * i + 1;
  }

  int getRightChild(int i)
  {
    return 2 * i + 2;
  }

  void heapifyUp(int i)
  {
    while (i > 0 && heap[i] < heap[getParent(i)])
    {
      swap(heap[i], heap[getParent(i)]);
      i = getParent(i);
    }
  }

  void heapifyDown(int i)
  {
    int smallest = i;
    int left = getLeftChild(i);
    int right = getRightChild(i);

    if (left < heap.size() && heap[left] < heap[smallest])
    {
      smallest = left;
    }

    if (right < heap.size() && heap[right] < heap[smallest])
    {
      smallest = right;
    }

    if (smallest != i)
    {
      swap(heap[i], heap[smallest]);
      heapifyDown(smallest);
    }
  }

public:
  void insert(int key)
  {
    heap.push_back(key);
    int i = heap.size() - 1;
    heapifyUp(i);
  }

  void removeMin()
  {
    if (heap.empty())
    {
      cout << "Heap is empty. Cannot remove min element." << endl;
      return;
    }

    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);
  }

  int getMin()
  {
    if (heap.empty())
    {
      cout << "Heap is empty. No minimum element." << endl;
      return -1;
    }

    return heap[0];
  }

  void display()
  {
    cout << "Min Heap: ";
    for (int i = 0; i < heap.size(); i++)
    {
      cout << heap[i] << " ";
    }
    cout << endl;
  }
};

int main()
{
  MinHeap minHeap;

  minHeap.insert(5);
  minHeap.insert(3);
  minHeap.insert(8);
  minHeap.insert(2);
  minHeap.insert(10);
  minHeap.display();

  cout << "Minimum element: " << minHeap.getMin() << endl;

  minHeap.removeMin();
  minHeap.display();

  cout << "Minimum element: " << minHeap.getMin() << endl;

  return 0;
}

/**
 * @brief Min heap explanation
 *
 * In this program, the MinHeap class represents a min heap data structure.
 * It maintains a vector heap to store the elements.
 * The class provides methods to insert elements, remove the minimum element,
 * retrieve the minimum element, and display the heap.
 * The heapify operations, heapifyUp and heapifyDown,
 * ensure that the heap property is maintained after each insertion or removal operation.
 *
 * The program demonstrates the usage of the MinHeap class by inserting some elements,
 * removing the minimum element, and retrieving the minimum element.
 * The display function is used to print the current state of the min heap after each operation.
 *
 * Note that the minimum element is always at the root of the min heap, and
 * removing the minimum element (i.e., the root) results in restructuring the heap to maintain the heap property.
 *
 */
