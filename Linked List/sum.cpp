/*#include<iostream>

using namespace std;



/*class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        next = nullptr;
    }
    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
    ~Node()
    {
        delete next;
    }
};

void insertlast(Node *&head, int x)
{

    Node *t = new Node(x);
    t->next = nullptr;
    if (head == nullptr)
    {
        head = t;
    }
    else
    {
        Node *last = head;
        while (last->next != nullptr)
        {
            last = last->next;
        }
        last->next = t;
        // last = t;
    }
}
int sum(Node *head){
    Node *temp=head;
    if (temp==nullptr)
    {
        return 0;
    }
    else{
        int sum=0;
       while (temp!=nullptr)
       {
           sum+=temp->data;
           temp= temp->next;

       }
        return sum;
    }
    
}
int main() {
    
    Node *first=nullptr;
    for (int i = 1; i <= 7; i++)
    {
        insertlast(first, i * 2);
    }
    cout<<"The total sum is: "<<sum(first);
    cout << endl ;
    return 0;
}*/


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
