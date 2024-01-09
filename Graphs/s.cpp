#include<iostream>
using namespace std;



int main() {
    int i =1;
    int fact =1;
    int num;
    cin>>num;
    while(i<=num){
        fact = fact *i;
        i++;
    }
    cout<<"Total fact is "<<fact ;
    cout << endl ;
    return 0;
}
