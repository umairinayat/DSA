
#include <iostream>

using namespace std;

 class Node {
public:
    int data;
    Node* next;
     Node(int value) {
        data = value;
        next = nullptr;
    }
};
 class CircularLinkedList {
private:
    Node* tail;
 public:
    CircularLinkedList() {
        tail = nullptr;
    }
     void pushBack(int value) {
        Node* newNode = new Node(value);
         if (tail == nullptr) {
            tail = newNode;
            tail->next = tail;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
    }
     int popBack() {
        if (tail == nullptr) {
            cout << "List is empty. Cannot pop element.\n";
            return -1; // Assuming -1 represents an empty list or invalid value
        }
         int poppedValue;
        if (tail->next == tail) {
            poppedValue = tail->data;
            delete tail;
            tail = nullptr;
        } else {
            Node* current = tail->next;
            while (current->next != tail) {
                current = current->next;
            }
            poppedValue = tail->data;
            current->next = tail->next;
            delete tail;
            tail = current;
        }
         return poppedValue;
    }
     bool search(int value) {
        if (tail == nullptr) {
            return false; // List is empty
        }
         Node* current = tail->next;
        do {
            if (current->data == value) {
                return true; // Value found
            }
            current = current->next;
        } while (current != tail->next);
         return false; // Value not found
    }
};
 int main() {
    CircularLinkedList myList;
     // Pushing elements to the back
    myList.pushBack(10);
    myList.pushBack(20);
    myList.pushBack(30);
     // Searching for a value
    int searchValue = 20;
    if (myList.search(searchValue)) {
        cout << "Value " << searchValue << " found in the list.\n";
    } else {
        cout << "Value " << searchValue << " not found in the list.\n";
    }
     // Popping elements from the back
    int poppedValue = myList.popBack();
    cout << "Popped value: " << poppedValue << "\n";
     return 0;
}
