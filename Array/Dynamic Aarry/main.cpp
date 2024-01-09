

#include<iostream>
#include"dynamicArray.h"
#include"dynamicArray.cpp"
#include<Windows.h>
#include <string>
#include <thread>
#include <stdexcept>
#include <conio.h>
using namespace std;


// Function to display loading animation
void load() {
	cout << "=====================================" << endl;
	cout << "Loading";


	for (int i = 0; i < 3; ++i) {
		this_thread::sleep_for(chrono::milliseconds(200));
		cout << ".";
		cout.flush();
		this_thread::sleep_for(chrono::milliseconds(200));
	}
	cout << endl;
	cout << "=====================================" << endl;
	// Pause for a moment before continuing
	Sleep(300);

	// Continue with the rest of your code after 1 second
	cout << endl << "Loading complete!" << endl;
}


int main() {

	string input;
	int choice, data;
	int index;
	int num;
	while (true)   // Loop to get a valid initial size 
	{
		cout << "Enter the initial size of the array: ";
		try
		{
			getline(cin, input);
			num = stoi(input);
			if (num >= 0)
			{
				break;
			}
			else
			{
				// Display error message for negative size input
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, 12);
				cout << "Size of Array Must be a Positive Number." << endl;
				SetConsoleTextAttribute(hConsole, 7);
			}
		}
		catch (const invalid_argument& e)
		{
			// Display error message for invalid input
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, 12);
			cout << "Invalid input. Please enter an integer." << endl;
			SetConsoleTextAttribute(hConsole, 7);
		}
	}
	cout << endl;
	
	dynamicArray<int> Obj(num);           // Create a dynamic array object

	int* temp_arr = new int[num];         // Temporary array to store initial elements

	if (num > 0)
	{

		cout << "  ==== Initialize Array ====\n"
			<< endl;


		for (int i = 0; i < num; i++)     // Loop to get initial elements from the user
		{
			while (true)
			{
				cout << "  arr[" << i << "]: ";
				try
				{
					getline(cin, input);
					temp_arr[i] = stoi(input);
					break;
				}
				catch (const invalid_argument& e)
				{
					// Display error message for invalid input
					HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hConsole, 12);
					cout << "Invalid input. Please enter an integer." << endl;
					SetConsoleTextAttribute(hConsole, 7);
				}
			}
		}

		for (int i = 0; i < num; i++)
		{
			Obj.insertAtZeroIndex(temp_arr[i]);          // Insert initial elements into the dynamic array at zero index
		}
		system("cls");
	}
	bool flag = false;
	char x;


	// Main menu loop
	while (true)
	{
		// Display user manual and options 
		cout << "=====================================" << endl;
		cout << "|           User Manual:             |" << endl;
		cout << "=====================================" << endl;
		cout << "| 1. Insert data into the array.     |" << endl;
		cout << "| 2. Insert data at the zero index.  |" << endl;
		cout << "| 3. Insert data at a specific index |" << endl;
		cout << "| 4. Remove element at zero index.   |" << endl;
		cout << "| 5. Remove element at last index.   |" << endl;
		cout << "| 6. Remove element at any index.    |" << endl;
		cout << "| 7. View current array state.       |" << endl;
		cout << "| 8. Increase array size.            |" << endl;
		cout << "| 9. Exit.                           |" << endl;
		cout << "=====================================" << endl;
		cout << "Enter your choice (1 to 9): ";
		
		
		while (true)                // Loop to get valid choice from the user
		{
			cout << endl;
			cout << "Enter Choice: ";
			try
			{
				getline(cin, input);
				choice = stoi(input);
				if (choice < 1 || choice > 9)
				{
					// Display error message for invalid choice
					HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hConsole, 12);
					cout << "Invalid Choice Range." << endl;
					SetConsoleTextAttribute(hConsole, 7);
				}
				else
				{
					break;
				}
			}
			catch (const invalid_argument& e)
			{
				// Display error message for invalid input
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, 12);
				cout << "Invalid input. Please enter an integer." << endl;
				SetConsoleTextAttribute(hConsole, 7);
			}
		}
		cout << endl;
		switch (choice)          // Switch case to handle user choices
		{
		case 1:
			while (true)
			{
				cout << "Enter the number to add to head: ";
				try                     // Insert data at the head of the array
				{
					getline(cin, input);
					num = stoi(input);
					break;
				}
				catch (const invalid_argument& e)
				{
					// Display error message for invalid choice
					HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hConsole, 12);
					cout << "Invalid input. Please enter an integer." << endl;
					SetConsoleTextAttribute(hConsole, 7);
				}
			}
			
			load();
			Obj.insertData(num);
			cout << "Enter any Character to goto Main menu...: ";
			cin >> x;
			cin.ignore();
			break;
		case 2:
			while (true)
			{
				cout << "Enter the number to add to the tail: ";
				try
				{
					getline(cin, input);                    // Insert data at the zero index of the array
					num = stoi(input);
					break;
				}
				catch (const invalid_argument& e)
				{
					// Display error message for invalid choice
					HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hConsole, 12);
					cout << "Invalid input. Please enter an integer." << endl;
					SetConsoleTextAttribute(hConsole, 7);
				}
			}
			
			load();
			Obj.insertAtZeroIndex(num);
			cout << "Enter any Character to goto Main menu...: ";
			cin >> x;
			cin.ignore();
			break;
		case 3:
			while (true)
			{
				cout << "Enter the number to add: ";
				try
				{
					getline(cin, input);
					num = stoi(input);
					break;
				}
				catch (const invalid_argument& e)
				{

					// Display error message for invalid choice
					HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hConsole, 12);
					cout << "Invalid input. Please enter an integer." << endl;
					SetConsoleTextAttribute(hConsole, 7);
				}
			}
			while (true)
			{
				cout << "Enter the index from 0 to " << Obj.getsize()-1 << ": ";
				try
				{
					getline(cin, input);
					index = stoi(input);
					if (index < 0 || index > Obj.getsize()-1)
					{

						// Display error message for invalid choice

						HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
						SetConsoleTextAttribute(hConsole, 12);
						cout << "Invalid Index Range." << endl;
						SetConsoleTextAttribute(hConsole, 7);
					}
					else
					{
						break;
					}
				}
				catch (const invalid_argument& e)
				{
					// Display error message for invalid choice

					HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hConsole, 12);
					cout << "Invalid input. Please enter an integer." << endl;
					SetConsoleTextAttribute(hConsole, 7);
				}
			}
			load();
			Obj.insertAtSpecificIndex(num, index);
			cout << "Enter any Character to goto Main menu...: ";
			cin >> x;
			cin.ignore();
			break;
		case 4:
			load();
			Obj.removeAtZeroIndex();
			cout << "Enter any Character to goto Main menu...: ";
			cin >> x;
			cin.ignore();
			break;
		case 5:
			load();
			Obj.removeAtLastIndex();
			cout << "Enter any Character to goto Main menu...: ";
			cin >> x;
			cin.ignore();
			break;
		case 6:
			if (Obj.getsize() > 0)
			{
				while (true)
				{
					cout << "Enter the index from 0 to " << Obj.getsize() - 1 << " to delete: ";
					try
					{
						getline(cin, input);
						index = stoi(input);
						if (index < 0 || index > Obj.getsize() - 1)
						{
							HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
							SetConsoleTextAttribute(hConsole, 12);
							cout << "Invalid Index Range." << endl;
							SetConsoleTextAttribute(hConsole, 7);
						}
						else
						{
							break;
						}
					}
					catch (const invalid_argument& e)
					{
						HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
						SetConsoleTextAttribute(hConsole, 12);
						cout << "Invalid input. Please enter an integer." << endl;
						SetConsoleTextAttribute(hConsole, 7);
					}
		        }

				load();
				Obj.removeAtIndex(index);
			}
		
			else
			{
				cout << "Array is Empty." << endl;
			}
			cout << "Enter any Character to goto Main menu...: ";
			cin >> x;
			cin.ignore();
			break;
		case 7:
			load();
			Obj.displayArray();
			cout << "Enter any Character to goto Main menu...: ";
			cin >> x; 
			cin.ignore();
			break;
		case 8:
			load();
			Obj.resize();
			cout << "Enter any Character to goto Main menu...: ";
			cin >> x;
			cin.ignore();
			break;
		case 9:
			// Exit the program
			cout << "Exiting the program. Take Care! \n";
			flag = true;
			exit(0);
			break;

		default:
			load();
			cout << "Invalid Choice! Please try again. " << endl;
			cout << "Enter any Character to goto Main menu...: ";
			cin >> x;
			cin.ignore();
			break;
		}
		system("cls");


		Sleep(600);

	}
	delete[] temp_arr;
	return 0;
}
