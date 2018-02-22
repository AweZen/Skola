#include <string.h>
#include <iostream>
#include <ctime>
#include "dice.h"
using namespace std;
	
int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//memleak

	//int value;
	//int i;
	//int times;
	srand(static_cast<unsigned int>(time(0)));

	Dice d1(20); 
	//Dice d2(17); //skapar dice med 17 sidor

	/*cout << "how many times do you want to roll the dice?" << endl;
	cin >> times;

	for (i = 0; i < times; i++)
	{
		d1.toss();
		value = d1.getValue();
		cout << value << endl;
		
	}*/

	Dice* d3 = nullptr;
	d3 = new Dice(d1.getValue());
	Dice* d4 = new Dice();

	cout << d3->getNrOfFaces() << endl;
	
	//d3 = d4;
	//cout << d3->getNrOfFaces() << endl;

	d4->toss();
	(*d4).toss(); //onödigt men bra att kunna inför framtiden



	delete d3;
	delete d4;


	/////////////////////////////////////
/*
	Dice* d11;
	Dice* d12 = nullptr;
	Dice* d13 = new Dice(9);
	Dice* d14 = new Dice[3]; //dymanisk array
	Dice* d15[4] = { nullptr }; //statisk array 
	//av pekare som pekar till okänt
	for (int i; i < 4; i++) {
		d15[i] = new Dice(8); //ger alla dices 8sidor
		//objekt dynamiska men statisk array
	} */

///////////////////////////////////////////////////////
	// Dynamiskt allokerad array innehållande Dice-pekare
	int nrOfDices = 0;
	int capacity = 3;

	Dice* *dices = nullptr;
	dices = new Dice*[capacity];
	for (int i = 0; i < capacity; i++) {
		dices[i] = nullptr;
	}
	dices[nrOfDices++] = new Dice(11);
	dices[0]->toss();

	for (int i = 0; i < nrOfDices; i++) {
		delete dices[i];
	}
	delete[] dices;

	system("pause");
	return 0;
}