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
class linkedlis
{
private:
    Node *head;

public:
    linkedlis()
    {
        head = nullptr;
    }
    void create(int arr[], int n)
    {
        Node *temp, *last;
        head = new Node;
        head->data = arr[0];
        head->next = nullptr;
        last = head;

        for (int i = 1; i < n; i++)
        {
            temp = new Node;
            temp->data = arr[i];
            temp->next = nullptr;
            last->next = temp;
            last = temp;
        }
    }

    void insertinsorted(int x)
    {
        Node *p, *q = nullptr;
        Node *temp = new Node(x);

        p = head;

        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == head)
        {
            temp->next = head;
            head = temp;
        }
        else
        {
            temp->next = q->next;
            q->next = temp;
        }
    }

    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    ~linkedlis()
    { // for deleting linkedlist
        Node *p = head;
        while (head)
        {
            head = head->next;
            delete p;
            p = head;
        }
    }
};

int main()
{
    int arr[8] = {3, 5, 6, 7, 8, 9, 10, 14};
    linkedlis l1;
    l1.create(arr, 8);
    l1.display();

    cout << "After inserting" << endl;
    l1.insertinsorted(20);
    l1.display();
    cout << endl;
    return 0;
}