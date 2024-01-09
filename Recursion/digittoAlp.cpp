#include <iostream>

using namespace std;
void displayapl(string Arr[], int n)
{
    if (n == 0)
    {
        return;
    }
    int dig = n % 10;
    n = n / 10;
    displayapl(Arr, n);

    if (dig > 0) 
    {
        cout << Arr[dig - 1] << " ";
    }
}
int main()
{
    string Arr[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    cout << "Enter the number you want to print" << endl;
    cout << endl;
    int n;
    cin >> n;
    displayapl(Arr, n);
    cout << endl;
    return 0;
}