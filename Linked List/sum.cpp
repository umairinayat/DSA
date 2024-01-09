#include<iostream>

using namespace std;



class Node
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
}
