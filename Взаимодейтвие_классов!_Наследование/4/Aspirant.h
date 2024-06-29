#pragma once
#include "Human.h"
#include "Student.h"

class Aspirant :public Human, public Student
{
	char * diplom;
public:
	Aspirant();
	Aspirant(char *n,int,char *,char *);
	~Aspirant();
	void Show();
	
};

