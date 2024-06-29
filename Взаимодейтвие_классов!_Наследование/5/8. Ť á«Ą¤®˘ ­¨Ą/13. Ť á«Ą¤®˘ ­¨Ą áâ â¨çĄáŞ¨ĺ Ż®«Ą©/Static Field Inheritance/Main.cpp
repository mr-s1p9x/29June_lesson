#include <iostream>
#include "Foo.h"
#include "Bar.h"

using namespace std;

void main()
{	
	cout << Foo::fooStatic << endl;
	Foo::fooStatic++;
	cout << Bar::fooStatic << endl;
}