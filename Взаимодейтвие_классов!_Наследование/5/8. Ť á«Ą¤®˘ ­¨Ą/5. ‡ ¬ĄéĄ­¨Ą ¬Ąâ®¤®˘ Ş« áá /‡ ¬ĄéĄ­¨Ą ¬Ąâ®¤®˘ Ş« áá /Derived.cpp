#include "Derived.h"

#include <iostream>

using namespace std;

void Derived::Set(const int valueDerived)
{
	cout << "Derived Set\n";
    m_fieldDerived = valueDerived;
}

void Derived::Show() const
{
    cout << m_fieldDerived << endl;
}