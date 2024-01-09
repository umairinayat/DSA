#include<iostream>
using namespace std;
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left, *right;
    BinaryTreeNode() : data(0), left(NULL), right(NULL) {}
    BinaryTreeNode(T x) : data(x), left(NULL), right(NULL) {}
    BinaryTreeNode(T x, BinaryTreeNode<T> *left, BinaryTreeNode<T> *right) : data(x), left(left), right(right) {}
};

bool searchInBST(BinaryTreeNode<int> *root, int x)
{
    BinaryTreeNode<int> *p = root;
    while (p != NULL)
    {
        if (p->data == x)
        {
            return true;
        }
        else if (p->data > x)
        {
            p = p->left;
        }
        else
        {
            p = p->right;
        }
    }

    return false;
}
bool searchInBST(BinaryTreeNode<int> *root, int x)
{
    // Write your code here.
    if (root == NULL)
    {
        return false;
    }
    if (root->data == x)
    {
        return true;
    }
    else if (root->data > x)
    {
        searchInBST(root->left, x);
    }
    else
    {
        searchInBST(root->right, x);
    }
}
// Function to insert a node in a Binary Search Tree
BinaryTreeNode<int>* insertInBST(BinaryTreeNode<int>* root, int x) {
    if (root == NULL) {
        BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(x);
        return newNode;
    }
    
    if (x < root->data) {
        root->left = insertInBST(root->left, x);
    } else {
        root->right = insertInBST(root->right, x);
    }
    
    return root;
}

int main() {
    // Test the searchInBST function
    BinaryTreeNode<int>* root = NULL;
    root = insertInBST(root, 5);
    root = insertInBST(root, 3);
    root = insertInBST(root, 7);
    root = insertInBST(root, 1);
    root = insertInBST(root, 4);
    root = insertInBST(root, 6);
    root = insertInBST(root, 8);
    
    int x = 6;
    if (searchInBST(root, x)) {
        cout << x << " is present in the BST." << endl;
    } else {
        cout << x << " is not present in the BST." << endl;
    }
    
    return 0;
}
