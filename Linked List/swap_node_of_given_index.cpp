/*
Make a linked list class with all required functionalities.
•
Keep taking integer inputs from the user unless -1 is entered.
•
The inputs are the indexes of the linked list you need to arrange in DECENDING order.
Take the linked list above as an example, if the user enters the following values:
4
2
1
-1
The linked list should be altered as following:
NOTE:
•
The first node of linked list considers as index 1.
•
You are not allowed to swap the data.
•
The nodes should be swapped
•
The user can enter as many indexes as much he/she want. If some index entered by user is an invalid index, ignore that value and word on the valid indexes.
•
Display that which particular index was invalid.
•
Display unsorted as well as sorted list too.
•
Above mentioned linked list is just sample linked-list. Your program must be generalized. Generalization in the form user can add as many nodes as much he/she want. That’s why make a use manual too for this program.


*/



#include<iostream>
#include<vector>
using namespace std;

class Node
{
public:
	int data;
	Node* next;
	Node();
	Node(int data);
	~Node();

};

Node::Node()
{
	this->data = 0;
	next = NULL;
}

Node::Node(int data)
{
	this->data = data;
	next = NULL;
}

Node::~Node()
{

}


class Linkedlist
{
private:
	Node* head;
public:
	Linkedlist();
	void insert(int data);
	void DecendingOrder(vector<int> arr);
	Node* getindex(int ind);
	void swapNodes(int p1, int p2);
	void print();
	~Linkedlist();



};

Linkedlist::Linkedlist()
{
	head = NULL;
}

void Linkedlist::insert(int data)
{
	Node* temp = new Node(data);
	if (head == NULL)
	{
		head = temp;
	}
	else
	{
		Node* curr = head;
		while (curr->next)
		{
			curr = curr->next;
		}
		curr->next = temp;
	}
}

void Linkedlist::swapNodes(int p1, int p2) {
	if (p1 == p2) {  //If both node are null
		return;
	}

	Node* prev1 = NULL;
	Node* curr1 = head;
	for (int i = 1; i < p1 && curr1 != NULL; i++) {   //Go to first node
		prev1 = curr1;
		curr1 = curr1->next;
	}

	Node* prev2 = NULL;
	Node* curr2 = head;
	for (int i = 1; i < p2 && curr2 != NULL; i++) {  //Go to 2nd node
		prev2 = curr2;
		curr2 = curr2->next;
	}
	  
	if (curr1 == NULL || curr2 == NULL) {              //If both are null then ERROR 
		cout << "Invalid positions for swapping." << endl;
		return;
	}

	if (prev1 != NULL) {              
		prev1->next = curr2;
	}
	else {
		head = curr2;              //if first node is head
	}

	if (prev2 != NULL) {
		prev2->next = curr1;
	}
	else { 
		head = curr1;              ////if second node is head
	}

	Node* temp = curr1->next;            //Here actual swap done there 
	curr1->next = curr2->next;
	curr2->next = temp;
}
void Linkedlist::DecendingOrder(vector<int> arr) //Taking arr of index which we have to swap 
{
	if (head == NULL || head->next == NULL)
	{
		return;
	}

	int n = arr.size();           //to get size of index 

	int i = 0;
	while (n - 1 > i)
	{
		Node* curr = getindex(arr[i]);
		Node* p = getindex(arr[i + 1]);
		if (curr->data > p->data)
		{
			swapNodes(arr[i], arr[i + 1]);   //calling swap function 
			i = 0;                           //again start from first index 
		}
		else {
			i++;
		}

	}

}

Node* Linkedlist::getindex(int ind)
{
	if (ind == 0)
	{
		return nullptr;
	}

	Node* curr = head;
	for (int i = 1; i < ind; i++)
	{
		if (curr == nullptr)
		{
			return NULL; 
		}
		curr = curr->next;
	}
	return curr;
}

Linkedlist::~Linkedlist()
{
	Node* current = head;
	while (current)
	{
		Node* nextNode = current->next;
		delete current;
		current = nextNode;
	}
}

void Linkedlist::print()
{
	Node* curr = head;
	while (curr)
	{
		cout << curr->data << " ";
		curr = curr->next;
	}
	cout << endl;
}


int main()
{
	Linkedlist myList;

	cout << "Enter integer values to create a linked list. Enter -1 to stop.\n";

	int input;
	while (true)
	{
		cin >> input;
		if (input == -1)
			break;

		myList.insert(input);
	}

	cout << "Unsorted linked list: ";      // Display unsorted list
	myList.print();

	// Input indices for descending order
	vector<int> indices;               //Storing in vector array 
	cout << "Enter indices to arrange in descending order. Enter -1 to stop.\n";
	while (true)
	{
		cin >> input;
		if (input == -1)
			break;

		indices.push_back(input);
	}

	// Sort the list in descending order based on indices
	myList.DecendingOrder(indices);

	cout << "Sorted linked list: ";
	// Display sorted list
	myList.print();

	return 0;
}

