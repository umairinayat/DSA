#include <iostream>

#include <cstring>
#include <string>
using namespace std;
template <class T>
class Stack
{
private:
    int top;
    T *arr;
    int size;

public:
    Stack(int size)
    {
        this->size = size;
        arr = new T[size];
        top = -1;
    }
    void push(T x)
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
    bool empty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }
    T pop()
    {
        T x = -1;
        if (!empty())
        {

            x = arr[top];
            top--;
        }

        return x;
    }
    T peek()
    {
        T x = -1;
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

int isBalance(char *exp)
{
    Stack<char> st(strlen(exp));
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            st.push(exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (st.empty())
            {
                return false;
            }
            char top = st.pop();
            if ((exp[i] == ')' && top != '(') ||
                (exp[i] == '}' && top != '{') ||
                (exp[i] == ']' && top != '['))
            {
                return false;
            }
        }
    }
    return st.empty();
}

int main()
{
    char expression[] = "{[()]}";
    if (isBalance(expression))
    {
        cout << "The parentheses are balanced." << endl;
    }
    else
    {
        cout << "The parentheses are not balanced." << endl;
    }

    cout << endl;
    return 0;
}

