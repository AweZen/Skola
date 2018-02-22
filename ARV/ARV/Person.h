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
// om en klass innehåller en rent virutell funktion blir klassen abstract och de innebär att att vi inte kan skapa
// några objekt av denna typen

//nu måste subklasserna ha en egen definition av funktionen som är rent virtuell i basklassen
