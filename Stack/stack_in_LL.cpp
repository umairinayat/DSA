#include <iostream>

using namespace std;

// Node class represents individual elements in the stack
class Node
{
public:
    int data;
    Node *next;

    // Constructor to initialize node with given data and next pointer as nullptr
    Node(int data = 0)
    {
        this->data = data;
        next = nullptr;
    }
    ~Node(){
        
    }
};

// Stack class represents a stack data structure using linked list
class Stack
{
public:
    Node *top;

    // Constructor to initialize the top pointer as nullptr
    Stack()
    {
        top = nullptr;
    }

    // Push operation: Adds a new element to the stack
    void push(int value)
    {
        Node *newNode = new Node;
        if (newNode == nullptr)
        {
            cout << "Stack overflow!\n";
        }
        else
        {
            newNode->data = value;
            newNode->next = top;
            top = newNode;
        }
    }

    // Peek operation: Returns the top element of the stack without removing it
    int peek()
    {
        int x = -1;
        if (!isEmpty())
        {
            return top->data;
        }
        else
            return x;
    }

    // Pop operation: Removes and returns the top element from the stack
    int pop()
    {
        int x = -1;
        if (top != nullptr)
        {
            Node *temp = top;
            x = temp->data;
            top = top->next;
            delete temp;
        }
        else
        {
            cout << "Stack is empty !!!" << endl;
        }
        return x;
    }

    // Checks if the stack is empty
    bool isEmpty()
    {
        return top == nullptr;
    }

    int Top_Val(){
        if(top){
            return top->data;
        }
        else{
            return -1;
        }
    }

    void display(){
        Node * temp = top;
        while (temp)
        {
            cout<<temp->data<<" ";
            temp= temp->next;
        }
        cout<<endl;
    }

};

int main()
{
    // Create a stack object
    Stack stack;

    // Push elements onto the stack
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(8);
    stack.push(9);

    // Print the top element
    cout << "Top element of the stack: " << stack.peek() << endl;

    // Pop elements from the stack and print them
    cout << "Popped element: " << stack.pop() << endl;
    cout << "Popped element: " << stack.pop() << endl;

    // Check if the stack is empty
    if (stack.isEmpty())
    {
        cout << "Stack is empty." << endl;
    }
    else
    {
        cout << "Stack is not empty." << endl;
    }
    stack.display();
    return 0;
}
