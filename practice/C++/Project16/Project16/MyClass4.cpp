#include "MyClass4.h"
#include <iostream>
using namespace std;

int MyClass4::Show()
{
	cout << "x = " << x << endl;
	return 0;
}
int MyClass4::Show(int a)
{
	cout << "引数付きのShow関数が呼び出されました\n";
	cout << "受けとった数値は" << a << "です\n";
	return 0;
}
