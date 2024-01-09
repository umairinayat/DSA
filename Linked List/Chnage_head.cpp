/*
You are required to write a program that will changes the head of the doubly linked list to the specified position. Remember after these changes your list should remain a valid doubly linked List.
The prototype of the function is as follows:
after calling positionHead(3)
2
1
head
8
3
11
1
head
3
11
2
8
NOTE:
•
User can enter the position.
•
Display unsorted as well as sorted list too.
•
Above mentioned linked list is just sample linked-list. Your program must be generalized. Generalization in the form user can add as many nodes as much he/she want. That’s why make a use manual too for this program.


*/




#include<iostream>

using namespace std;
class Doublylinkedlist;
class Node
{

	int data;
	Node* next;
	Node* prev;
	friend class Doublylinkedlist;     // make friend class to acces the data member of node class 
	 
public:
	Node(int data);
	Node();
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
	delete next;
}

class Doublylinkedlist {
private:
	Node* head;

public:
	Doublylinkedlist();
	void Insertattail(int val);
	void updatehead(int index);
	void print();

};

Doublylinkedlist::Doublylinkedlist()
{
	head = NULL;
}

void Doublylinkedlist::Insertattail(int val)   //for adding at the tail of node 
{
	Node* curr = new Node;
	curr->data = val;
	curr->prev = NULL;
	curr->next = NULL;


	if (head == NULL)
	{
		head = curr;
	}
	else
	{
		Node* temp = head;
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = curr;
		curr->prev = temp;
	}
}

void Doublylinkedlist::updatehead(int index)
{

	if (head == NULL || index == 1)       //if head is equal to null or only one is present 
	{
		cout << "Invalid position!" << endl;
		return;
	}


	Node* curr = head;
	for (int i = 1; i < index && curr; ++i) {         //go to that index
		curr = curr->next;
	}

	if (curr == NULL) {                              //if current become null 
		cout << "Invalid position!" << endl;
		return;
	}
	Node* tail = head;                               // make the tail equal to head

	while (tail->next)
	{
		tail = tail->next;                           //go to last node
	}

	head->prev = curr->prev;                         
	curr->prev->next = NULL;
	tail->next = head;
	tail = head->prev;
	 
	head = curr;                                    //Update cuurent to head

}

void Doublylinkedlist::print()
{
	Node* temp = head;
	while (temp)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}


int main() {
	Doublylinkedlist l1;
	cout << "Enter integer values to create a linked list. Enter -1 to stop.\n";

	int input;
	while (true)
	{
		cin >> input;
		if (input == -1)
			break;

		l1.Insertattail(input);
	}
	cout << "Before update" << endl;
	l1.print();
	cout << "Enter the index you want to make that head" << endl;
	cin >> input;
	l1.updatehead(input);
	cout << "Before update" << endl;
	l1.print();

	return 0;
}
