/*
DSA lab 11

Max heap 

*/



#include <iostream>
using namespace std;

class heap
{
    int* arr;
    int size;
    int capacity;

public:
    heap(int* inputArr, int inputSize)
    {
        size = inputSize;
        capacity = size;
        arr = new int[capacity];

        // Copy the input array elements to the heap array
        for (int i = 0; i < size; ++i)
        {
            arr[i] = inputArr[i];
        }

        buildheap(); // Build the max heap
    }

    ~heap()
    {
        delete[] arr;
    }

    void insert(int val)
    {
        if (size == capacity)
        {
            // If the array is full, double its capacity
            capacity *= 2;
            int* newArr = new int[capacity];
            for (int i = 0; i < size; ++i)
            {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
        }

        // Insert at the end
        arr[size] = val;
        int child = size;
        int parent = (child - 1) / 2;
        while (child > 0 && arr[child] > arr[parent])
        {
            swap(arr[child], arr[parent]);
            child = parent;
            parent = (child - 1) / 2;
        }
        size++;
    }

    void delete_Frommaxheap()
    {
        if (size == 0)
        {
            cout << "Nothing to delete" << endl;
            return;
        }
        if (size == 1)
        {
            size--;
            return;
        }
        arr[0] = arr[size - 1];
        size--;

        int i = 0;
        while (i < size)
        {
            int leftindex = 2 * i + 1;
            int rightindex = 2 * i + 2;
            int maxChildIndex = i;
            if (leftindex < size && arr[leftindex] > arr[maxChildIndex])
            {
                maxChildIndex = leftindex;
            }

            if (rightindex < size && arr[rightindex] > arr[maxChildIndex])
            {
                maxChildIndex = rightindex;
            }

            if (maxChildIndex != i)
            {
                swap(arr[i], arr[maxChildIndex]);
                i = maxChildIndex;
            }
            else
            {
                break;
            }
        }
    }

    void heapify(int i)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && arr[left] > arr[largest])
            largest = left;

        if (right < size && arr[right] > arr[largest])
            largest = right;

        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            heapify(largest);
        }
    }

    void buildheap()
    {
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            heapify(i);
        }
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{
   
    int arr[] = { 5, 12, 34, 51, 90, 14, 49, 67, 72, 8 };
    int n = 9;

    // Create max heap from the array
    heap maxHeap(arr, n);

    cout << "Max - Heap:\n";
    maxHeap.display();
    cout << endl;
    cout << "After Delecting the max:" << endl;
    maxHeap.delete_Frommaxheap();

    maxHeap.display();
    maxHeap.insert(96);

    cout << "\nAfter Inseting\n";
    maxHeap.display();



    return 0;
}


