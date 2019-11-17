#include<iostream>
#include"student.h"

student::student(const char* name, const int& age, const int& grade)
{
	_name = name;
	_age = age;
	//std::cout << strlen(name) << std::endl;
	//strcpy(_name, name);
	_grade = grade;
}

student::student(const student& st)
{
	_name = st._name;
	_age = st._age;
	_grade = st._grade;
}

student& student::operator=(const student& st)
{
	if (this != &st)
	{
		_name = st._name;
		_age = st._age;
		_grade = st._grade;
	}
	return *this;
}

std::string student::returnStudentName()const
{
	return _name;
}

int student::returnStudentAge()const
{
	return _age;
}

int student::returnStudentGrade()const
{
	return _grade;
}

void student::printInfo()const
{
	std::cout<<"The Grade Point Average of " << _name.c_str() << " is " << _grade << ".\n";
}