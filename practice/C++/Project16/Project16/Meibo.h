#pragma once
#include <iostream>
#include <string>
using namespace std;

class Meibo
{
	string name;			// 名前
	double bw;				// 体重
	double bl;				// 身長
	static int No_of_obj;	// 名簿クラスの数
public:
	static double bw_total;	// 静的データメンバ
	static double bl_total; // 静的データメンバ

	void SetData();

	Meibo();				// コンストラクタ
	static void GetMean();	// 静的メンバ関数
};
