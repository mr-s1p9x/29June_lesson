#include "Aspirant.h"



Aspirant::Aspirant():diplom(nullptr)
{
}


Aspirant::~Aspirant()
{
	if (diplom != nullptr)
	{
		delete[] diplom;
	}
}
void Aspirant::Show()
{
	Human::Show();
	Student::Show();
	cout << "Diplom: " << diplom << endl<<endl;
}
Aspirant::Aspirant(char * n,int a,char *v,char * d):Human(n,a), Student(v)
{
	diplom = new char[strlen(d) + 1];
	strcpy_s(diplom, strlen(d) + 1, d);
}