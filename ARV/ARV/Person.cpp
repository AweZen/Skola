#include "Person.h"

Person::Person(string name, string mail)
{
	this->name = name;
	this->mail = mail;
}

Person::Person(const Person & origObj)
{
	this->name = origObj.name;
	this->mail = origObj.mail;
}

Person::~Person()
{
}

Person& Person::operator=(const Person & origObj)
{
	if (this!= &origObj)
	{
		this->name = origObj.name;
		this->mail = origObj.mail;
		
	}
	return *this;
}

string Person::toString()const
{
	return "Name: " + this->name + "\nMail: " + this->mail + toStringSpecific();
}

string Person::getName() const
{
	return this->name;
}

string Person::getMail() const
{
	return this->mail;
}
