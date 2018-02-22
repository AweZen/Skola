#ifndef CARHANDLER_H
#define CARHANDLER_H
#include <string>
#include <iostream>
#include "Car.h"

using namespace std;

class CarHandler
{
private:
	Car* *cars;
	int nrOfCars;
	int capacity;
	void initiate(int from = 0);
	void freeMemory();
	void makeCopy(const CarHandler& origobj);
	int findCar(string name, int price)const;
	void expand();
public:
	CarHandler(int capacity = 3);
	//copy construkt
	CarHandler(const CarHandler& origobj);
	//tilldelningsoperator
	CarHandler& operator=(const CarHandler& origobj);
	~CarHandler();
	bool addCar(string name, int price);  
	bool removeCar(string name, int price); 
	int getNrOfCars() const;
	void getCarsAsString(string arr[])const;
	void saveOnFile(string fileName) const;
	void readFromFile(string fileName);
};

#endif