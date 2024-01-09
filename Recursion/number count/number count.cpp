
#include <iostream>
using namespace std;
int count(int n) {
	if (n==0)
	{
		return 0;

	}
	else
	{
		return count(n / 10) + 1;
	}
}
int main()
{
	int n;
	cout << "Enter the number " << endl;
	cin >> n;
	cout << "The total count is " << count(n) << endl;
	return 0;
}

