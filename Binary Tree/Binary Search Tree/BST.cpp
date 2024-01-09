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
    Node * insertdata(Node * root, int val);
    void levelorderTrav(Node * root);
    void display();
    BST();
    ~BST();
};

BST::BST()
{
    root =  NULL;
}
void BST::levelorderTrav(Node * root){
    if(root == NULL){
        return;
    }
    else{
        cout << root->data << " ";
        levelorderTrav(root->left);
        levelorderTrav(root->right);
    }
}

void BST::display(){
    levelorderTrav(root);
}
Node * BST::insertdata(Node * root, int val){
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
void BST:: insert(int val){
    Node* newNode = new Node(val);
    if(root == NULL){
        root = newNode;
    }

    else{
        Node* temp = root;
        while(temp != NULL){
            if(temp->data > val){
                if(temp->left == NULL){
                    temp->left = newNode;
                    break;
                }
                else{
                    temp = temp->left;
                }
            }
            else{
                if(temp->right == NULL){
                    temp->right = newNode;
                    break;
                }
                else{
                    temp = temp->right;
                }
            }
        }
    }
}
BST::~BST()
{
}

int main() {
    
    BST bst;
    int input;
    while (input != -1)
    {
        cin >> input;
        if(input != -1){
            bst.insert(input);
        }
    }
    
    bst.display();

    

    cout << endl ;
    return 0;
}