#include "MyDerived.h"
#include <iostream>
using namespace std;

// �h���N���X�̃R���X�g���N�^
// �e�̃R���X�g���N�^�����s����Ă���
// (�ȗ�����Ă���ƃf�t�H���g�R���X�g���N�^���Ăяo�����)
MyDerived::MyDerived() : d(400)
{
	cout << "�h���N���X�̃R���X�g���N�^\n";
	// a = 100; private�Ȃ̂Ŗ���
	b = 200; // ���������X�g�ł͏������ł��Ȃ��̂ő��
	c = 300; // ���������X�g�ł͏������ł��Ȃ��̂ő��
}

MyDerived::~MyDerived()
{
	cout << "�h���N���X�̃f�X�g���N�^\n";
}

void MyDerived::Show_MyDerived()
{
	// cout << "a  " << b << endl; ��private�Ȃ̂Ŗ���
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;
}