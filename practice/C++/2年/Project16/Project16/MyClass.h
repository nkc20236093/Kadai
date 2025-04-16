// MyClass.h
#pragma once

// 231p クラスの使用例
class MyClass
{
	// 非公開部
private:
	int a;
	// 公開部
public:
	int b;
	int set_a();   // 関数宣言のみ
	int show_a();  // 関数宣言のみ

	// インライン関数
	// インライン関数にすると、コンパイル時に関数の中身が展開され
	// 関数呼び出しの処理がなくなり、処理が軽くなる
	inline int add(int a, int b) { return a + b; }
};

