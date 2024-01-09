#include <iostream>

using namespace std;
bool issorted(int *arr, int size)
{
    if (size == 0 || size == 1)
    {
        return true;
    }
    if (arr[0] > arr[1])
    {
        return false;
    }
    else
    {
        return issorted(arr + 1, size - 1);
    }
}
int main()
{
    int arr[7] = {3, 4, 6, 7, 8, 45, 66};
    bool sorted = issorted(arr, 7);
    if (sorted)
    {
        cout << "Array is sorted" << endl;
    }
    else
    {
        cout << "Array is not sorted" << endl;
    }
    cout << endl;
    return 0;
}