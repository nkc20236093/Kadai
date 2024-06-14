// Menseki.h
#pragma once
#include <iostream>
using namespace std;

class Menseki
{
	double area;
public:
	
	// �R���X�g���N�^(����1��)
	Menseki(double r) :area(r* r * 3.14) {}

	// �R���X�g���N�^(����2��)
	Menseki(double a, double b) :area(a* b) {}

	// �R���X�g���N�^(����3��)
	Menseki(double a, double b, double c) : area((a + b)* c / 2.0) {}

	inline double show() { return area; }
};