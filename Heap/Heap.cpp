#include <iostream>
using namespace std;

class Heap
{
public:
    int *arr;
    int capacity;
    int size;

    Heap(int capacity)
    {
        this->arr = new int[capacity];
        this->capacity = capacity;
        this->size = 0;
    }

    void insert(int val)
    {
        if (size == capacity)
        {
            cout << "Heap OverFlow" << endl;
            return;
        }
        size++;
        int index = size;
        arr[index] = val;
        // Take the value to its correct position
        while (index > 1)
        {
            int parentIndex = index / 2;
            if (arr[index] > arr[parentIndex])
            {
                swap(arr[index], arr[parentIndex]);
                index = parentIndex;
            }
            else
            {
                break;
            }
        }
    }
    void printHeap()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
    }

    int deleteFromHeap()
    {
        int answer = arr[1];

        arr[1] = arr[size];
        size--;
        int index = 1;
        while (index < size)
        {
            int leftIndex = 2 * index;
            int rightIndex = 2 * index + 1;
            // Find out the largest element
            int largestKaIndex = index;
            if (leftIndex <= size && arr[largestKaIndex] < arr[leftIndex])
            {
                largestKaIndex = leftIndex;
            }
            if (rightIndex <= size && arr[largestKaIndex] < arr[rightIndex])
            {
                largestKaIndex = rightIndex;
            }

            if (index == largestKaIndex)
            {
                break;
            }
            else
            {
                swap(arr[index], arr[largestKaIndex]);
                index = largestKaIndex;
            }
        }
        return answer;
    }

    void heapify(int *arr, int n, int index)
    {
        int leftIndex = 2 * index;
        int rightIndex = 2 * index + 1;
        int largestKaIndex = index;
        if (leftIndex <= n && arr[leftIndex] > arr[largestKaIndex])
        {
            largestKaIndex = leftIndex;
        }
        if (rightIndex <= n && arr[rightIndex] > arr[largestKaIndex])
        {
            largestKaIndex = rightIndex;
        }
        if (index != largestKaIndex)
        {
            swap(arr[index], arr[largestKaIndex]);
            index = largestKaIndex;
            heapify(arr, n, index);
        }
    }
};

void heapify(int *arr, int n, int index)
{
    int leftIndex = 2 * index;
    int rightIndex = 2 * index + 1;
    int largestKaIndex = index;
    if (leftIndex <= n && arr[leftIndex] > arr[largestKaIndex])
    {
        largestKaIndex = leftIndex;
    }
    if (rightIndex <= n && arr[rightIndex] > arr[largestKaIndex])
    {
        largestKaIndex = rightIndex;
    }
    if (index != largestKaIndex)
    {
        swap(arr[index], arr[largestKaIndex]);
        heapify(arr, n, largestKaIndex);
    }
}

void buildHeap(int *arr, int n)
{
    for (int index = n / 2; index > 0; index--)
    {
        heapify(arr, n, index);
    }
}

int main()
{
    Heap h(20);
    // Insertion
    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(11);
    h.insert(6);
    cout << "Printing the content of heap: " << endl;
    h.printHeap();

    int ans = h.deleteFromHeap();
    cout << "Deleted element: " << ans << endl;
    cout << "Printing the content of heap after deletion: " << endl;
    h.printHeap();

    return 0;
}