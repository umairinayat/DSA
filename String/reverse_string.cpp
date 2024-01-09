#include<iostream>

using namespace std;

int main() {
    string a="python";
    char b[7];
    int i=0;
    for ( i = 0; a[i] !='\0'; i++)
    {
        
    }
    cout<<i<<endl;
    i= i-1 ;
    for (int j = 0 ; i >=0; i--, j++)
    {
       b[j]=a[i];
        
    }
    cout<<b;

    cout << endl ;
    return 0;
}