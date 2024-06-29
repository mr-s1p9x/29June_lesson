#include "Student.h"



Student::Student():vuz(nullptr)
{
}
Student::Student(char * v)
{

	vuz = new char[strlen(v) + 1];
	strcpy_s(vuz, strlen(v) + 1, v);

}

Student::~Student()
{

	if (vuz != nullptr)
	{
		delete[] vuz;
	}
}

void Student::Show()
{
	cout << "Vuz: " << vuz << endl;
}