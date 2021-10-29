//code included from my shitty stack lab 9 array, used for my search implementation, could change to be linked list or vector or something
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

template <class T>
class Stack
{
public:
	Stack(int newSize = 0);
	~Stack();

	bool push(T& newItem);
	bool pop(T& poppedItem);
	
	bool isEmpty();

private:
	int mSize; // represents the current number of items in the stack
	int mMaxSize; // must not exceed the max size of our allocated array
	T* mTop; // will point to contigous memory on the heap (an array)
};


template <class T>
Stack<T>::Stack(int newSize)
{
	mSize = newSize; // this can also be used as the index to the top of the stack
	mMaxSize = 100;
	mTop = new T[100]; // allocating an array of 100 items of type T on the heap// assuming mTop[0] is bottom node of stack
}
template <class T>
Stack<T>::~Stack()
{
	delete[] mTop; // this is how we free up an array on the heap in C++
}

template <class T>
bool Stack<T>::pop(T& poppedItem)
{
	if (~isEmpty())
	{
		poppedItem = mTop[mSize - 1];


		mTop[mSize - 1] = NULL;
		mSize--;

		return true;
	}

	return false;

}


template <class T>
bool Stack<T>::push(T& newItem)
{
	mTop[mSize] = newItem;
	mSize++;
	return true;
	
}

template <class T>
bool Stack<T>::isEmpty()
{
	if (mSize == 0)
	{
		return true;
	}
	return false;
}


