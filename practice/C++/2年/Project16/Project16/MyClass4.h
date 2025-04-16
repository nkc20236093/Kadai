#pragma once


class MyClass4
{
	int x;
public:
	// デフォルトコンストラクタ
	MyClass4() :x(100) {}
	// show関数は多重定義
	int Show();
	int Show(int a);
};