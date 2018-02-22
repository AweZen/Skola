#include "Employee.h"

Employee::Employee(string name, string mail, string department, int salery)
	:Person(name, mail)
{	
	this->department = department;
	this->salery = salery;
	this->department;
}
Employee::~Employee()
{
}
string Employee::toStringSpecific()const
{
	return "\nDepartment: " + this->department + "\nSallery: " + to_string(this->salery)+ "\n";
}

string Employee::getDepartment() const
{
	return this->department;
}

int Employee::getSalery() const
{
	return this->salery;
}

Employee * Employee::clone()const
{
	return new Employee(*this);
}

