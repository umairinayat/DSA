// #include <iostream>
// #include <cstring>
// using namespace std;

// class Stack;
// class Node
// {
// public:
//     char val;
//     Node *next;
//     Node()
//     {
//         next = nullptr;
//     }
//     Node(char val)
//     {
//         this->val = val;
//     }
//     friend class Stack;
// };
// class Stack
// {
// private:
//     Node *top;

// public:
//     Stack()
//     {
//         top = nullptr;
//     }
//     void Push(char x)
//     {
//         Node *temp = new Node(x);
//         if (temp == nullptr)
//         {
//             cout << "Stack is Full " << endl;
//         }
//         else
//         {
//             temp->next = top;
//             top = temp;
//         }
//     }
//     char pop()
//     {
//         char x = -1;
//         if (top == nullptr)
//         {
//             cout << "Stack is full\n";
//         }
//         else
//         {
//             Node *temp = top;
//             x = temp->val;
//             top = top->next;
//             delete temp;
//         }
//         return x;
//     }
//     void display()
//     {
//         Node *temp = top;
//         while (temp)
//         {
//             cout << temp->val << " ";
//             temp = temp->next;
//         }
//     }
//     char gettop()
//     {
//         char v = -1;
//         if (top)
//         {
//             return top->val;
//         }
//         else
//         {
//             return v;
//         }
//     }
//     int isempty()
//     {
//         if (top == nullptr)
//         {
//             return 0;
//         }
//         else
//         {
//             return 1;
//         }
//     }
// };

// class inFixToPostFix
// {
// private:
//     Stack stack;
//     int pre(char x)
//     {
//         if (x == '+' || x == '-')
//         {
//             return 1;
//         }
//         else if (x == '/' || x == '*')
//         {
//             return 2;
//         }
//         else
//         {
//             return 0;
//         }
//     }
//     bool isoprad(char x)
//     {
//          if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
//         {
//             return true;
//         }
//         else
//         {
//             return false;
//         }
//     }

// public:
//     char *Topost(char *infix)
//     {
//         int i = 0;
//         int j = 0;
//         int len = strlen(infix);
//         char *postfix = new char[len + 1];

//         stack.Push('#');
//         while (infix[i] != '\0')
//         {
//             if (isoprad(infix[i]))
//             {
//                 postfix[j] = infix[i];
//                 i++;
//                 j++;
//             }
//             else
//             {
//                 if (!stack.isempty() && pre(infix[i]) > pre(stack.gettop()))
//                 {
//                     stack.Push(infix[i]);
//                     i++;
//                 }
//                 else
//                 {
//                     postfix[j] = stack.pop();
//                     j++;
//                 }
//             }
//         }
//         while (!stack.isempty() == 1)
//         {
//             postfix[j] = stack.pop();
//             j++;
//         }
//         postfix[j] = '\0';
//         return postfix;
//     }
//     inFixToPostFix()
//     {
//     }
//     ~inFixToPostFix()
//     {
//     }
// };

// int main()
// {
//     char infix[] = "a+b/c";

//     inFixToPostFix convert;
//     char *postfix = convert.Topost(infix);
//     cout << postfix << endl;

//     delete[] postfix;
//     cout << endl;
//     return 0;
// }

// #include <iostream>
// #include <cstring>
// using namespace std;

// class Node
// {
// public:
//     char data;
//     Node *next;
// };

// class Stack
// {
// private:
//     Node *top;

// public:
//     Stack() { top = nullptr; }
//     void push(char x);
//     char pop();
//     void Display();
//     bool isBalanced(char *exp);
//     int pre(char x);
//     int isOperand(char x);
//     char *InToPost(char *infix);
// };

// void Stack::push(char x)
// {
//     Node *t = new Node;
//     if (t == nullptr)
//         cout << "stack is full\n";
//     else
//     {
//         t->data = x;
//         t->next = top;
//         top = t;
//     }
// }

// char Stack::pop()
// {
//     Node *t;
//     char x = -1;
//     if (top == nullptr)
//         cout << "Stack is Empty\n";
//     else
//     {
//         t = top;
//         top = top->next;
//         x = t->data;
//         delete t;
//     }
//     return x;
// }

