#include <iostream>

using namespace std;

const int MAX_SIZE = 100; // Maximum size of the heap

// Function to maintain the max-heap property by bubbling down
void heapifyDown(int heap[], int heapSize, int index)
{
    while (true)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < heapSize && heap[left] > heap[largest])
        {
            largest = left;
        }
        if (right < heapSize && heap[right] > heap[largest])
        {
            largest = right;
        }
        if (largest == index)
        {
            break;
        }

        swap(heap[index], heap[largest]);
        index = largest;
    }
}

// Function to build a max-heap
void buildMaxHeap(int heap[], int heapSize)
{
    for (int i = heapSize / 2 - 1; i >= 0; i--)
    {
        heapifyDown(heap, heapSize, i);
    }
}

// Function to perform Heapsort
void heapSort(int heap[], int heapSize)
{
    buildMaxHeap(heap, heapSize);

    for (int i = heapSize - 1; i > 0; i--)
    {
        swap(heap[0], heap[i]);
        heapSize--;
        heapifyDown(heap, heapSize, 0);
    }
}

// Function to print the array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int heap[MAX_SIZE] = {50, 30, 70, 20, 40, 60, 80}; // Array to be sorted
    int heapSize = 7;                                  // Number of elements in the array

    cout << "Original array: ";
    printArray(heap, heapSize);

    heapSort(heap, heapSize);

    cout << "Sorted array: ";
    printArray(heap, heapSize);

    return 0;
}
