#include<iostream>

using namespace std;


int getsum(int *arr, int size){
    if(size ==0){
        return 0;
    }
    if(size ==1){
        return arr[ 0];
    }

    return arr[0]+ getsum(arr+1, size-1);
}
int main() {
    int arr[9]={3,55,6,7,4,2,4,5,3};
    int sum = getsum(arr, 9);
    cout<<"The total sum is "<<endl<<endl;

    cout<<sum;

    cout << endl ;
    return 0;
}