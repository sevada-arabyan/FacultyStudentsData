#include<iostream>
#include"student.h"
#include<string>

void sortStudentsArray(student*, const int&);

int main()
{

	/*const char* name{ "Sevada" };
	std::cout << strlen(name) << std::endl;*/

	student std{ "Sevada", 29, 48 };
	std.printInfo();
	std::cout << std.returnStudentName().c_str() << std::endl;
	//char* ch{ std.returnStudentName() };
	//std::cout << ch << std::endl;

	const int size{ 3 };
	student* arr = new student[size];

	for (int i{ 0 }; i < size; i++)
	{
		std::cin >> arr[i];
	}
	for (int i{ 0 }; i < size; i++)
	{
		arr[i].printInfo();
	}
	sortStudentsArray(arr, size);
	for (int i{ 0 }; i < size; i++)
	{
		arr[i].printInfo();
	}
	system("pause");
	return EXIT_SUCCESS;
}

void sortStudentsArray(student* arr, const int& size)
{
	int j;
	student key;
	for (int i{ 1 }; i < size; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j].returnStudentAge()>key.returnStudentAge())
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}