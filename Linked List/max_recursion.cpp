#include <iostream>
#include <climits>
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
    ~Node()
    {
        delete next;
    }
};

class Linkedlist
{
private:
    Node *first;

public:
    Linkedlist()
    {
        first = NULL;
    }

    void input(int arr[], int n)
    {
        Node *temp, *last;
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
    int recMaximun(Node *f)
    {
        int m = 0;
        if (f == 0)
        {
            return INT_MIN;
        }
        else
        {
            m = recMaximun(f->next);
            if (m > f->data)
            {
                return m;
            }
            else
            {
                return f->data;
            }
        }
    }
    int RecMaximun() // calling funtion
    {
        return recMaximun(first);
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
    int arr[8] = {41, 53, 72, 83, 34, 66, 45};

    Linkedlist l1;
    l1.input(arr, 8);
    
    cout << "The Maximun in linked list is " << l1.RecMaximun(); // Call the recMaximun function to find the maximum value
    cout << endl;
    return 0;
}