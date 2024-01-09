#include<iostream>
#include<vector>
using namespace std;

template<class T>
class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;
        TreeNode(){
            data = 0;
            left = NULL;
            right = NULL;
        }
        TreeNode(T val){
            data = val;
            left = NULL;
            right = NULL;
        }
};

void inorder(TreeNode<int> *root, vector<int> &v){
    if(root == NULL){
        return;
    }
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
    
} 

TreeNode<int> * flatten(TreeNode<int> *root){
    if(root == NULL){
        return NULL;
    }
    vector<int> inorderval;
    
    inorder(root, inorderval);
    int n = inorderval.size();
    TreeNode<int> * newnode= new TreeNode<int>(inorderval[0]);
    TreeNode<int> * curr = newnode;

    for(int i =1; i<n; i++){
        TreeNode<int> * temp = new TreeNode<int>(inorderval[i]);
           

        curr->left = NULL;
        curr->right = temp;
        curr= temp;

    }

    curr->left = NULL;
    curr->right = NULL;

    return newnode;
}

