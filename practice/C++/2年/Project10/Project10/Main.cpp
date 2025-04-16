#include <iostream>
using namespace std;

// 関数(値渡し)
void func1(int a) { a = 100; }

// ポインタ
void func2(int* pa) 
{
	*pa = 100;
}

int main()
{
	int x = 0;
	func1(x);	// func1呼び出し
	cout << "xの値は" << x << "です\n";

	func2(&x);	// func2呼び出し
	cout << "xの値は" << x << "です\n";
}