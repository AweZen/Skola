#include "CarHandler.h"

void CarHandler::initiate(int from)
{
	for (int i = from;i<capacity; i++)
	{
		this->cars[i] = nullptr;
	}
} 

void CarHandler::freeMemory()
{
	for(int i = 0; i < this->nrOfCars;i++)
	{
		delete this->cars[i];
	}
	delete[] this->cars;
}

void CarHandler::makeCopy(const CarHandler& origobj)
{
	this->nrOfCars = origobj.nrOfCars;
	this->capacity = origobj.capacity;
	//deep copying regarding the array
	this->cars = new Car*[this->capacity /*funkar med origobj.capacity också*/];
	for (int i = 0; i > this->nrOfCars; i++)
	{
		//this->cars[i] = origobj.cars[i]; Så får jag inte heller göra... Kopierar pekarna så de pekar på samma carobjekt
		//
		//deep copying regarding the objects
		//we use the copy constructer in class Car
		//we dereferece the pointer
		this->cars[i] = new Car(*origobj.cars[i]);
		//ALT:  this->cars[i]=new Car(origObj.cars->getname(), --||-- ->getprice())
	}
	this->initiate(origobj.nrOfCars);
}

int CarHandler::findCar(string name, int price) const
{
	int pos = -1;
	Car temp(name, price);
		for (int i = 0; i < this->nrOfCars; i++) {
			if (temp == *this->cars[i])
				pos = i;
		}
	return pos;
}

void CarHandler::expand()
{
	this->capacity += 5;
	Car* *temp = new Car*[this->capacity];
	for (int i = 0;i < this->nrOfCars; i++)
	{
		temp[i] = this->cars[i];
	}
	delete[] this->cars;
	this->cars = temp;
	this->initiate(this->nrOfCars);
}

CarHandler::CarHandler(int capacity)
{
	this->capacity = capacity;
	this->nrOfCars = 0;
	this->cars = new Car*[this->capacity];
	this->initiate();
}

CarHandler& CarHandler::operator=(const CarHandler& origobj)
{
	//memberwise copying
//	if (this != &origobj)
	//{
	//this->cars= origobj.cars SÅ FÅR JAG INTE KOPIERA POINTERS....!!!!
		this->freeMemory();

		//this->makeCopy(origobj);
		this->capacity = origobj.capacity;
		this->nrOfCars = origobj.nrOfCars;
		this->cars = new Car*[origobj.capacity];
		for (int i= 0; i<origobj.nrOfCars;i++)
		{
			this->cars[i] = new Car(*origobj.cars[i]);
		}
		this->initiate(origobj.nrOfCars);
	//}*/
	return *this;
}

CarHandler::~CarHandler()
{
	this->freeMemory();
}

CarHandler::CarHandler(const CarHandler& origobj)
{
	//memberwise copying
	this->nrOfCars = origobj.nrOfCars;
	this->capacity = origobj.capacity;

	//this->cars= origobj.cars SÅ FÅR JAG INTE KOPIERA POINTERS....!!!!

	//deep copying regarding the array
	this->cars = new Car*[this->capacity /*funkar med origobj.capacity också*/];
	for (int i = 0 ; i > this->nrOfCars; i++)
	{
		//this->cars[i] = origobj.cars[i]; Så får jag inte heller göra... Kopierar pekarna så de pekar på samma carobjekt
		//
		//deep copying regarding the objects
		//we use the copy constructer in class Car
		//we dereferece the pointer
		this->cars[i] = new Car(*origobj.cars[i]);
		//ALT:  this->cars[i]=new Car(origObj.cars->getname(), --||-- ->getprice())
	}
	this->initiate(origobj.nrOfCars);
}

bool CarHandler::addCar(string name, int price)
{
	bool added = false;
	if (this->findCar(name, price) == -1)
	{
		if (this->nrOfCars == this->capacity)
		{
			this->expand();
		}
		
		this->cars[this->nrOfCars] = new Car(name, price); //derefererar pekare

		this->nrOfCars++;
		added = true;
	}

	return added;
}

bool CarHandler::removeCar(string name, int price)
{
	bool removed = false;
	int pos = this->findCar(name, price);
	
	if(pos != -1)
	{
		delete this->cars[pos];
		this->cars[pos] = this->cars[--this->nrOfCars];
 		removed = true;
	}
	return removed;
}

int CarHandler::getNrOfCars() const
{

	return this->nrOfCars;
}

void CarHandler::getCarsAsString(string arr[]) const
{
	for (int i = 0; i < this->nrOfCars; i++) {
		arr[i] = (*cars[i]).tostring();
	}
}

void CarHandler::saveOnFile(string fileName) const
{
}

void CarHandler::readFromFile(string fileName)
{
}
