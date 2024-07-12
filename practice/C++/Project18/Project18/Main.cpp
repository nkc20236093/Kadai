#include <iostream>
using namespace std;

#if false
// フレンド関数、フレンドクラスについて

class  A
{
	int x;
public:
	A() :x(0) {}
	A(int n) :x(n) {}
	void Show()
	{
		cout << "x = " << x << endl;
	};
	// フレンド関数
	// メンバ関数ではない
	friend void FShow(A a);
};

class B :public A
{
	int x;
public:
	B() :x(1000) {}
	void Show()
	{
		cout << "x = " << x << endl;
	};
};
// フレンド関数の実装
// 非公開メンバにアクセスできる
void FShow(A a)
{
	cout << "x = " << a.x << endl;
};

// 前方宣言(中身はあとで書くやつ)
class Dog;
class Cat;

class Cat
{
	string voice;
public:
	Cat() : voice("にゃー") {}
	friend void GetVoice(Cat tama, Dog pochi);
};
class Dog
{
	string voice;
public:
	Dog() :voice("ワンワン") {}
	friend void GetVoice(Cat tama, Dog pochi);
};
// フレンド関数の実装
void GetVoice(Cat tama, Dog pochi)
{
	cout << "猫は" << tama.voice << endl;
	cout << "犬は" << pochi.voice << endl;
};
class A2
{
	int x;
public:
	A2() :x(10) {}
	friend class B2;
};
class B2
{
public:
	void Func(A2 a)
	{
		// AがBをフレンドクラスとしているので
		// BはAの非公開部にアクセスできる
		a.x = 0;
	};
};
class C :public B2
{
public:
	// 親が持つpublicのfuncにはアクセスできるので
	// 結果的にAの値を変更できる
	void Func2(A2 a)
	{
		// a.x = 0;	// 友達じゃないので変更できない
		Func(a);	// 親は友達なんで、親の力
	};
};

// 多重継承
class B3_1
{
	int x;
public:
	B3_1() :x(10) {}
	void ShowB3_1()
	{
		cout << "x = " << x << endl;
	};
};
class B3_2
{
	int y;
public:
	B3_2() :y(20) {};
	void ShowB3_2()
	{
		cout << "y = " << y << endl;
	};
};
// B3_1とB3_2を多重継承
class C2 :public B3_1, public B3_2
{
	int d;
public:
	C2() :d(30) {}
	void ShowC2()
	{
		cout << "d = " << d << endl;
	};
};

// ひし形継承
class B4_1
{
protected:
	int x;
public:
	void ShowX()
	{
		cout << "x = " << x << endl;
	}
	B4_1() :x(10)
	{
		cout << "B4_1のコンストラクタ\n";
		cout << "xを10に設定\n";
	};
};
class B4_2 :virtual public B4_1
{
public:
	B4_2()
	{
		cout << "B4_2のコンストラクタ\n";
		x = 100;
		cout << "xを100に設定\n";
	};
};
class B4_3 :virtual public B4_1
{
public:
	B4_3()
	{
		cout << "B4_3のコンストラクタ\n";
		x = 200;
		cout << "xを200に設定\n";
	};
};
// B4_2、B4_3ひし形継承したC3
class C3 :public B4_2, public B4_3
{
public:
	void Show()
	{
		cout << "クラスC3のShow関数でxを表示:" << x << endl;
	};
};
#endif
int main()
{
#if false
	A Obj1(10), Obj2;
	Obj1.Show();
	FShow(Obj1);
	Obj2.Show();
	FShow(Obj2);

	B b;
	// Bのxを表示
	b.Show();
	// Aのフレンド関数を実行
	FShow(b);

	Cat a;
	Dog b;
	// フレンド関数呼び出し
	GetVoice(a, b);

	// 実体作成
	C2 der;
	der.ShowB3_1();	// B3_1のメンバ関数
	der.ShowB3_2();	// B3_2のメンバ関数
	der.ShowC2();	// C2のメンバ関数

	// 親に同じ名前の関数がある時は
	// スコープ解決演算子を使う
	der.B3_1::ShowB3_1();
	der.B3_2::ShowB3_2();

	C3 c3;
	c3.Show();
#endif
}