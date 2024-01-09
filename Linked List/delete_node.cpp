#include <iostream>

using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        next = NULL;
    }
};
class Linkedlist
{
private:
    Node *first;

public:
    Linkedlist()
    {
        first = nullptr;
    }

    void input(int arr[], int n)
    {
        Node *last, *temp;
        first = new Node;
        first->data = arr[0];
        first->next = NULL;
        last = first;

        for (int i = 1; i < n; i++)
        {
            temp = new Node;
            temp->data = arr[i];
            temp->next = NULL;
            last->next = temp;
            last = temp;
        }
    }

    void deletenode(int pos)
    {
        Node *p, *q = nullptr;
        p = first;
        int x = -1, i = 0;
        if (pos == 1)
        {
            x = first->data; // storing data for deleted element
            p = first;
            first = first->next;
            delete p;
        }
        else
        { // at any position
            p = first;
            q = NULL;
            for (int i = 0; i < pos - 1; i++)
            {
                q = p;
                p = p->next;
            }

            if (p)
            {

                q->next = p->next;
                x = p->data;
                delete p;
            }
        }
    }

    void display()
    {
        Node *temp = first;
        while (temp != nullptr)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    ~Linkedlist()
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
    int A[7] = {9, 5, 7, 2, 6, 7, 3};
    int n = 7;
    Linkedlist l1;
    l1.input(A, n);

    cout << "Before Deleting " << endl;
    l1.display();
    cout << endl;

    l1.deletenode(2);

    cout << "After deleting node" << endl;
    l1.display();
    cout << endl;
    return 0;
}