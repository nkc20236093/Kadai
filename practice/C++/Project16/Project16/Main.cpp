#include <iostream>
#include "MyClass.h"
#include "BMI.h"
using namespace std;

// クラスとは
// データ、関数などをまとめた型
// ユーザーが自由に作成できるユーザー定義型

class Human 
{
	// アクセス指定子：非公開
private:
	// データメンバ（メンバ変数）
	int age;
	string gender;
	// ここまで非公開
	// アクセス指定子：公開
	void DispPlay() 
	{
		cout << "表示します\n";
	}
	// ここまで公開
};

int main()
{
#if false
	// クラスの実体（インスタンス）作成
	MyClass mc{};

	// bは公開部なので、アクセス可能
	mc.b = 100;
	cout << "b = " << mc.b << endl;

	// aは非公開なのでアクセスできない
	//mc.a = 100;

	// 公開のset_a()を使用し、非公開のaの値を設定
	mc.set_a();
	// 公開のshow_a()を使用し、非公開のaの値を表示
	mc.show_a();
#endif

	BMI b{};
	b.SetData();
	b.ShowBMI();
	return 0;
}