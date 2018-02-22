#ifndef CAR_H
#define CAR_H
#include <string>
#include <iostream>
using namespace std;

class Car
{
private:
	string name;
	int price;
public:
	Car(string name="N/A", int price = -1);
	~Car();
	string getName()const;
	int getPrice()const;
	void setName(string name);
	void setPrice(int price);
	string tostring()const;
	bool operator==(Car compObj) const;
};

#endif