#include "dynamicArray.h"
#include <iostream>
using namespace std;

template<class T>
 dynamicArray<T>::dynamicArray(int Size)
{
	total = 0;
	this->Size = Size;
	Arr = new T[Size];
}

template<class T>
 dynamicArray<T>::~dynamicArray()
{
	delete[] Arr;
}

 template<class T>
 void dynamicArray<T>::resize()
 {
	 Size = Size * 2;
	 T* newArr = new T[Size];
	 for (int i = 0; i < total; i++)
	 {
		 newArr[i] = Arr[i];
	 }

	 delete[] Arr;
	 Arr = newArr;
 }

 template<class T>
 int dynamicArray<T>::getsize()
 {
	 return total;
 }

 template<class T>
 void dynamicArray<T>::insertData(T data)
 {
	 if (!present(data)) {
		 if (total>= Size)
		 {
			 resize();
		 }
		 Arr[total] = data;
		 total++;
		 cout << "Data inserted Successfully! \n";
	 }
	 else
	 {
		 cout << "Duplicate element! Data not inserted.\n";
	 }
 }

 template<class T>
 bool dynamicArray<T>::present(T data)
 {
	 for (int i = 0; i < total; i++)
	 {
		 if (Arr[i] == data) {
			 return true;
		 }
	 }
	 return false;
 }

 template<class T>
 void dynamicArray<T>::insertAtZeroIndex(T data)
 {
	 if (!present(data))
	 {
		 if (Size >= total) {
			 resize();
		 }
		 for (int i = total; i > 0; i--)
		 {
			 Arr[i] = Arr[i - 1];
		 }
		 Arr[0] = data;
		 total++;
		 cout << "Data inserted at zero index successfully!\n";
	 }
	 else {
		 cout << "Duplicate element! Data not inserted.\n";
	 }
	 
 }

 template<class T>
 void dynamicArray<T>::insertAtSpecificIndex(T data, int pos)
 {
	 if (!present(data) && pos >= 0 && pos <= total) {
		 if (total>= Size)
		 {
			 resize();
		 }
		 for (int i = total; i > pos; --i)
		 {
			 Arr[i] = Arr[i - 1];
		 }
		 Arr[pos] = data;
		 total++;
		 cout << "Data inserted at index " << pos << " successfully!" << endl;
	 }
	 else {
		 cout << "Invalid index or duplicate element! Data not inserted." << endl;
	 }
 }

 template<class T>
 void dynamicArray<T>::removeAtZeroIndex()
 {
	 if (total>0)
	 {
		 for (int i = 0; i < total - 1; i++) {
			 Arr[i] = Arr[i + 1];
		 }
		 total--;
		 cout << "Element at zero index removed successfully!\n" ;
	 }
	 else
	 {
		 cout << " Array is empty! No element to remove.\n ";
	 }
 }

 template<class T>
 void dynamicArray<T>::removeAtLastIndex()
 {
	 if (total>0)
	 {
		 total--;
		 cout << "Element at last index removed successfully!" <<endl;
	 }
	 else {
		 cout << "Array is empty! No element to remove.\n";
	 }
 }

 template<class T>
 void dynamicArray<T>::removeAtIndex(int pos)
 {
	 if (pos >= 0 && pos < total) {
		 for (int i = pos; i <total; i++)
		 {
			 Arr[i] = Arr[i + 1];
		 }
		 total--;
		 cout << "Element at index " << pos << " removed successfully! \n";
	 }
	 else
	 {
		 cout << "Invalid index!No element to remove.\n";
	 }

 }



 template<class T>
 void dynamicArray<T>::displayArray()
 {
	 if (total==0)
	 {
		 cout << "Array is empty" << endl;
	 }
	 else {
		 cout << "=====================================\n";
		 cout << "The total size of Array is " << total << endl;
		 cout << "=====================================\n";
		 cout << "   Current state of the array: \n";
		 for (int i = 0; i < total; i++)
		 {
			 cout << Arr[i] << " ";
		 }
		 cout << "\n";
		 cout << "=====================================\n";
	
	 }

 }

 template<class T>
 bool dynamicArray<T>::isFull()
 {
	 if (total>=Size)
	 {
		 return true;
	 }
	 return false;
 }


