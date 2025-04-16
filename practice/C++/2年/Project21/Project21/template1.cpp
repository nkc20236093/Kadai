#include <iostream>
using namespace std;

// テンプレート関数
template<typename T> void comp(T a, T b)
{
	if (a > b)
	{
		cout << a << "は" << b << "よりも大きい\n";
	}
	else if (a < b)
	{
		cout << a << "は" << b << "よりも小さい\n";
	}
	else
	{
		cout << a << "と" << b << "は等しい\n";
	}
}

// 複数の型を使ったテンプレート関数
template<typename A,typename B>
A func(A a, B b)
{
	cout << "a = " << a << endl;
	cout << "b = " << a << endl;
	cout << "戻り値 = " << a << endl;
	return a;
}

// テンプレート関数のオーバーロード
template<typename T>
void func(T a)
{
	cout << a << endl;
}
template<typename T>
void func(T a, T b)
{
	cout << a << "," << b << endl;
}
template<typename T>
void func(T a, T b, T c)
{
	cout << a << "," << b << "," << c << endl;
}

int main()
{
	func(1.25);
	func(5, 6);
	func("ぜんため", "1日目は", "雨だった…");

#if false
	char c; int i;
	i = func(1, "abc");
	c = func('A', 12.5);

	comp(2, 3);
	comp(2.5, 0.5);
	comp('a', 'b');
	comp('s', 'S');
#endif
}