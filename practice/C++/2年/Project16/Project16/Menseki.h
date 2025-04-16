// Menseki.h
#pragma once
#include <iostream>
using namespace std;

class Menseki
{
	double area;
public:
	
	// コンストラクタ(引数1つ)
	Menseki(double r) :area(r* r * 3.14) {}

	// コンストラクタ(引数2つ)
	Menseki(double a, double b) :area(a* b) {}

	// コンストラクタ(引数3つ)
	Menseki(double a, double b, double c) : area((a + b)* c / 2.0) {}

	inline double show() { return area; }
};