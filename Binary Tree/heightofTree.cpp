
#include <stdlib.h>
#include <queue>
// Following is the TreeNode class structure

template <class T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

int heightOfBinaryTree(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    queue<TreeNode<int> *> q;
    q.push(root);
    int hei = 0;
    while (q.size() > 0)
    {
        int count = q.size();

        for (int i = 0; i < count; i++)
        {
            TreeNode<int> *node = q.front();
            q.pop();

            if (node->left != NULL)
            {
                q.push(node->left);
            }
            if (node->right != NULL)
            {
                q.push(node->right);
            }
        }
        hei++;
    }
    return hei;
}

int heightOfBinaryTree(TreeNode<int> *root)   //recurion code 
{
    // Write your code here.
    if (root == NULL)
    {
        return 0;
    }

    int left = heightOfBinaryTree(root->left);
    int right = heightOfBinaryTree(root->right);

    int ans = max(left, right) + 1;

    return ans;
}
