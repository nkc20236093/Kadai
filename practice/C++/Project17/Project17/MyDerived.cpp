#include "MyDerived.h"
#include <iostream>
using namespace std;

// 派生クラスのコンストラクタ
// 親のコンストラクタが実行されている
// (省略されてあるとデフォルトコンストラクタが呼び出される)
MyDerived::MyDerived() : d(400)
{
	cout << "派生クラスのコンストラクタ\n";
	// a = 100; privateなので無理
	b = 200; // 初期化リストでは初期化できないので代入
	c = 300; // 初期化リストでは初期化できないので代入
}

MyDerived::~MyDerived()
{
	cout << "派生クラスのデストラクタ\n";
}

void MyDerived::Show_MyDerived()
{
	// cout << "a  " << b << endl; ※privateなので無理
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;
}