#include <iostream>
#include "MyBase.h";

MyBase::MyBase() : a(10), b(20), c(30) 
{
	std::cout << "MyBase�̃R���X�g���N�^\n";
}

MyBase::~MyBase()
{
	std::cout << "MyBase�̃f�X�X�g���N�^\n";
}

void MyBase::Show_Data()
{
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
}
