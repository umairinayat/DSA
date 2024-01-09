#include<iostream>

using namespace std;


class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(){
            data = 0;
            left = NULL;
            right = NULL;
        }
        Node(int val){
            data = val;
            left = NULL;
            right = NULL;
        }
};

class BST
{
private:
    /* data */
    Node *root; 
public:
    void insert(int val);
    Node * insertdata(Node *& root, int val);
    Node* deleteNode(Node *& root, int val);
    void deletenode(int val);
    void inorder(Node *& root);
    Node * findmax(Node * root);
    void display();
    BST(){
        root =  NULL;
    }
    ~BST(){
        delete root;
    
    }
};
void BST::deletenode(int val){
    deleteNode(root, val);
}

void BST::insert(int val){
    root = insertdata(root, val);
}

Node * BST::insertdata(Node *& root, int val){
    if(root == NULL){
        root = new Node(val);
    }
    else if(val <= root->data){
        root->left = insertdata(root->left, val);
    }
    else{
        root->right = insertdata(root->right, val);
    }
    return root;
}
void BST::inorder(Node *& root){
    if(root == NULL){
        return;
    }
    else{
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
    
}
void BST::display(){
    inorder(root);
    cout<<endl;
}
Node* BST::findmax(Node * root){
    if(root == NULL){
        return NULL;
    }
    else if(root->right == NULL){
        return root;
    }
    else{
        return findmax(root->right);
    }
}
Node* BST::deleteNode(Node *& root,int val){
    if(root == NULL){
        return NULL;
    }
    else if(val < root->data){
        root->left = deleteNode(root->left, val);
    }
    else if(val > root->data){
        root->right = deleteNode(root->right, val);
    }
    else{
        if(root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
        }
        else if(root->left == NULL){
            Node * temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == NULL){
            Node * temp = root;
            root = root->left;
            delete temp;
        }
        else{
            Node * temp = findmax(root->left);
            root->data = temp->data;
            root->left = deleteNode(root->left, temp->data);
            
        }
    }
    return root;
}
int main() {
    BST *bst = new BST(); // Initialize the BST pointer

    bst->insert(5);
    bst->insert(3);
    bst->insert(7);
    bst->insert(1);
    bst->insert(4);
    bst->insert(6);
    bst->insert(8);

    cout << "Original BST: ";
    bst->display();

    bst->deletenode(6);

    cout << "BST after deleting node 6: ";
    bst->display();

    delete bst; // Don't forget to delete the BST object

    return 0;
}