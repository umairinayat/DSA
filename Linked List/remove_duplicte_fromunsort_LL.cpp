/*Removing Dupliacte from unsorted Linkedlist
Step 1 : Create Linkedlist
Step 2 : Convert sorted linkedlist
Step 3 : Remove duplicate 

*/

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
        Node *last, *temp;
        head = new Node(arr[0]);
        last = head;
        for (int i = 1; i < n; i++)
        {
            temp = new Node(arr[i]);
            last->next = temp;
            last = temp;
        }
    }
    void sortedlist() // insertion sort
    {
        Node *first = head, *index = NULL;
        if (first == nullptr)
        {

            return;
        }
        else
        {
            while (first != nullptr)
            {
                index = first->next;
                while (index != nullptr)
                {

                    if (first->data > index->data)
                    {
                        int temp = first->data;
                        first->data = index->data;
                        index->data = temp;
                    }
                    index = index->next;
                }
                first = first->next;
            }
        }
    }
    void removeduplicate()
    {
        if (head == nullptr)
        {
            return;
        }
        else
        {
            Node *first = head;
            Node *q = first->next;
            while (q != nullptr)
            {
                if (first->data != q->data)
                {
                    first = q;
                    q = q->next;
                }
                else
                {
                    first->next = q->next;
                    free (q);
                    q = first->next;
                }
            }
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
    ~linkedlist()
    {
        Node *temp = head;

        while (temp)
        {
            delete temp;
            temp->next;
        }
    }
};

int main()
{
    linkedlist l1;
    int arr[6] = {4, 6, 8, 6, 6, 1};
    l1.create(arr, 6);
    l1.display();
    l1.sortedlist();
    l1.display();
    l1.removeduplicate();
    l1.display();
    cout << endl;
    return 0;
}