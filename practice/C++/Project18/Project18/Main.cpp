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

#endif

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


#endif

}