#pragma once

class MyClass2
{
	int x, y;
	int* px;
public:
	// ��������R���X�g���N�^
	MyClass2(int m, int n);
	// �R�s�[�R���X�g���N�^
	MyClass2(const MyClass2& other);
	// �f�X�g���N�^
	// �N���X����~��t�������O�������A�����͖���
	~MyClass2();
	// �����o�֐�
	int show();
};
