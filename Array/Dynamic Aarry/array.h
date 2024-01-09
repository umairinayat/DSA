#pragma once
//#using namespace std;
template<class T>
class dynamicArray
{
private:
	T* Arr;
	int total;
	int Size;
public:
	dynamicArray(int Size);
	void resize();
	int getsize();
	void insertData(T data);
	bool present(T data);
	void insertAtZeroIndex(T data);
	void insertAtSpecificIndex(T data, int pos);
	void removeAtZeroIndex();
	void removeAtLastIndex();
	void removeAtIndex(int pos);
	void displayArray();
	bool isFull();
	~dynamicArray();
};
