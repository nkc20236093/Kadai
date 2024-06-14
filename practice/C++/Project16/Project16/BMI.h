#pragma once
class BMI
{
private:
	double bw;	// 体重
	double bl;	// 身長
	double bmi; // BMI
public:
	// 関数宣言
	int SetData(); // 身長・体重を設定する
	int ShowBMI(); // 表示する
};