// void Stack::Display()
// {
//     Node *p = top;
//     while (p != nullptr)
//     {
//         cout << p->data << " ";
//         p = p->next;
//     }
//     cout << endl;
// }

// bool Stack::isBalanced(char *exp)
// {
//     int i;
//     for (i = 0; exp[i] != '\0'; i++)
//     {
//         if (exp[i] == '(')
//             push(exp[i]);
//         else if (exp[i] == ')')
//         {
//             if (top == nullptr)
//                 return false;
//             pop();
//         }
//     }
//     if (top == nullptr)
//         return true;
//     else
//         return false;
// }

// int Stack::pre(char x)
// {
//     if (x == '+' || x == '-')
//         return 1;
//     else if (x == '*' || x == '/')
//         return 2;
//     return 0;
// }

// int Stack::isOperand(char x)
// {
//     if (x == '+' || x == '-' || x == '*' || x == '/')
//         return 0;
//     else
//         return 1;
// }

// char *Stack::InToPost(char *infix)
// {
//     int i = 0, j = 0;
//     char *postfix;
//     int len = strlen(infix);
//     postfix = new char[len + 2];
//     push('#');
//     while (infix[i] != '\0')
//     {
//         if (isOperand(infix[i]))
//             postfix[j++] = infix[i++];
//         else
//         {
//             if (pre(infix[i]) > pre(top->data))
//                 push(infix[i++]);
//             else
//             {
//                 postfix[j++] = pop();
//             }
//         }
//     }
//     while (top != nullptr)
//         postfix[j++] = pop();
//     postfix[j] = '\0';
//     return postfix;
// }

// int main()
// {
//     Stack stk;
//     char infix[] = "a+b*c-d/e";
//     char *postfix = stk.InToPost(infix);
//     cout << postfix << endl;
//     return 0;
// }

#include <iostream>
#include <cstring>
using namespace std;

class Stack;
class Node
{
public:
    char val;
    Node *next;
    Node()
    {
        next = nullptr;
    }
    Node(char val)
    {
        this->val = val;
    }
    friend class Stack;
};
class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = nullptr;
    }
    void Push(char x)
    {
        Node *temp = new Node(x);
        if (temp == nullptr)
        {
            cout << "Stack is Full " << endl;
        }
        else
        {
            temp->next = top;
            top = temp;
        }
    }
    char pop()
    {
        char x = -1;
        if (top == nullptr)
        {
            cout << "Stack is Empty\n";
        }
        else
        {
            Node *temp = top;
            x = temp->val;
            top = top->next;
            delete temp;
        }
        return x;
    }
    void display()
    {
        Node *temp = top;
        while (temp)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
    }
    char gettop()
    {
        char v = -1;
        if (top)
        {
            return top->val;
        }
        else
        {
            return v;
        }
    }
    int isempty()
    {
        if (top == nullptr)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

class inFixToPostFix
{
private:
    Stack stack;
    int pre(char x)
    {
        if(x=='^')
        {
            return 3;
        }
        else if (x == '+' || x == '-')
        {
            return 1;
        }
        else if (x == '*' || x == '/')
        {
            return 2;
        }
        return 0;
    }

    int isOperand(char x)
    {
        if (x == '+' || x == '-' || x == '*' || x == '/')
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }

public:
    void convert(char *infix, char *postfix)
    {
        int i = 0, j = 0;
        while (infix[i] != '\0')
        {
            if (isOperand(infix[i]))
            {
                postfix[j] = infix[i];
                j++;
                i++;
            }
            else
            {
                if (pre(infix[i]) > pre(stack.gettop()))
                {
                    stack.Push(infix[i]);
                    i++;
                }
                else
                {
                    postfix[j] = stack.pop();
                    j++;
                }
            }
        }
        while (!stack.isempty())
        {
            postfix[j] = stack.pop();
            j++;
        }
        postfix[j] = '\0';
    }
};
int main()
{
    inFixToPostFix conve;
    char infix[] = "a+b*c-d";
    char postfix[30];
    conve.convert(infix, postfix);
    cout << "Infix Expression: " << infix << endl;
    cout << "Postfix Expression: " << postfix << endl;
}
