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
        Node *temp, *last;
        head = new Node(arr[0]);
        head->next = head;
        head = last;
        for (int i = 1; i < n; i++)
        {
            temp = new Node(arr[i]);
            temp->next = last->next;
            last = temp;
        }
    }
    void display()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    bool checkloop()
    {
        if (head == nullptr)
        {
            return false;
        }
        else
        {
            Node *p = head, *q = nullptr;
            q = p->next;
            while (p && q)
            {
                if (p->data == q->data)
                {
                    return true;
                }
                p = q;
                q = q->next;
            }
            return false;
        }
    }
    ~linkedlist()
    {
        delete head;
    }
};

int main()
{
    int arr[7] = {2, 3, 4, 5, 7, 8, 9};
    linkedlist l1;
    l1.create(arr, 7);
    l1.display();
    cout << l1.checkloop();
    cout << endl;
    return 0;
}