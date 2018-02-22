#include "Student.h"

Student::Student(string name, string mail, string studyprogram)
	:Person(name, mail)
{
	this->studyprogram = studyprogram;
}

Student::Student(const Student &origobj)
	:Person(origobj)
{
	this->studyprogram = origobj.studyprogram;
}

Student::~Student()
{
}

Student & Student::operator=(const Student & origObj)
{
	if (this!= &origObj)
	{
		Person::operator=(origObj);
		this->studyprogram = origObj.studyprogram;
	}
	return *this;
}

string Student::toStringSpecific()const
{
	return "\nStudyprogram: " + this->studyprogram +"\n";
}

Student * Student::clone() const
{
	return new Student(*this);
}

string Student::getStudyProgram()const
{
	return this->studyprogram;
}
