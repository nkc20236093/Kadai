// MyClass.h
#pragma once

// 231p �N���X�̎g�p��
class MyClass
{
	// ����J��
private:
	int a;
	// ���J��
public:
	int b;
	int set_a();   // �֐��錾�̂�
	int show_a();  // �֐��錾�̂�

	// �C�����C���֐�
	// �C�����C���֐��ɂ���ƁA�R���p�C�����Ɋ֐��̒��g���W�J����
	// �֐��Ăяo���̏������Ȃ��Ȃ�A�������y���Ȃ�
	inline int add(int a, int b) { return a + b; }
};

