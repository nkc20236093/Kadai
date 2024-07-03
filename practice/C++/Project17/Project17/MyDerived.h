#pragma once
#include "MyBase.h";

// MyBaseクラスを継承する派生クラス
// 継承する際にはアクセス指定子が必要
// protectedは継承で使うアクセス指定子で
// 外部からはアクセスできないが、継承先ではアクセスできる
class MyDerived :public MyBase
{
	int d;
public:
	void Show_MyDerived();
	MyDerived();
	~MyDerived();
};