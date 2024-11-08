#include <iostream>
#include <typeinfo>
#include <vector>
#include <algorithm>
using namespace std;

// C++11以降の機能

//autoによる型推論

int main()
{
#if false
	int i = 10;
	auto d = 3.14;
	cout << "iの型" << typeid(i).name() << endl;
	cout << "dの型" << typeid(d).name() << endl;

	vector<int> v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i * 10);
	}

	// vectorのイテレータをautoで型推論
	// vector<int>::iteratorという方は長すぎるので
	for (auto a = v.begin(); a != v.end(); ++i)
	{
		cout << *a << " ";
	}
	cout << endl;

	// 範囲ベースのfor文
	int array[10];
	int sum = 0;
	for (int i = 0; i < 10; ++i)
	{
		array[i] = 2 * i + 1; // 奇数を設定
	}

	// for(データ型：範囲)
	// 範囲やコンテナは範囲として使用可能
	for (auto i : array)
	{
		cout << i << " ";
		sum += i;
	}
	cout << " の合計は" << sum << endl;

	// ラムダ式
	// 記述方法は
	//[キャプチャ](パラメータ)->戻り値{関数本体}
	
	// 2乗を返す
	// auto f = ラムダ関数、というように宣言
	auto f = [](int x) {return x + x; };
	cout << f(10) << endl; // ラムダ関数呼び出し

	// 2つのパラメータを乗算
	// [->double]で戻り値の型を指定している。
	auto ff = [](double p, double q)->double
	{
		return p * q;
	};
	cout << ff(2.5, 0.5) << endl;

	// 文字を連結して返す
	auto s = [](string s) {return s.append("です"); };
	cout << s("C++") << endl;
#endif
	vector<int> v2;
	vector<int>::iterator s2, e;
	s2 = v2.begin();
	e = v2.end();

	// for_eachというアルゴリズム関数
	// for_each(iterator,iterator,function)
	for_each(s2, e, [](int x)
	{
		if (x % 2 == 0)
		{
			cout << "xは偶数\n";
		}
		else
		{
			cout << "xは奇数です\n";
		}
	});
	auto f = [](int x)
	{
		if (x % 2 == 0)
		{
			cout << "xは偶数\n";
		}
		else
		{
			cout << "xは奇数です\n";
		}
	};

	for_each(s2, e, f);
	// 従来の書き方はこれ
	for_each(s2, e, Function);
}

void Function(int x)
{
	if (x % 2 == 0)
	{
		cout << "xは偶数\n";
	}
	else
	{
		cout << "xは奇数です\n";
	}
}