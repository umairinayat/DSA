#include <iostream>
using namespace std;

class heap
{
public:
    int arr[100];
    int size;
    heap()
    {
        size = 0;
    }
    void insert(int val)
    {
        if (size == 0)
        { // if heap is empty then insert at 0th index
            arr[size] = val;
            size++; // increase size by 1
            return;
        } // if heap is not empty then insert at last index
        if (size == 1)
        {
            arr[size] = val;
            size++;
            return;
        }
        else
        {
            arr[size] = val;
            int child = size;             // child is the index of the element which is inserted
            int parent = (child - 1) / 2; // parent is the index of the parent of the element which is inserted
            while (arr[child] > arr[parent])
            {
                int temp = arr[child]; // swap the child and parent if child is greater than parent
                arr[child] = arr[parent];
                arr[parent] = temp;
                child = parent; // update the child and parent index
                parent = (child - 1) / 2;
            }
            size++; // increase the size by 1
        }
    }

    void delete_Frommaxheap()
    {
        if (size == 0)
        { // if heap is empty then return
            cout << "Nothing  to delete" << endl;
            return; // return 0
        }
        if (size == 1)
        { // if heap is only one element then delete it
            size--;
            return;
        }
        arr[0] = arr[size - 1]; // replace the first element with the last element
        size--;                 // decrease the size by 1

        int i = 0; // i is the index of the element which is replaced
        while (i < size)
        {
            int leftindex = 2 * i + 1;  // leftindex is the index of the left child of the element which is replaced`
            int rightindex = 2 * i + 2; // rightindex is the index of the right child of the element which is replaced
            if (leftindex < size && arr[i] < arr[leftindex])
            {                                 // if leftindex is greater than size then break
                swap(arr[i], arr[leftindex]); // swap the element with its left child if element is less than its left child
                i = leftindex;                // update the index
            }
            else if (rightindex < size && arr[i] < arr[rightindex])
            {                                  // if rightindex is greater than size then break
                swap(arr[i], arr[rightindex]); // swap the element with its right child if element is less than its right child
                i = rightindex;                // update the index
            }
            else
            {
                break;
            }
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
void heapify(int arr[], int n, int i)
{
    int largest = i;   // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

int main()
{
    heap h;
    // h.insert(50);
    // h.insert(55);
    // h.insert(53);
    // h.insert(52);
    // h.insert(54);

    // h.display();

    // h.delete_Frommaxheap();

    // cout << endl;
    // h.display();
    int arr[] = {54, 53, 55, 52, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        h.insert(arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    // h.display();

    return 0;
}
