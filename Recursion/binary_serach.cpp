#include <iostream>

using namespace std;
bool binrayserach(int arr[], int s, int e, int key)
{
    if (s > e)
    {
        return 0;
    }
    int mid = s + (e - s) / 2;
    if (arr[mid] == key)
    {
        cout << "At index " << mid << endl;
        return true;
    }
    if (arr[mid] < key)
    {
        return binrayserach(arr, mid + 1, e, key);
    }
    else
    {
        return binrayserach(arr, s, mid - 1, key);
    }
}
int main()
{

    int arr[10] = {3, 5, 6, 7, 8, 54, 33, 23, 56,89};
    bool found = binrayserach(arr, 0, 9, 89);

    if (found)
    {
        cout << "Element found" << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }

    cout << endl;
    cout << endl;
    return 0;
}