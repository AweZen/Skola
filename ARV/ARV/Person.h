#pragma once
#include <string>
#include <iostream>


using namespace std;

class Person
{

private:
	string name;
	string mail;
public:
	Person(string name, string mail);
	Person(const Person &origObj);
	virtual~Person();
	Person& operator=(const Person &origObj);
	string toString()const;
	virtual Person* clone()const = 0;
	virtual string toStringSpecific()const = 0; // rent virutell kommer aldrig kallas tack vare  = 0;
	string getName()const;
	string getMail()const;
};
// om en klass inneh�ller en rent virutell funktion blir klassen abstract och de inneb�r att att vi inte kan skapa
// n�gra objekt av denna typen

//nu m�ste subklasserna ha en egen definition av funktionen som �r rent virtuell i basklassen
