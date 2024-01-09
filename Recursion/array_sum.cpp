// sum of array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int sum(int arr[], int n) {
	if (n==0)
	{
		return 0;
	}
	else
	{
		int total = arr[0] + sum(arr + 1, n - 1); //arr+1 means point to next index
		return total;
	}
}
int main()
{
	int *arr;
	int n = 8;
	arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int res = sum(arr, n);
	cout << "The total sum is " << res << endl;
	return 0;
}
