#include <iostream>

// Following is the Binary Tree Node class structure:

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void inorder(BinaryTreeNode<int> *root, int &count)
{
    if (root == nullptr)
    {
        return;
    }

    inorder(root->left, count);
    if (root->left == NULL && root->right == NULL)
    {
        count++;
    }
    inorder(root->right, count);
}
int noOfLeafNodes(BinaryTreeNode<int> *root)
{
    // Write your code here.
    int count = 0;

    inorder(root, count);

    return count;
}
