#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d = 0)
    {
        data = d;
        next = NULL;
    }
};

class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(int x)
    {
        Node *t = new Node;
        if (t == NULL)
        {
            cout << "Queue is full !!!" << endl;
        }
        else
        {
            t->data = x;
            t->next = NULL;
            if (front == NULL)
            {
                front = rear = t;
            }
            else
            {
                rear->next = t;
                rear = t;
            }
        }
    }

    int dequeue()
    {
        int x = -1;
        Node *p;
        if (front == NULL)
        {
            cout << "Queue is Empty!!!" << endl;
        }
        else
        {
            p = front;
            front = front->next;
            x = p->data;
            delete p;
        }
        return x;
    }
};

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << "Dequeued element: " << q.dequeue() << endl;
    cout << "Dequeued element: " << q.dequeue() << endl;

    return 0;
}
