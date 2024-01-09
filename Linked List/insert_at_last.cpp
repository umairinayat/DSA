#include <iostream>

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
    }
}
void rdisplay(Node *head)
{
    if (head != nullptr)
    {
        rdisplay(head->next);
        cout << head->data << "->";
    }
    cout << "NULL\n";
}
void display(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void addlast(Node *&first, int x)
{
     Node *newnode = new Node(x);
    newnode->next = nullptr;
    if (first == nullptr)
    {
       
        first=newnode;
    }
    else{
    Node *last = first;
    while (last->next != nullptr)
    {
        last = last->next;
    }
   
    last->next = newnode;
    }
}
int main()
{
    Node *first = nullptr;
    for (int i = 1; i <= 7; i++)
    {
        insertlast(first, i * 2);
    }
    
    display(first);

    addlast(first, 6);
    cout << "After adding"<<endl;
    display(first);
    cout << endl;
    return 0;
}
