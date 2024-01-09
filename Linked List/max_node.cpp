
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
        next = nullptr;
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
        first = nullptr;
    }
    void input(int arr[], int n) // for input creating linked list for array
    {
        Node *last, *temp;
        first = new Node;
        first->data = arr[0];
        first->next = NULL;
        last = first; // for first node

        for (int i = 1; i < n; i++) // for nexts nodes
        {
            temp = new Node;
            temp->data = arr[i];
            temp->next = NULL;
            last->next = temp;
            last = temp;
        }
    }
    int maximum(Node *p)
    {
        int max = INT_MIN;
        if (p == nullptr)
        {
            return max;
        }
        else
        {
            max = maximum(p->next);
            if (max > p->data)
            {
                return max;
            }
            else
            {
                max = p->data;
            }
        }
    }

    int sum(Node *p)
    {
        int Sum = 0;
        if (p == nullptr)
        {
            return Sum;
        }
        else
        {
            Sum = sum(p->next) + p->data;
            return Sum;
        }
    }
    int maximumrec()
    {
        return maximum(first);
    }
    int maximun()
    {
        Node *p = first;
        int m = INT_MIN; // for storing most minimum value

        while (p)
        {
            if (p->data > m)
            {
                m = p->data;
            }
            p = p->next;
        }

        return m;
    }

    ~Linkedlist() // destroing all element in Linkedlist
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
    int arr[8] = {41, 53, 72, 83, 88, 66, 45};

    Linkedlist l1;
    l1.input(arr, 8);
    cout << "The Maximun in linked list is " << l1.maximun() << endl;
    cout << "The Maximun in linked list is in rec " << l1.maximumrec() << endl;
    cout << endl;
    return 0;
}