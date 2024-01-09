/*We are asked to build an address book that is capable of storing name, address and phone number of a person. 
Your program will get the information in the form of input (name, address and phone number) from console. 
This data will be stored in a linked list in alphabetical order i.e. all names that start from letter 
A will come first following the names that start from letter B and so on. Your program will get the information of a person from console.
After inserting the required information, the node will be inserted in the linked list in the right place. Furthermore, 
you are required to write a find function for list class that will help you in finding a person record by passing its name. 
As it is the program for phone directory, so must include the user manual properly.
And your program must not be terminated until unless user press a specific key.*/




#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

class Node {
public:
	string name;
	string phoneNumber;
	string address;
	Node* next;
	Node() {
		next = NULL;
	}
	Node(string name, string address, string phoneNumber);
	~Node();
};

Node::Node(string name, string address, string phoneNumber) {
	this->name = name;
	this->address = address;
	this->phoneNumber = phoneNumber;
	this->next = nullptr;
}

Node::~Node() {
	
}

class AddressBook {
private:
	Node* head;
public:
	AddressBook();
	void insert(string n, string a, string p);
	Node* find(string name);
	void print();
	~AddressBook();
};

AddressBook::AddressBook() {
	head = nullptr;
}

void AddressBook::insert(string name, string address, string phoneno) {
	Node* newNode = new Node(name, address, phoneno);

	if (head ==	NULL || name < head->name) {
		newNode->next = head;
		head = newNode;
	}
	else {
		Node* curr = head;
		while (curr->next && name > curr->next->name) {
			curr = curr->next;
		}
		newNode->next = curr->next;
		curr->next = newNode;
	}
}

Node* AddressBook::find(string name) {
	Node* curr = head;
	while (curr && curr->name != name) {
		curr = curr->next;
	}
	return curr;
}

void AddressBook::print() {
	Node* curr = head;
	while (curr) {
		cout << "Name: " << curr->name << "\nAddress: " << curr->address
			<< "\nPhone Number: " << curr->phoneNumber << "\n\n";
		curr = curr->next;
	}
}

AddressBook::~AddressBook() {
	Node* current = head;
	while (current != NULL) {
		Node* nextNode = current->next;
		delete current;
		current = nextNode;
	}
}

int main() {
	AddressBook addressBook;

	while (true) {
		char choice;
		system("cls");
		while (true) {
			cout << "=====================================" << endl;
			cout << "|           Address Book Menu:       |" << endl;
			cout << "=====================================" << endl;
			cout << "| 1. Add a new record                |" << endl;
			cout << "| 2. Search for a person by name     |" << endl;
			cout << "| 3. Print the entire address book   |" << endl;
			cout << "| 4. Exit                            |" << endl;
			cout << "=====================================" << endl;
			cout << "Enter your choice (1-4): ";

			try {
				string input;
				getline(cin, input);
				choice = input[0];

				if (choice < '1' || choice > '4') {
					throw out_of_range("Invalid input. Please enter a number between 1 and 4.");
				}

				break;
			}
			catch (const out_of_range& e) {
				cout << e.what() << endl;
				// Clear the input buffer
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}

		//cin.ignore();
		char x;
		switch (choice) {
		case '1': {
			do {
				string name, address, phoneNumber;

				cout << "Enter name: ";
				getline(cin, name);

				cout << "Enter address: ";
				getline(cin, address);

				do {
					cout << "Enter phone number (10 digits): ";
					getline(cin, phoneNumber);

					if (phoneNumber.length() == 10 && all_of(phoneNumber.begin(), phoneNumber.end(), ::isdigit)) {
						break;
					}
					else {
						cout << "Invalid phone number. Please enter exactly 10 digits.\n";
					}
				} while (true);

				addressBook.insert(name, address, phoneNumber);

				cout << "Do you want to add another record? (y/n): ";
				cin >> choice;
				cin.ignore();

			} while (tolower(choice) == 'y');
			break;
		}

		case '2': {
			string searchName;
			cout << "Enter name to search: ";
			getline(cin, searchName);

			Node* foundNode = addressBook.find(searchName);

			if (foundNode) {
				cout << "Record found:\n";
				cout << "Name: " << foundNode->name << "\nAddress: " << foundNode->address
					<< "\nPhone Number: " << foundNode->phoneNumber << "\n";
			}
			else {
				cout << "Record not found.\n";
			}
			cout << "Enter any Character to goto Main menu...: ";
			cin >> x;
			cin.ignore();
			break;
		}

		case '3':
			cout << "\nAddress Book:\n";
			addressBook.print();
			cout << "Enter any Character to goto Main menu...: ";
			cin >> x;
			cin.ignore();
			break;

		case '4':
			cout << "Exiting the program.\n";
			return 0;

		default:
			cout << "Invalid choice. Please enter a number between 1 and 4.\n";
			cout << "Enter any Character to goto Main menu...: ";
			cin >> x;
			cin.ignore();
			
			break;
		}
	}

	return 0;
}
