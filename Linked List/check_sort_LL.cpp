#include <iostream>

using namespace std;
template <class T>
class Node
{
public:
    T data;
    Node *next;
    Node(T data)
    {
        this->data = data;
        next = nullptr;
    }
    ~Node()
    {
        while (next != nullptr)
        {
            delete next;
        }
    }
};
class linkedlist
{
private:
    Node<int> *head;

public:
    linkedlist()
    {
        head = nullptr;
    }
    void create(int arr[], int n)
    {
        Node<int> *temp, *last;
        
        head = new Node<int>(arr[0]);
        head->next=nullptr;
        last = head;
        for (int i = 1; i < n; i++)
        {
            temp = new Node<int>(arr[i]);
            last->next = temp;
            last = temp;
        }
    }
    void display(){
        Node<int> *temp=head;
     
        while (temp)
        {
           cout<<temp->data<<" ";
           temp=temp->next;
        }
        cout<<endl;
        
    }
    bool checksort(){
        if (head==nullptr)
        {
            return false;
        }
        else
        {
            Node<int> * p=head;
            int min= p->data;
            while (p!=nullptr)
            {
                if (p->data<min)
                {
                    return false;
                }
                min=p->data;
                p=p->next;
                
            }
        
        }
        return true;
        
        
    }
    ~linkedlist(){
        delete head;
    }
};



int main()
{

    int arr[7]={3,4,6,7,8,12,13};
    linkedlist l1;
    l1.create(arr, 7);
    l1.display();
    cout<<l1.checksort()<<endl;
    cout << endl;
    return 0;
}