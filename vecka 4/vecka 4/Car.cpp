#include "Car.h"

Car::Car(string name, int price)
{
	this->name = name;
	this->price = price;
}

Car::~Car()
{
}

string Car::getName()const
{

	return this->name;
}

int Car::getPrice()const
{
	return this->price;
}

void Car::setName(string name)
{
	this->name = name;
}

void Car::setPrice(int price)
{
	this->price = price;
}

string Car::tostring() const
{
	return "Name of car: " + getName() + "\nPrice: " + to_string(getPrice());
}
bool Car::operator==(Car compObj) const
{
	return this->name == compObj.name && this->price == compObj.price;
}