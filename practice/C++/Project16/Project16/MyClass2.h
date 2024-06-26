#pragma once

class MyClass2
{
	int x, y;
	int* px;
public:
	// 引数ありコンストラクタ
	MyClass2(int m, int n);
	// コピーコンストラクタ
	MyClass2(const MyClass2& other);
	// デストラクタ
	// クラス名に~を付けた名前を持ち、引数は無し
	~MyClass2();
	// メンバ関数
	int show();
};
