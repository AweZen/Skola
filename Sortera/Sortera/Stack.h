#pragma once
#include "IStack.h"
template<typename T>
class Stack: public IStack<T>
{
private:
	T * stack;
	int capacity;
	int nrOfItems;
	int capacityIncrement;
	void expand();
public:
	Stack(int capacity = 5, int capacityIncrement = 10);
	Stack(const Stack& origobj);
	Stack& operator=(const Stack<T>& origobj);
	virtual ~Stack();
	void push(const T& element);
	T pop() throw(...);
	T peek()const throw(...);
	bool isEmpty()const;
};

template<typename T>
void Stack<T>::expand()
{
}

template<typename T>
Stack<T>::Stack(int capacity, int capacityIncrement)
{
	this->nrOfItems = 0;
	this->capacity = capacity;
	this->capacityIncrement = capacityIncrement;
	this->stack = new T[this->capacity];
}

template<typename T>
Stack<T>::Stack(const Stack & origObj)
{
	this->nrOfItems = origObj.nrOfItems;
	this->capacity = origObj.capacity;
	this->capacityIncrement = origObj.capacityIncrement;
	this->stack = new T[this->capacity];
	for (int i = 0; i < this->nrOfItems) {
		this->stack[i] = origObj.stack[i];

	}
}

template<typename T>
Stack<T> & Stack<T>::operator=(const Stack<T> & origobj)
{
		this->nrOfItems = origObj.nrOfItems;
		this->capacity = origObj.capacity;
		this->capacityIncrement = origObj.capacityIncrement;
		this->stack = new T[this->capacity];
		for (int i = 0; i < this->nrOfItems) {
			this->stack[i] = origObj.stack[i];

		}
	return this
}




template<typename T>
Stack<T>::~Stack()
{
	delete[] stack;
}

template<typename T>
void Stack<T>::push(const T & element)
{
	if (this->nrOfItems == this->capacity)
	{
		//expand();
	}
	this->stack[this->nrOfItems++] = element;
}

template<typename T>
T Stack<T>::pop() throw(...)
{
	if (this->nrOfItems == 0)
	{
		std::string test = "Error. No more items.";
		throw test;
	}
	return stack[--this->nrOfItems];
}

template<typename T>
T Stack<T>::peek() const throw(...)
{
	if (this->nrOfItems == 0)
	{
		std::string test = "Error. No more items.";
		throw test;
	}
	return stack[this->nrOfItems-1];
}

template<typename T>
bool Stack<T>::isEmpty() const
{
	if (this->nrOfItems == 0) {
		return true;
	}
	else {
		return false;
	}
}
