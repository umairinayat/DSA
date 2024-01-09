#include <iostream>
#include <queue>
using namespace std;

class Node
{

public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    Node()
    {
        data = -1;
        this->left = NULL;
        this->right = NULL;
    }
    ~Node()
    {
        delete left;
        delete right;
    }
};
void postorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
void preorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);

    preorder(root->right);
}

void levelorder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(nullptr);
    while (!q.empty())
    {
        Node *temp = q.front();

        q.pop();
        if (temp == NULL) // Use seprater here after every level
        {                 // Completeed one level traversal
            cout << endl;
            if (!q.empty()) // if queue still has some child nodes
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
void buildtreefromlevel(Node *&root)
{
    queue<Node *> q;
    cout << "Enter the data from root" << endl;
    int data;
    cin >> data;

    root = new Node(data);
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        cout << "Enter the data of left side of " << temp->data << endl;
        int leftdata;
        cin>>leftdata;

        if(leftdata != -1){
            temp->left= new Node(leftdata);
            q.push(temp->left);
        }

        cout << "Enter the data for right side of " << temp->data << endl;
        int rightdata; 
        cin>>rightdata;

        if (rightdata != -1)
        {
            temp->right= new Node(rightdata);
            q.push(temp->right);
        }
        


    }
}
void inorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
Node *buildtree(Node *&root)
{
    int x;

    cout << "Enter the Data" << endl;
    cin >> x;
    root = new Node(x);
    if (x == -1) // base case
    {
        return nullptr;
    }
    cout << "Enter the data of left side of " << root->data << endl;
    root->left = buildtree(root->left);
    cout << "Enter the data for right side pf " << root->data << endl;
    root->right = buildtree(root->right);

    return root;
}

int main()
{
    Node *n1 = nullptr;
    //buildtree(n1);
    buildtreefromlevel(n1);
    cout << "Level Order Traversal" << endl;
    levelorder(n1);
    cout << endl;
    cout << "In Order Traversal" << endl;
    inorder(n1);
    cout << endl;
    cout << "Pre order" << endl;
    preorder(n1);
    cout << endl;
    cout << "post order" << endl;
    postorder(n1);
    cout << endl;
    exit;
    return 0;
}