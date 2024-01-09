#include<iostream>
#include<vector>
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
    vector<int>* treefromInandpreorder(vector<int> In, vector<int> pre){
        int p,q=0;
        
        
    }
};
int main() {
    

    cout << endl ;
    return 0;
}