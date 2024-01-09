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
        next = NULL;
    }
    ~Node()
    {
        delete next;
    }
};
Node *serach(Node *first, int key)
{
    while (first)
    {
        if (key == first->data)
        {
            return first;
        }
        first = first->next;
    }
    return NULL;
}

void input(Node *&first, int arr[], int n) // use *& to change its head org value and creating linked list from array
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
int main()
{

    Node *head = nullptr;
    int arr[8] = {6, 8, 3, 7, 9, 5, 0, 7};
    input(head, arr, 8);

    Node *p = serach(head, 5);
    cout << "Element found at: ";
    cout << p;
    cout << endl;
    return 0;
}