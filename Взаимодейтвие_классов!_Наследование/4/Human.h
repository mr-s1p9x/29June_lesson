#pragma once
#include<iostream>
using namespace std;
class Human
{
	char * name;
	int age;
public:
	Human();
	Human(char *, int);
	~Human();
	void Show();
};

