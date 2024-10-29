#include <iostream>

using namespace std;

const int MAX_SIZE = 100; // Maximum size of the heap

// Function to maintain the min-heap property by bubbling up
void heapifyUp(int heap[], int index)
{
    while (index > 0)
    {
        int parent = (index - 1) / 2;
        if (heap[index] >= heap[parent])
            break;
        swap(heap[index], heap[parent]);
        index = parent;
    }
}

// Function to insert an item into the heap
void INSHEAP(int heap[], int &heapSize, int ITEM)
{
    if (heapSize >= MAX_SIZE)
    {
        cout << "Heap is full. Cannot insert item." << endl;
        return;
    }

    heap[heapSize] = ITEM; // Add the new item at the end
    heapSize++;
    heapifyUp(heap, heapSize - 1); // Restore the heap property
    cout << "Item " << ITEM << " inserted into the heap." << endl;
}

// Function to print the heap
void printHeap(int heap[], int heapSize)
{
    for (int i = 0; i < heapSize; i++)
    {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main()
{
    int heap[MAX_SIZE]; // Array to store the heap
    int heapSize = 0;   // Current size of the heap

    // Inserting elements into the heap
    INSHEAP(heap, heapSize, 50);
    INSHEAP(heap, heapSize, 30);
    INSHEAP(heap, heapSize, 70);
    INSHEAP(heap, heapSize, 20);
    INSHEAP(heap, heapSize, 40);
    INSHEAP(heap, heapSize, 60);
    INSHEAP(heap, heapSize, 80);

    cout << "Heap: ";
    printHeap(heap, heapSize);

    return 0;
}
