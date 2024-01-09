// multiple number.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int multiple(int m, int n) {
	if (n==0)
	{
		return 0;
	}
	else
	{
		return  m+multiple(m, n - 1);
	}
}
int main()
{
	int m, n;
	cin >> m >> n;
	cout << multiple(m, n) << endl;
}

