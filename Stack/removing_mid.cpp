#include <iostream>

using namespace std;

class Stack
{
private:
    int top;
    int *arr;
    int size;

public:
    // Constructor to initialize the stack with given size
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    // Function to push an element onto the stack
    void push(int x)
    {
        if (top == size - 1)
        {
            cout << "Stack is overflow";
        }
        else
        {
            top++;
            arr[top] = x;
        }
    }

    // Function to check if the stack is empty
    bool empty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }

    // Function to pop an element from the stack
    int pop()
    {
        int x = -1;
        if (!empty())
        {
            x = arr[top];
            top--;
        }
        return x;
    }

    // Function to peek the top element of the stack
    int peek()
    {
        int x = -1;
        if (!empty())
        {
            x = arr[top];
        }
        else
        {
            cout << "Empty stack" << endl;
        }
        return x;
    }

    // Function to solve the problem as remove the mid of stack using recurison 
    void removemid(Stack &inputstack, int count, int size)
    {
        if (count == size / 2)
        {
            inputstack.pop();
            return;
        }
        else
        {
            int num = inputstack.peek();
            inputstack.pop();
            removemid(inputstack, count + 1, size);
            inputstack.push(num);
        }
    }

    // Function to display the elements of the stack
    void display()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Destructor to free the dynamically allocated memory for the stack
    ~Stack()
    {
        delete[] arr;
    }
};

int main()
{
    int size = 10;
    Stack s1(size);

    // Pushing elements into the stack
    for (int i = 1; i <= size; i++)
    {
        s1.push(2 * i);
    }

    // Display the original stack
    cout << "Original Stack: ";
    s1.display();

    // Solve the problem as described in the main function
    s1.removemid(s1, 0, size);

    // Display the modified stack
    cout << "Modified Stack: ";
    s1.display();

    return 0;
}
