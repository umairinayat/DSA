#include <iostream>

using namespace std;
class Queue
{
private:
    int fornt;
    int rear;
    int *Q;
    int size;

public:
    Queue(int size)
    {
        this->size = size;
        rear = -1;
        fornt = -1;
        Q = new int[size];
    }
    bool isempty()
    {
        if (fornt == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isfull()
    {
        if (rear == size - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void enqueue(int x)
    {
        if (!isfull())
        {
            rear++;
            Q[rear] = x;
        }
        else
        {
            cout << "Queue is Full " << endl;
        }
    }
    void display()
    {
        for (int i = fornt + 1; i <= rear; i++)
        {
            cout << Q[i] << " ";
        }
        cout << endl;
    }
    int dequeue()
    {
        int x = -1;
        if (!isempty())
        {
            fornt++;
            x = Q[fornt];
        }
        else
        {
            cout << "Queue is empty" << endl;
        }
        return x;
    }
};

int main()
{
    int A[5] = {3, 5, 7, 8, 9};

    Queue q(10);
    for (int i = 0; i < 5; i++)
    {
        q.enqueue(A[i]);
    }
    q.display();
    cout << endl;
    cout << q.dequeue();
    cout << endl;
    q.dequeue();
    q.enqueue(9);
    q.enqueue(21);
    cout << endl;
    q.display();
    return 0;
}