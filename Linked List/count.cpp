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

Node *takeinput()
{
    cout<<"Enter element: ";
    int data;
    cin >> data;
    Node *head = nullptr;
    Node *tail = nullptr;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cout<<"Enter element: ";
        cin >> data;
    }
    return head;
}

int countlist(Node *first)
{
    int count = 0;
    if (first == nullptr)
    {
        return 0;
    }
    else
    {

        while (first)
        {
            count++;
            first = first->next;
        }
        return count;
    }
}

int main()
{
    Node *head = nullptr;
    head = takeinput();
    cout << "The total count in linkedlist is : " << countlist(head);

    return 0;
}
