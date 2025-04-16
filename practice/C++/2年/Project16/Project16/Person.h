// Person.h
#pragma once
#include <string>

class Person
{
	// アクセス指定子がない場合はprivateになる
	std::string name;
	int age;
	char sex;
public:
	// 関数宣言
	// クラス名と同じ名前の関数をコンストラクタと呼ぶ
	// コンストラクタには戻り値はない
	Person(const std::string&, int, char);
	int Show();
};
