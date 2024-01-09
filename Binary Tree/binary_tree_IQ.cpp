#include <iostream>
#include <queue>
#include <stack>
#include <vector>
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

    vector<int> zigzagLevelorder(Node *root)
    {
        
        vector<int> ans;
        if (root == NULL)
        {
            return;
        }

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            vector<int> ans(size);
            bool LtoR = true;
            for (int i = 0; i < size; i++)
            {
                Node *forntnode = q.front();
                q.pop();
                int index;
                if (LtoR)
                {
                    index = i;
                }
                else
                {
                    index = size - i - 1;
                }
                ans[index]= forntnode->data;
                if (forntnode->left)
                {
                    q.push(forntnode->left);
                }
                if (forntnode->right)
                {
                    q.push(forntnode->right);
                    LtoR=false;
                }
                
            }
        }
        vector<int> result(ans.size());
        for (int i = 0; i < ans.size(); i++)
        {
            result.push_back(ans[i]);
        }
        return result;
    }
};