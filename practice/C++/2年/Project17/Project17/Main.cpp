#include <iostream>
#include "MyDerived.h"
using namespace std;

// ���ۃN���X
// �������z�֐������N���X�A���ۃN���X�Ƃ���
// ���ۃN���X�͎��̂������Ƃ��ł��Ȃ�
class Date 
{
protected:
	double x, y;
public:
	// �������z�֐��͒��g�������Ȃ��̂� = 0; �Ə����B
	// �������z�֐��͕K���I�[�o�[���C�h���Ȃ��Ƃ����Ȃ�
	virtual double SetValue(double a, double b) = 0;
	virtual void GetValue(double* a, double* b) = 0;
};

class DateA :public Date
{
public:
	// �������z�֐��̃I�[�o�[���C�h
	double SetValue(double a, double b) { x = a, y = b; }
	void GetValue(double* a, double* b) { *a = x, * b = y; }
};

// ���N���X
class GameObject
{
public:
	// ���z�֐�
	// �p�����Ďg���O��
	// �q����Show�֐��������Ă����ꍇ��
	// �q����Show�֐����g���Ă����֗��Ȃ��

	virtual void Show()
	{
		cout << "GameObject\n";
	}
};

// �Q�[���I�u�W�F�N�g���p�������v���C���[�N���X
class Player :public GameObject
{
public:
	void Show()
	{
		cout << "Player\n";
	}
};

// �Q�[���I�u�W�F�N�g���p�������G�N���X
class Enemy :public GameObject
{
	void Show()
	{
		cout << "Enemy\n";
	}
};

// ���z�֐��ƒ��ۃN���X
class A
{
public:
	void Show() 
	{
		cout << "��{�N���X�̊֐�\n"; 
	}
};

class B :public A
{
public:
	int x;
	B() : x(100) {}
	void Show()
	{
		cout << "�h���N���X�̊֐�\n";
	}
};

int main()
{
#if false
	{
		MyDerived der;
		cout << "�h���N���X��Show_MyDerived���Ăяo��\n";
		der.Show_MyDerived();

		cout << "���N���X��Show_Date���Ăяo��\n";
		der.Show_Data();
	}
	{
		B child;
		// Show�֐��͔h���N���X��B���Ăяo�����
		// ������֐��̃I�o�[���C�h�ƌ���
		child.Show();
		// ��{�N���X(A)��Show�֐����ĂԂƂ��́A
		// �X�R�[�v�������Z�q���g��
		child.A::Show();

		// �|�C���^���g�����֐��Ăяo��
		A* pBase;	// A�N���X�̃|�C���^(���̂͂Ȃ�)
		B derived;	// B�̎���
		// ��{�N���X�̃|�C���^�ɔh���N���X�̃A�h���X����
		pBase = &derived;

		// �|�C���^���w��Show�֐������s
		pBase->Show();

		// �e�̃|�C���^����A�������q���̊֐����Ă�
		// pBase���q���̃|�C���^�ɕϊ�������Ɋ֐����ĂԂƏo����
		static_cast<B*>(pBase)->Show();

		// �e�̃|�C���^����q���̎��ϐ�x�ɂ̓A�N�Z�X�͂ł��Ȃ�
		// �A�N�Z�X����ۂ͎q���̃|�C���^�ɕϊ����Ă�����
		// pBase->x = 0; ������͂ł��Ȃ�
		static_cast<B*>(pBase)->x = 0;
	}
	{
		GameObject* pObj;
		Player pl;
		Enemy em;

		// �e�N���X�̃|�C���^���g���Ďq���N���X�̊֐����Ăяo��
		// �q���̃A�h���X��e�̃|�C���^�ɕϊ����邱�Ƃ��A�b�v�L���X�g�Ƃ���
		// �e�̃A�h���X���q���̃|�C���^�ɕϊ����邱�Ƃ��_�E���L���X�g�Ƃ���
		pObj = &pl;
		pObj->Show();

		pObj = &em;
		pObj->Show();

		GameObject* ptrTable[] =
		{
			&pl,&em
		};
		int length = sizeof(ptrTable) / sizeof(int);
		for (int i = 0; i < length; i++)
		{
			ptrTable[i]->Show();
		}
	}
	#endif
}