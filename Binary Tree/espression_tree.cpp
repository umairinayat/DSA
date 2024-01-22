#include <iostream>
#include <stack>

using namespace std;

struct node
{
    char data;
    node *left;
    node *right;
};

node *create_node(char data)
{
    node *new_node = new node();
    new_node->data = data;
    new_node->left = nullptr;
    new_node->right = nullptr;
    return new_node;
}

node *construct_tree(char postfix[])
{
    stack<node *> s;
    int i = 0;
    while (postfix[i] != '\0')
    {
        char ch = postfix[i];
        if (ch >= 'A' && ch <= 'Z')
        {
            node *new_node = create_node(ch);
            s.push(new_node);
        }
        else
        {
            node *new_node = create_node(ch);
            new_node->right = s.top();
            s.pop();
            new_node->left = s.top();
            s.pop();
            s.push(new_node);
        }
        i++;
    }
    return s.top();
}

void inorder(node *root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main()
{
    char postfix[] = "ABC*+D/";
    node *root = construct_tree(postfix);
    cout << "Inorder traversal of expression tree:" << endl;
    inorder(root);
    return 0;
}
