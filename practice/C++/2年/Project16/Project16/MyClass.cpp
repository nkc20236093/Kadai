#include <iostream>
using namespace std;
#include "MyClass.h"

// set_a�֐���`
int MyClass::set_a()
{
	cout << "a -->";
	cin >> a;
	return 0;
}

// show_a�֐���`
int MyClass::show_a()
{
	cout << a << endl;
	return 0;
}
