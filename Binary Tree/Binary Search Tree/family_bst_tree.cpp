/*
Design a family tree using a Binary Search Tree, where each node represents a family member. 
The family members are identified by unique names. Implement the following functionalities:  

1. Insert a new family member into the tree, ensuring that the BST property is maintained. 

2. Search for a family member and return his/her information (or indicate if not found). 

3. Traverse the family tree in-order, pre-order, and post-order to display the family members in different orders.

 4. Implement a function to find the oldest family member in the tree. 

5. Extend the family tree by adding relationships (e.g., parent-child) 
between existing family members, ensuring the BST property is preserved. 

*/


#include<iostream>
#include<string>

using namespace std;


class Node {
public:
	string name;
	int age;
	Node* left;
	Node* right;
	Node(string n, int a) {
		name = n;
		age = a;
		left = NULL;
		right = NULL;
	}
	Node() {
		name = "";
		age = 0;
		left = NULL;
		right = NULL;
	}
};


Node* insert(Node* root, string name, int age) {

	if (root == nullptr) {
		return new Node(name, age);
	}

	if (name < root->name) {
		root->left = insert(root->left, name, age);
	}

	else if (name > root->name) {
		root->right = insert(root->right, name, age);
	}
	return root;
}


Node* search(Node* root, string name) {

	if (root == nullptr) {
		cout << "The family tree is empty." << endl;
		return nullptr;
	}

	if (name < root->name) {
		return search(root->left, name);
	}

	else if (name > root->name) {
		return search(root->right, name);
	}

	else {
		return root;
	}
}


void inorder(Node* root) {

	if (root != nullptr) {
		inorder(root->left);
		cout << root->name << ", age " << root->age << endl;
		inorder(root->right);
	}
}

void preorder(Node* root) {

	if (root != nullptr) {
		cout << root->name << ", age " << root->age << endl;
		preorder(root->left);
		preorder(root->right);
	}
}


void postorder(Node* root) {

	if (root != nullptr) {
		postorder(root->left);
		postorder(root->right);
		cout << root->name << ", age " << root->age << endl;
	}
}


pair<string, int> findOldest(Node* root) {

	if (root == nullptr) {
		return make_pair("", 0);
	}

	pair<string, int> oldest = make_pair(root->name, root->age);

	pair<string, int> leftOldest = findOldest(root->left);

	if (leftOldest.second > oldest.second) {
		oldest = leftOldest;
	}

	pair<string, int> rightOldest = findOldest(root->right);

	if (rightOldest.second > oldest.second) {
		oldest = rightOldest;
	}

	return oldest;
}


Node* addRelationship(Node* root, string parent, string child) {

	if (root == nullptr) {
		cout << "The family tree is empty." << endl;
		return root;
	}


	Node* parentNode = search(root, parent);


	if (parentNode == nullptr) {
		cout << "The parent is not in the family tree." << endl;
		return root;
	}


	Node* childNode = search(root, child);

	if (childNode == nullptr) {
		childNode = new Node(child, 0);
	}


	if (parentNode->left != nullptr && parentNode->left->name == childNode->name) {
		cout << "The child is already a child of the parent." << endl;
		return root;
	}

	if (parentNode->right != nullptr && parentNode->right->name == childNode->name) {
		cout << "The child is already a child of the parent." << endl;
		return root;
	}


	if (childNode->name < parentNode->name) {
		parentNode->left = childNode;
	}

	else {
		parentNode->right = childNode;
	}


	return root;
}
int main() {
	Node* root = nullptr;

	int choice;
	do {
		cout << "\nFamily Tree Menu:\n";
		cout << "1. Insert a family member\n";
		cout << "2. Search for a family member\n";
		cout << "3. Display family tree in In-order\n";
		cout << "4. Display family tree in Pre-order\n";
		cout << "5. Display family tree in Post-order\n";
		cout << "6. Find the oldest family member\n";
		cout << "7. Add relationship between existing members\n";
		cout << "8. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1: {
			string name;
			int age;
			cout << "Enter the name of the family member: ";
			cin >> name;
			cout << "Enter the age of the family member: ";
			cin >> age;
			root = insert(root, name, age);
			break;
		}
		case 2: {
			string name;
			cout << "Enter the name of the family member to search: ";
			cin >> name;
			Node* foundNode = search(root, name);
			if (foundNode != nullptr) {
				cout << "Found " << foundNode->name << ", age " << foundNode->age << "." << endl;
			}
			else {
				cout << "Family member not found." << endl;
			}
			break;
		}
		case 3:
			cout << "In-order traversal:\n";
			inorder(root);
			break;
		case 4:
			cout << "Pre-order traversal:\n";
			preorder(root);
			break;
		case 5:
			cout << "Post-order traversal:\n";
			postorder(root);
			break;
		case 6: {
			pair<string, int> oldest = findOldest(root);
			if (!oldest.first.empty()) {
				cout << "Oldest family member: " << oldest.first << ", age " << oldest.second << "." << endl;
			}
			else {
				cout << "Family tree is empty." << endl;
			}
			break;
		}
		case 7: {
			string parent, child;
			cout << "Enter the name of the parent: ";
			cin >> parent;
			cout << "Enter the name of the child: ";
			cin >> child;
			root = addRelationship(root, parent, child);
			break;
		}
		case 8:
			cout << "Exiting program.\n";
			break;
		default:
			cout << "Invalid choice. Please enter a valid option.\n";
		}

	} while (choice != 8);

	return 0;
}
