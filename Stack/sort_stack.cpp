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
    void sorted(Stack &st)
    {
        if (st.empty() || st.size == 1)
        {
            return;
        }
        else
        {
            int num = st.peek();
            st.pop();
            sorted(st);
            if (num <= st.peek())
            {
                sorted(st);
            }

            st.push(num);
        }
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
    for (int i = size; i >=0; i--)
    {

        s1.push(2 * i);
    }
    s1.display();
    s1.sorted(s1);
    s1.display();
    cout << endl;
    return 0;
}