#ifndef student_h
#define student_h
#include"person.h"
#include"SortingAlgorithms.h"
#include<string>


class student:public person
{
	//char* _name{nullptr};
	int _grade{ 0 };
public:
	student() = default;
	student(const char* name, const int& age, const int& grade);
	student(const student& st);
	student& operator=(const student& st);

	std::string returnStudentName()const;
	int returnStudentAge()const;
	int returnStudentGrade()const;
	void printInfo()const;
	friend std::istream& operator>>(std::istream &is, student& st)
	{
		getline(is,st._name,' ');
		if(st._name[0]=='\n')
			st._name.erase(0, 1);
		is >> st._age >> st._grade;
		return is;
	}
};
#endif