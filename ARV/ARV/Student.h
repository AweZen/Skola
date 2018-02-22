#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <iostream>
#include "Person.h"



using namespace std;

class Student: public Person
{
private:
	string studyprogram;
public:
	Student(string name, string mail,string studyprogram);
	Student(const Student &origobj);
	virtual~Student();
	Student& operator=(const Student &origObj);
	string toStringSpecific()const;
	Student* clone()const;
	string getStudyProgram()const;

};

#endif