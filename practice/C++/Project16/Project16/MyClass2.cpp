#include <iostream>
#include "MyClass2.h"
using namespace std;

// コンストラクタ定義
MyClass2::MyClass2(int m, int n) :x(m), y(n), px(&x) {}

// デストラクタ定義
MyClass2::~MyClass2()
{
	cout << "デストラクタ呼び出し\n";
}

// コピーコンストラクタ定義
// xの値はコピー、yの値は0に
// ポインタのコピーはせず、設定しなおす
MyClass2::MyClass2(const MyClass2& other) :x(other.x), y(0), px(&x) {}

int MyClass2::show()
{
	cout << "x = " << x << " , ";
	cout << "y = " << y << " , ";
	cout << "px = " << px << endl;
	return 0;
}