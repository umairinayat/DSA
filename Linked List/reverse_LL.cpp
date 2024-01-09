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
    Node *head;

public:
    linkedlist()
    {
        head = nullptr;
    }
    void create(int arr[], int n)
    {
        Node *last, *temp = nullptr;
        head = new Node(arr[0]);
        head->next = nullptr;
        last = head;
        for (int i = 1; i < n; i++)
        {
            temp = new Node(arr[i]);
            temp->next = nullptr;
            last->next = temp;
            last = temp;
        }
    }

    /*void recursive_reverse(Node *&q, Node *head)
    {
        if (head)
        {
            recursive_reverse(q, head->next);
            head->next->next = head;

        }
        else
        {
            this->head = q;
        }
    }

    void recursive_reverse1()
    {
        recursive_reverse(head, head);
    }*/
    void recursive_reverse(Node *prev, Node *curr)
    {
        if (curr == nullptr)
        {
            head = prev;
            return;
        }
        Node *next = curr->next;
        curr->next = prev;
        recursive_reverse(curr, next);
    }
    void recursive_reverse1()
    {
        recursive_reverse(nullptr, head);
    }
    void reverse()
    {
        Node *p = head;
        Node *q = nullptr;
        Node *r = nullptr;
        while (p != nullptr)
        {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        head = q;
    }
    void display()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{

    int arr[10] = {6, 3, 8, 9, 7, 5, 3, 10, 21, 23};
    linkedlist l1;
    l1.create(arr, 10);
    l1.display();
    cout << endl;
    cout << "After reversing" << endl;

    l1.recursive_reverse1();

    l1.display();
    cout << endl;
    return 0;
}