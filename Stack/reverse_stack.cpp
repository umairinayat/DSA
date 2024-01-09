#include <iostream>

using namespace std;
class Stack
{
private:
    int top;
    int *arr;
    int size;

public:
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int x)
    {
        if (top == size - 1)
        {
            cout << "Stack is overflow";
            return;
        }

        else
        {
            top++;
            arr[top] = x;
        }
    }
    bool empty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }
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
    void insertatbutton(Stack &inputstack, int x) // using recursion do only first step, then recursion can do remaing step
    {
        if (inputstack.empty())
        {
            inputstack.push(x);
        }
        else
        {
            int num = inputstack.peek();
            inputstack.pop();
            insertatbutton(inputstack, x);
            inputstack.push(num);
        }
    }
    void reverse(Stack &inputstack)
    {
        if (inputstack.empty())
        {
            return;
        }

        int num = inputstack.peek();
        inputstack.pop();
        reverse(inputstack);
        insertatbutton(inputstack, num);
    }
    void display()
    {
        int i;
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    ~Stack()
    {
        delete[] arr;
    }
};

int main()
{
    int size = 11;
    Stack s1(size);
    for (int i = 1; i < size; i++)
    {

        s1.push(2 * i);
    }
    s1.display();
    s1.insertatbutton(s1, 30);
    s1.display();

    s1.reverse(s1);
    s1.display();
    cout << endl;
    return 0;
}