// #include <iostream>

// using namespace std;
// class Node
// {

// public:
//     int data;
//     Node *next;
//     Node(int data)
//     {
//         this->data = data;
//     }
//     Node()
//     {
//         next = nullptr;
//     }
//     ~Node()
//     {
//         delete next;
//     }
// };

// // class Linkedlist
// // {
// // private:
// //     Node *head;

// // public:
// //     Linkedlist()
// //     {
// //         head = nullptr;
// //     }

// //     void create(int arr[], int n)
// //     {
// //         Node *last, *temp;
// //         head = new Node(arr[0]);
// //         head->next = nullptr;
// //         last = head;
// //         for (int i = 1; i < n; i++)
// //         {
// //             temp = new Node(arr[i]);
// //             temp->next = nullptr;
// //             last->next = temp;
// //             last = temp;
// //         }
// //     }

// //     ~Linkedlist()
// //     {
// //         Node *temp;
// //         while (head)
// //         {
// //             head = head->next;
// //             delete temp;
// //             temp = head;
// //         }
// //     }
// //     void display(){
// //         Node * temp=head;
// //         while(temp){
// //             cout<<temp->data<<"->";
// //             temp= temp->next;
// //         }
// //     }
// // };
// void create(Node *&head, int arr[], int n)
// {
//     Node *last, *temp;
//     head = new Node(arr[0]);
//     head->next = nullptr;
//     last = head;
//     for (int i = 1; i < n; i++)
//     {
//         temp = new Node(arr[i]);
//         temp->next = nullptr;
//         last->next = temp;
//         last = temp;
//     }
// }
// void display(Node *head)
// {
//     Node *temp = head;
//     while (temp)
//     {
//         cout << temp->data << "->";
//         temp = temp->next;
//     }
// }
// Node *Merge(Node *L1, Node *L2)
// {
//     Node *third, *last;
//     while (L1 != nullptr && L2 != nullptr)
//     {
//         if (L1->data > L2->data)
//         {
//             third = L1;
//             last = L1;
//             L1 = L1->next;
//             last->next = nullptr;
//         }
//         else
//         {
//             third = L2;
//             last = L2;
//             L2 = L2->next;
//             last->next = nullptr;
//         }
//     }
//     if (L1 != nullptr)
//     {
//         last->next = L1;
//     }
//     else
//     {
//         last->next = L2;
//     }
//     return third;
// }

// int main()
// {
//     Node * head=nullptr;
//     Node * head2=nullptr;
//     int arr[5] = {3, 5, 7, 9, 10};
//     int arr1[6] = {2, 4, 6, 8, 12};
//     create(head,arr, 5);
//     create(head2,arr1, 6);
//     Node *mergedList = Merge(head, head2);

//     display(mergedList);
//     cout << endl;
//     return 0;
// }

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
        this->next = nullptr;
    }
};

void display(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL";
}

void create(Node *&head, int A[], int n)
{
    int i;
    Node *t, *last;
    head = new Node(A[0]);
    last = head;
    for (i = 1; i < n; i++)
    {
        t = new Node(A[i]);
        last->next = t;
        last = t;
    }
}

void Merge(Node *p, Node *q, Node *&third)
{
    Node *last, *start;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = nullptr;
    }
    else
    {
        third = last = q;
        q = q->next;
        third->next = nullptr;
    }

    while (p != nullptr && q != nullptr)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = nullptr;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = nullptr;
        }
    }

    if (p)
        last->next = p;
    if (q)
        last->next = q;
}

int main()
{
    Node *first = nullptr;
    Node *second = nullptr;
    Node *third = nullptr;

    int A[] = {10, 20, 40, 50, 60};
    int B[] = {15, 18, 25, 30, 55};

    create(first, A, 5);
    create(second, B, 5);
    Merge(first, second, third);
    display(third);

    return 0;
}
