#include <iostream>
#include "MyClass2.h"
using namespace std;

// �R���X�g���N�^��`
MyClass2::MyClass2(int m, int n) :x(m), y(n), px(&x) {}

// �f�X�g���N�^��`
MyClass2::~MyClass2()
{
	cout << "�f�X�g���N�^�Ăяo��\n";
}

// �R�s�[�R���X�g���N�^��`
// x�̒l�̓R�s�[�Ay�̒l��0��
// �|�C���^�̃R�s�[�͂����A�ݒ肵�Ȃ���
MyClass2::MyClass2(const MyClass2& other) :x(other.x), y(0), px(&x) {}

int MyClass2::show()
{
	cout << "x = " << x << " , ";
	cout << "y = " << y << " , ";
	cout << "px = " << px << endl;
	return 0;
}