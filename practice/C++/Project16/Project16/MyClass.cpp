#include <iostream>
using namespace std;
#include "MyClass.h"

// set_a関数定義
int MyClass::set_a()
{
	cout << "a -->";
	cin >> a;
	return 0;
}

// show_a関数定義
int MyClass::show_a()
{
	cout << a << endl;
	return 0;
}
