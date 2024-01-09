#include <iostream>
#include <queue>
#include<algorithm>
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

class Binarytree
{
private:
    Node *root;

public:
    Binarytree()
    {
        root = nullptr;
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
    void create()
    {
        Node *p, *temp;
        int x;
        queue<Node *> q;
        cout << "Enter the root value" << endl;
        cin >> x;
        root = new Node(x);
        root->left = root->right = NULL;
        q.push(root);
        while (!q.empty())
        {
            p = q.front();
            q.pop();
            cout << "Enter the data of left child of " << p->data << endl;
            cin >> x;
            if (x != -1)
            {
                temp = new Node(x);
                temp->left = temp->right = NULL;
                p->left = temp;
                q.push(temp);
            }
            cout << "Enter the data of right child of " << p->data << endl;
            cin >> x;
            if (x != -1)
            {
                temp = new Node(x);
                temp->left = temp->right = NULL;
                p->right = temp;
                q.push(temp);
            }
        }
    }
    int countleaf(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        if (root->left==NULL && root->right==NULL )
        {
            return 1;
        }
        int leftcount= countleaf(root->left);
        int rightcount= countleaf(root->right);

        return leftcount + rightcount;
    }
    void leaf(){
        cout<<countleaf(root);
    }


    int countnode(Node *p)
    {
        int x, y;
        if (p != NULL)
        {
            x = countnode(p->left);
            y = countnode(p->right);
            return x + y + 1;
        }
        return 0;
    }
    void count()
    {
        cout << countnode(root);
    }

    int heightoftree(Node *root){
        if (root==NULL)
        {
            return 0;
        }

        int leftheight= heightoftree(root->left);
        int rightheight= heightoftree(root->right);
        if (leftheight>rightheight)
        {
            return leftheight+1;
        }
        else
        {
            return rightheight+1;
        }
       
        
    }

    void height(){
        cout<<heightoftree(root);
    }

};

int main()
{
    Binarytree *tree = new Binarytree;
    tree->create(); // 2 3 4 5 -1 7 9 -1 11 14 -1 -1 16 -1 -1 18 20 -1 -1 -1 -1 -1 -1
    cout<<"\nTotal Node\n";
    tree->count();
    cout<<"\nTotal leaf Node\n";
    tree->leaf();
     cout<<"\nHeight of Tree\n";
    tree->height();
    cout << endl;
    delete tree;
    return 0;
}