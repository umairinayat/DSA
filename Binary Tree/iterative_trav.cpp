#include <iostream>
#include <queue>
#include <stack>
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

    void preorder()
    {
        Node *temp = root;
        stack<Node *> st;
        while (temp || !st.empty())
        {
            if (temp != NULL)
            {
                cout << temp->data << " ";
                st.push(temp);
                temp = temp->left;
            }
            else
            {
                temp = st.top();
                st.pop();
                temp = temp->right;
            }
        }
    }
    vector<int> zigzagLevelorder(Node *root)
    {

        vector<int> result;
        if (root == NULL)
        {
            return result;
        }

        queue<Node *> q;
        q.push(root);
        vector<int> level;
        bool LtoR = true;
        while (!q.empty())
        {
            int size = q.size();
            vector<int> level(size);

            for (int i = 0; i < size; i++)
            {
                Node *forntnode = q.front();
                q.pop();
                int index = LtoR ? i : size - i - 1;

                level[index] = forntnode->data;
                if (forntnode->left)
                {
                    q.push(forntnode->left);
                }
                if (forntnode->right)
                {
                    q.push(forntnode->right);
                    // LtoR = false;
                }
                LtoR = !LtoR;
                for (auto i : level)
                {
                    result.push_back(i);
                }
            }
        }

        return result;
    }

    void zigzag()
    {
        vector<int> result = zigzagLevelorder(root);
        for (int i = 0; i < result.size(); i++)
        {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    void inorder()
    {
        Node *temp = root;
        stack<Node *> st;
        while (temp || !st.empty())
        {
            if (temp != NULL)
            {
                // cout<<temp->data<<" ";
                st.push(temp);
                temp = temp->left;
            }
            else
            {
                temp = st.top();
                st.pop();
                cout << temp->data << " ";
                temp = temp->right;
            }
        }
    }

    void postOrder()
    {
        if (root == NULL)
        {
            return;
        }

        stack<Node *> s1, s2;
        s1.push(root);
        Node *node = nullptr;
        while (!s1.empty())
        {
            node = s1.top();
            s1.pop();
            s2.push(node);
            if (node->left)
            {
                s1.push(node->left);
            }
            if (node->right)
            {
                s1.push(node->right);
            }
        }
        while (!s2.empty())
        {
            node = s2.top();

            s2.pop();
            cout << node->data << " ";
        }
    }

    int heightoftree(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int leftheight = heightoftree(root->left);
        int rightheight = heightoftree(root->right);
        if (leftheight > rightheight)
        {
            return leftheight + 1;
        }
        else
        {
            return rightheight + 1;
        }
    }

    void height()
    {
        cout << heightoftree(root);
    }

    /*Diameter of a tree is the number of nodes on the longest path between two leaves in the tree. We have to find first if root has only left node or only right node
    then find the height of the tree and then find the diameter of the left and right subtree and then find the diameter of the root node.
    and if tree has both left and right then find the distance for both we have to find the height of tree and return max value  */

    int diameter(Node *root)
    { // using height function
        if (root == NULL)
        {
            return 0;
        }
        {
            int op1 = diameter(root->left);
            int op2 = diameter(root->right);
            int op3 = heightoftree(root->left) + heightoftree(root->right) + 1;

            return max(op1, max(op2, op3));
        }
    }

    void diameteroftree()
    {
        cout << diameter(root);
    }

    pair<int, int> diameterTree(Node *root)
    { // in order of T.C O(n) and S.C O(h)

        if (root == NULL)
        {
            pair<int, int> p = make_pair(0, 0);
            return p;
        }
        pair<int, int> left = diameterTree(root->left);
        pair<int, int> right = diameterTree(root->right);
        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second + 1;
        pair<int, int> ans;
        ans.first = max(op1, max(op2, op3)); // this is for diameter of tree and return the max value of diameter of tree for left and right subtree

        ans.second = max(left.second, right.second) + 1; // this is for height of tree and return the max value of height of tree

        return ans;
    }

    void DiameterOfTree()
    {
        pair<int, int> p = diameterTree(root);
        cout << "Diameter of tree is " << p.first << endl;
        cout << p.first << endl;
    }

    /*Leveltraversal of tree by push first node in queue check if queue is not empty then
    pop and print data if if left exist then push left else right untill queue become null */

    void leveltraversal()
    {
        Node *temp = root;
        queue<Node *> q;
        q.push(temp);
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            cout << temp->data << " ";
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
    bool isbalance(Node *root)
    {
        if (root == NULL)
        {
            return 1;
        }

        bool left = isbalance(root->left);
        bool right = isbalance(root->right);

        bool third = heightoftree(root->left) - heightoftree(root->right) <= 1;
        if (left && right && third)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void isBalance()
    {
        cout << isbalance(root);
    }

    pair<bool, int> isbalanced(Node *root) // this code is for both balance and height of tree in O(n)
    {
        if (root == NULL)
        {
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }
        pair<bool, int> Leftside = isbalanced(root->left);
        pair<bool, int> rightside = isbalanced(root->right);
        int hi = max(Leftside.second, rightside.second) + 1; // this is third option if root have both left and right subtree so we have to find the height of tree and maximum of left and right subtree
        bool balanced = abs(Leftside.second - rightside.second) <= 1;
        pair<bool, int> ans;
        if (balanced && Leftside.first && rightside.first)
        {
            ans.first = 1;
        }
        else
        {
            ans.first = 0;
        }
        ans.second = hi;

        return ans;
    }
    void pairbalance()
    {
        pair<bool, int> p = isbalanced(root);

        cout << "\nHeight of tree is " << p.second << endl;
        if (p.first)
        {
            cout << "\nTree is balanced" << endl;
        }
        else
        {
            cout << "\nTree is not balanced" << endl;
        }

        cout << "Height of tree is " << p.second << endl;
    }
    bool indeical(Node *r1, Node *r2)
    {
        // base case
        if (r1 == NULL && r2 == NULL)
        {
            return true;
        }
        if (r1 != NULL && r2 == NULL)
        {
            return false;
        }
        if (r1 == NULL && r2 != NULL)
        {
            return false;
        }
        bool leftside = indeical(r1->left, r2->left);
        bool rightside = indeical(r1->right, r2->right);
        bool equal = r1->data == r2->data;

        if (equal && leftside && rightside)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    pair<bool, int> issum(Node *root)
    {
        if (root == NULL)
        {
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }
        if (root->left == NULL && root->right == NULL)
        {
            pair<bool, int> p = make_pair(true, root->data);
            return p;
        }

        pair<bool, int> leftside = issum(root->left);
        pair<bool, int> rightside = issum(root->right);

        bool leftans = leftside.first;
        bool rightans = rightside.first;

        bool cnd = root->data == leftside.second + rightside.second + root->data;
        pair<bool, int> ans; // this is for both height and sum of tree
        if (!leftans || !rightans || !cnd)
        {
            ans.first = false;
        }
        else
        {
            ans.first = true;
        }

        ans.second = max(leftside.second, rightside.second);

        return ans;
    }

    void Issum()
    {
        pair<bool, int> p = issum(root);

        cout << "\nHeight of tree is " << p.second << endl;
        if (p.first)
        {
            cout << "\nTree is balanced" << endl;
        }
        else
        {
            cout << "\nTree is not balanced" << endl;
        }

        cout << "Height of tree is " << p.second << endl;
    }

    void istreeidetical()
    {
        bool val = indeical(root, root);
        if (val)
        {
            cout << "This is identical Tree" << endl;
        }
        else
        {
            cout << "This is not Identical tree" << endl;
        }
    }
};

int main()
{
    Binarytree b1;
    b1.create(); // 2 3 4 5 -1 7 9 -1 11 14 -1 -1 16 -1 -1 18 20 -1 -1 -1 -1 -1 -1

    cout << endl;
    b1.preorder();
    cout << "\nInorder \n";
    b1.inorder();

    cout << "\nPostorder \n";
    b1.postOrder();
    cout << endl;

    cout << "\nDiameter of tree \n";
    b1.DiameterOfTree();

    cout << "\n\n";
    b1.pairbalance();

    b1.istreeidetical();
    cout << endl;

    b1.Issum();
    cout << endl;

    b1.zigzag();
    return 0;
}