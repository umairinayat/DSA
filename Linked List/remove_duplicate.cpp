#include <iostream>

using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
    Node()
    {
        next = nullptr;
    }

    ~Node()
    {
        delete next;
    }
};

class linkedlist
{
private:
    Node *first;

public:
    linkedlist()
    {
        first = nullptr;
    }
    void create(int arr[], int n)
    {
        Node *temp, *last;
        first = new Node(arr[0]);
        first->next = nullptr;
        last = first;
        for (int i = 1; i < n; i++)
        {
            temp = new Node(arr[i]);
            temp->next = nullptr;
            last->next = temp;
            last = temp;
        }
    }
    void removeduplicate() //removing in stored array 
    {
        Node *p, *q = nullptr;
        p = first;
        q = first->next;
        while (q != nullptr)
        {
            if (p->data != q->data)
            {
                p = q;
                q = q->next;
            }
            else
            {
                p->next = q->next;
                free (q); //for free the value of q to store new value in it
                q = p->next;
            }
        }
    }
    void display()
    {
        Node *p = first;
        while (p)
        {
            cout << p->data << "->";
            p = p->next;
        }
        cout << "NULL" << endl;
    }
    ~linkedlist()
    {
        Node *p = first;
        while (first)
        {
            first = first->next;
            delete p;
            p = first;
        }
    }
};

int main()
{
    int arr[10] = {4, 5, 6, 7, 7, 8, 9, 9,9};
    linkedlist l1;
    l1.create(arr, 10);
    l1.display();
    cout << "After removing " << endl;
    l1.removeduplicate();

    l1.display();
    cout << endl;
    return 0;
}