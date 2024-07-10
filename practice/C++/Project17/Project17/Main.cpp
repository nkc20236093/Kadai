#include <iostream>
#include "MyDerived.h"
using namespace std;

// 抽象クラス
// 純粋仮想関数を持つクラス、抽象クラスという
// 抽象クラスは実体を持つことができない
class Date 
{
protected:
	double x, y;
public:
	// 純粋仮想関数は中身を書かないので = 0; と書く。
	// 純粋仮想関数は必ずオーバーライドしないといけない
	virtual double SetValue(double a, double b) = 0;
	virtual void GetValue(double* a, double* b) = 0;
};

class DateA :public Date
{
public:
	// 純粋仮想関数のオーバーライド
	double SetValue(double a, double b) { x = a, y = b; }
	void GetValue(double* a, double* b) { *a = x, * b = y; }
};

// 基底クラス
class GameObject
{
public:
	// 仮想関数
	// 継承して使う前提
	// 子供がShow関数を持っていた場合は
	// 子供のShow関数を使ってくれる便利なやつ

	virtual void Show()
	{
		cout << "GameObject\n";
	}
};

// ゲームオブジェクトを継承したプレイヤークラス
class Player :public GameObject
{
public:
	void Show()
	{
		cout << "Player\n";
	}
};

// ゲームオブジェクトを継承した敵クラス
class Enemy :public GameObject
{
	void Show()
	{
		cout << "Enemy\n";
	}
};

// 仮想関数と抽象クラス
class A
{
public:
	void Show() 
	{
		cout << "基本クラスの関数\n"; 
	}
};

class B :public A
{
public:
	int x;
	B() : x(100) {}
	void Show()
	{
		cout << "派生クラスの関数\n";
	}
};

int main()
{
#if false
	{
		MyDerived der;
		cout << "派生クラスのShow_MyDerivedを呼び出し\n";
		der.Show_MyDerived();

		cout << "基底クラスのShow_Dateを呼び出し\n";
		der.Show_Data();
	}
	{
		B child;
		// Show関数は派生クラスのBが呼び出される
		// これを関数のオバーライドと言う
		child.Show();
		// 基本クラス(A)のShow関数を呼ぶときは、
		// スコープ解決演算子を使う
		child.A::Show();

		// ポインタを使った関数呼び出し
		A* pBase;	// Aクラスのポインタ(実体はない)
		B derived;	// Bの実体
		// 基本クラスのポインタに派生クラスのアドレスを代入
		pBase = &derived;

		// ポインタが指すShow関数を実行
		pBase->Show();

		// 親のポインタから、無理やり子供の関数を呼ぶ
		// pBaseを子供のポインタに変換した後に関数を呼ぶと出来る
		static_cast<B*>(pBase)->Show();

		// 親のポインタから子供の持つ変数xにはアクセスはできない
		// アクセスする際は子供のポインタに変換してからやる
		// pBase->x = 0; ←これはできない
		static_cast<B*>(pBase)->x = 0;
	}
	{
		GameObject* pObj;
		Player pl;
		Enemy em;

		// 親クラスのポインタを使って子供クラスの関数を呼び出し
		// 子供のアドレスを親のポインタに変換することをアップキャストという
		// 親のアドレスを子供のポインタに変換することをダウンキャストという
		pObj = &pl;
		pObj->Show();

		pObj = &em;
		pObj->Show();

		GameObject* ptrTable[] =
		{
			&pl,&em
		};
		int length = sizeof(ptrTable) / sizeof(int);
		for (int i = 0; i < length; i++)
		{
			ptrTable[i]->Show();
		}
	}
	#endif
}