
// Some predefined fuctions:
// Swap,Sort,Max,Min

#include <iostream>
using namespace std;
void sort(int arr[], int size)
{
    int temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if(arr[i]>arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}
int binrayserach(int arr[], int size, int key){
    int start=0,end=size-1,mid;
    while (start<=end)
    {
        mid=(start+end)/2;
        if (key==arr[mid])
        {
            return mid;
        }
        else if (key>arr[mid])
        {
            start=mid+1;
           
        }
        else{
             end=mid-1;
        }
    }
    return -1;
}

void sortt(int arr[], int size){

    int i = 0, j = size-1;

    while((i<size) && (i!=j)){
        if(arr[i]==0){
            i++;
        }
        else if(arr[i]==1){
            if(arr[j]==0){
                swap(arr[i],arr[j]);
                i++;
                j--;
            }
            else{
                j--;
            }
        }
    }

    for(int z = 0; z<size; z++){
        cout<<arr[z];
    }

}

int main(){
    
    int myarr[6] = {0,0,1,0,1,0};
    sortt(myarr,6);

}
