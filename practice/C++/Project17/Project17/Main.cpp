#include <iostream>
#include "MyDerived.h"
using namespace std;

int main()
{
	MyDerived der;
	cout << "派生クラスのShow_MyDerivedを呼び出し\n";
	der.Show_MyDerived();

	cout << "基底クラスのShow_Dateを呼び出し\n";
	der.Show_Data();
}