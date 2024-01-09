

#include <iostream>
using namespace std;
int sum(int n) {
	if (n==0)
	{
		return 0;
	}
	else
	{
		int rev = n % 10;
		return rev + sum(n / 10);
	}
}
int main()
{
	int no = 563459;
	cout << "The sum of number " << no << " is : " << sum(no) << endl;
	return 0;
}


