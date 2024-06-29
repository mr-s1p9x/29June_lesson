#include "Base.h"

#include <iostream>

using namespace std;

void Base::Set()
{
	cout << "Base Set\n";
    m_fieldBase = 10;
}

void Base::Show() const
{
    cout << m_fieldBase << endl;
}