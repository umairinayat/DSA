
#include <iostream>
#include<string>
using namespace std;
void printala(char a);
void printtime(int t) {
	char a = 'a';
	if (t>0)
	{
		
		printala(a);
		cout << endl;
		printtime(t - 1);
	}
}
void printala(char a) {
	if (a <='z')
	{
		cout << a << ".";
		printala(a + 1);

	}
 }
int main()
{
	int ti = 10;
	printtime(ti);
	
}

