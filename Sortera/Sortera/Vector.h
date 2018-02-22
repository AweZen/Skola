#ifndef VECTOR_H
#define VECTOR_H

#include <string>
template<typename T>
class Vector
{
private:
	T * items;
	int capacity;
	int nrOfItems;
	int capacityIncrement;
public:
	Vector(int capacity = 10, int capacityIncrement = 10);
	void addLast(T item);
	void addFirst(T item);
	void addAt(T item, int at)throw(...);
	T getFirst() const throw(...);
	T getLast()const throw(...);
	T getAt(int index)const throw(...);
	T removeFirst()throw(...);
	T removeLast()throw(...);
	T removeAt()throw(...);
	void removeBetween()throw(...);
};

template<typename T>
Vector<T>::Vector(int capacity, int capacityIncrement)
{
	this->nrOfItems = 0;
	this->capacity = capacity;
	this->capacityIncrement = capacityIncrement;
	this->items = new T[this->capacity];
}

template<typename T>
void Vector<T>::addLast(T item)
{
	if(this->nrOfItems == this->capacity)
	{
		//expand();
	}
	this->items[nrOfItems++] = item;
}

template<typename T>
void Vector<T>::addFirst(T item)
{
	if (this->nrOfItems == this->capacity)
	{
		//expand();
	}
	T* temp = new T [this->capacity];
	temp[0] = item;
	for (int i = 1; i< nrOfItems-1;i++)
	{
		temp[i] = this->items[i + 1];

	}
	nrOfItems++;
	this->items = temp;
	delete temp;
}

template<typename T>
void Vector<T>::addAt(T item, int index)
{
	if (this->nrOfItems == this->capacity)
	{
		//expand();
	}
	T* temp = new T[this->capacity];
	int j = 0;
	for (int i = 0; i< nrOfItems; i++)
	{
		if(i == index)
		{
			temp[i] = item;
		}
		else {
			temp[i] = this->items[j];
			j++;
		}
	}
	this->items = temp;
}

template<typename T>
T Vector<T>::getFirst()const throw(...)
{
	if (this->nrOfItems == 0)
	{
		std::string test = "Error getting first.";
		 throw test;
	}
	return this->items[0];
}

template<typename T>
T Vector<T>::getLast()const
{
	return items[nrOfItems];
}

template<typename T>
T Vector<T>::getAt(int at)const {
	return this->items[at];
}
#endif
