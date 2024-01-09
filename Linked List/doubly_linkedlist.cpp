#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int value)
    {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};
class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }
    void pushFront(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    void pushBack(int value)
    {
        Node *newNode = new Node(value);
        if (tail == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }
    int popFront()
    {
        if (head == nullptr)
        {
            cout << "List is empty. Cannot pop element.\n";
            return -1; 
        }
        int poppedValue;
        if (head == tail)
        {
            poppedValue = head->data;
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            poppedValue = head->data;
            head = head->next;
            delete head->prev;
            head->prev = nullptr;
        }
        return poppedValue;
    }
    int popBack()
    {
        if (tail == nullptr)
        {
            cout << "List is empty. Cannot pop element.\n";
            return -1; 
        }
        int poppedValue;
        if (head == tail)
        {
            poppedValue = tail->data;
            delete tail;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            poppedValue = tail->data;
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
        }
        return poppedValue;
    }
    bool search(int value)
    {
        if (head == nullptr)
        {
            return false; // List is empty
        }
        Node *current = head;
        while (current != nullptr)
        {
            if (current->data == value)
            {
                return true; 
            }
            current = current->next;
        }
        return false; 
    }
};
int main()
{
    DoublyLinkedList myList;
    // Pushing elements 
    myList.pushFront(10);
    myList.pushBack(20);
    myList.pushFront(5);
    myList.pushBack(30);
    // Searching for a value
    int searchValue = 20;
    if (myList.search(searchValue))
    {
        cout << "Value " << searchValue << " found in the list.\n";
    }
    else
    {
        cout << "Value " << searchValue << " not found in the list.\n";
    }
    // Popping elements from the front and back
    int poppedValue = myList.popFront();
    cout << "Popped value from front: " << poppedValue << "\n";
    poppedValue = myList.popBack();
    cout << "Popped value from back: " << poppedValue << "\n";
    return 0;
}