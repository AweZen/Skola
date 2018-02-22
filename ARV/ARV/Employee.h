#pragma once
#include <string>
#include <iostream>
#include "Person.h"

using namespace std;

class Employee: public Person
{
private:
	string department;
	int salery;
public:
	Employee(string name, string mail, string department, int salery);
	virtual~Employee();
	string toStringSpecific()const;
	string getDepartment()const;
	int getSalery()const;
	Employee* clone()const;
};
