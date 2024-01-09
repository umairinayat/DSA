#include<iostream>

using namespace std;
 bool serach(int arr[], int size,int key){
    if(size==0){
        return false;
    }
    if(arr[0]==key){
        return true;
    }

    else{
        return serach(arr+1, size-1, key);
    }
 }
int main() {
    int arr[9]={3,5,6,7,8,54,33,23,56};
    bool found=serach(arr, 9, 2);

    if(found){
        cout<<"Element found"<<endl;
    }
    else{
        cout<<"Not found"<<endl;

    }

    cout << endl ;
    return 0;
}