#pragma once
#include "MyBase.h";

// MyBase�N���X���p������h���N���X
// �p������ۂɂ̓A�N�Z�X�w��q���K�v
// protected�͌p���Ŏg���A�N�Z�X�w��q��
// �O������̓A�N�Z�X�ł��Ȃ����A�p����ł̓A�N�Z�X�ł���
class MyDerived :public MyBase
{
	int d;
public:
	void Show_MyDerived();
	MyDerived();
	~MyDerived();
};