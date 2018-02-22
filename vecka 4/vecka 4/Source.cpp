#include <string.h>
#include <iostream>
#include "CarHandler.h"
using namespace std;

void foo(CarHandler& CarHand);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	int nrOfCars = 1;
	int CAP = 3;
	
	CarHandler ch(3);
	if(ch.addCar("volvo", 10120)== true)
	{
		cout << "succes" << endl;
	}
	if (ch.addCar("golf", 10120) == true)
	{
		cout << "succes" << endl;
	}

	foo(ch);

	ch.removeCar("volvo", 10120);
	int nr = ch.getNrOfCars();
	string* str = new string[nr];
	ch.getCarsAsString(str);
	for (int i = 0; i < nr; i++) {
		cout << str[i] << endl;
	}

	//direkt initiering ex:
	//CarHandler ch2 = ch;
	//CarHandler ch3(ch);


	// om vi har en funktion med retur typ CarHandler
	CarHandler ch4(5);

	//tilldelningsoperator INTE COPYCONTRUCTER
	ch4 = ch;


	 nr = ch.getNrOfCars();
	str = new string[nr];
	ch.getCarsAsString(str);
	for (int i = 0; i < nr; i++) {
		cout << str[i] << endl;
	}


		//cout << "Namn: " << i;


	/*for (int i = 0; i < nrOfCarHandlers; i++) {
		delete cars[i];
	}
	delete[] cars;*/
	delete[] str;
	system("pause");
	return 0;
}


void foo(CarHandler& CarHand)
{
	if (CarHand.addCar("skoda", 10120) == true)
	{
		cout << "succes" << endl;
	}else
	{
		cout << "fail" << endl;

	}
}
