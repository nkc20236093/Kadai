#include <iostream>
using namespace std;

// ����w�b�_
#include "MyClass.h"
#include "BMI.h"
#include "Person.h"
#include "Menseki.h"
#include "MyClass2.h"
#include "MyClass3.h"
#include "MyClass4.h"
#include "Meibo.h"

// �N���X�Ƃ�
// �f�[�^�A�֐��Ȃǂ��܂Ƃ߂��^
// ���[�U�[�����R�ɍ쐬�ł��郆�[�U�[��`�^

class Human 
{
	// �A�N�Z�X�w��q�F����J
private:
	// �f�[�^�����o�i�����o�ϐ��j
	int age;
	string gender;
	// �����܂Ŕ���J
	// �A�N�Z�X�w��q�F���J
	void DispPlay() 
	{
		cout << "�\�����܂�\n";
	}
	// �����܂Ō��J
};

// �R���X�g���N�^����
class Test1
{
	int x;
	// �R���X�g���N�^����`����ĂȂ��N���X��
	// �f�t�H���g�R���X�g���N�^���ÖٓI�ɗp�ӂ����
};

// �f�t�H���g�R���X�g���N�^���`
// �f�t�H���g�R���X�g���N�^�͈��������̃R���X�g���N�^
// ���O�Ŏ������邱�Ƃ��ł���

// ���O�Ŏ������邱�Ƃ��ł���
class Test2
{
	int x;
	Test2() :x(100) {}
};

// 
class Test3
{
	int x;
public:
	// �����L��̃R���X�g���N�^������
	// �f�t�H���g�R���X�g���N�^�͎�����������Ȃ��̂�
	// ���O�Ŏ�������K�v������
	Test3() :x(100) {}
	Test3(int a) : x(a) {}
	// �f�t�H���g����������R���X�g���N�^
	Test3(int a, int b, int c) :x(a + b + c) {}
};

// �֐��̃|�C���^�̗�
void ActionCharge() { cout << "�ːi\n"; }
void ActionTall() { cout << "����\n"; };
void ActionPunch() { cout << "�Ō�"; };

// �֐��̃|�C���^�̔z����`
void (*ActionFunc[])(void) =
{
	ActionCharge,
	ActionPunch,
	ActionTall
};


int main()
{
#if false
	// �N���X�̎��́i�C���X�^���X�j�쐬
	MyClass mc{};

	// b�͌��J���Ȃ̂ŁA�A�N�Z�X�\
	mc.b = 100;
	cout << "b = " << mc.b << endl;

	// a�͔���J�Ȃ̂ŃA�N�Z�X�ł��Ȃ�
	//mc.a = 100;

	// ���J��set_a()���g�p���A����J��a�̒l��ݒ�
	mc.set_a();
	// ���J��show_a()���g�p���A����J��a�̒l��\��
	mc.show_a();
	BMI b{};
	b.SetData();
	b.ShowBMI();
	Person p("aaaa", 100, 'M');
	
	// �l�ԃN���X�̍쐬
	Person yamada("�R�c���Y", 26, 'M');
	Person hanako("�c���Ԏq", 24, 'F');
	cout << "-----------------" << endl;
	yamada.Show();
	cout << "-----------------" << endl;
	hanako.Show();
	cout << "-----------------" << endl;
	
	Menseki circle(1.5), rect(5.2, 2.5), daikei(2.5, 4.5, 3.0);
	cout << "���a1.5�̉~�̖ʐς�" << circle.show() << "�ł�\n";
	cout << "�c5.2�A��2.5�̒����`�̖ʐς�" << rect.show() << "�ł�\n";
	cout << "���2.5�A����4.5�A����3.0�̑�`�̖ʐς�" << daikei.show() << "�ł�\n";

	Test3 a1;
	Test3(5);
	Test3(1, 2, 3);

	// MyClass2�̎��̍쐬
	MyClass2 a(10, 100);
	// �R�s�[�R���X�g���N�^�ɂ�鏉����
	// �������̍ۂɎ������g�̃N���X����
	MyClass2 b = a;
	// MyClass2 b(a);�@���̏��������� 

	// ���(�R�s�[�R���X�g���N�^�͌Ă΂�Ȃ�)
	b = a;

	a.show();
	b.show();

	MyClass2 a(10, 100);
	a.show();
	// �R�s�[�R���X�g���N�^�ŃR�s�[
	// �R�s�[�R���X�g���N�^�Ń|�C���^���R�s�[�����
	// �o�O���N����\��������
	// b��*px��b��x�̃A�h���X�ł͂Ȃ��Aa��x�̃A�h���X�������Ă��܂�
	MyClass2 b = a;
	b.show();

	MyClass2 a(10, 100);
	MyClass2 b = a;
	a.show();
	b.show();

	MyClass3 a;
	a.SetX(10);
	int num;
	a.ReadX(&num);
	cout << "x = " << num << endl;

	Meibo man[3];
	for (int i = 0; i < 3; ++i)
	{
		man[i].SetData();
	}

	// �ÓI�f�[�^�����o�̓X�R�[�v�������Z�q�Ŏg�p����
	// Meibo::bw_total
	cout << "�̏d�̍��v:" << Meibo::bw_total << endl;
	cout << "�g���̍��v:" << Meibo::bl_total << endl;

	string end;
	while (1)
	{
		Meibo person;
		// �ÓI�����o�֐��Ăяo��
		// �N���X��::�֐��ŌĂяo��
		Meibo::GetMean();
		cout << "�����܂���?(y/n)";
		cin >> end;
		if (end[0] == 'n')
		{
			break;
		}
		cout << "----------------\n";
	}

	// �֐��̃|�C���^
	MyClass4 mc;
	// �����o�ϐ��ւ̃|�C���^��錾
	// �߂�l�A�|�C���^�̖��O�A�����̌^
	int (MyClass4:: * ptr1)();
	int (MyClass4:: * ptr2)(int);

	// ����������Show�֐��̃A�h���X
	ptr1 = &MyClass4::Show;
	// �����L���Show�֐��̃A�h���X
	ptr2 = &MyClass4::Show;
	// �Ԑڃ|�C���^���g���Ċ֐��Ăяo��
	(mc.*ptr1)();
	(mc.*ptr2)(20);

	int actionNo = 0;
	ActionFunc[actionNo]();

	// �\����(struct)�ɂ���
	// �ق�class�Ɠ��������A�f�t�H���g�̃A�N�Z�X�w�肪public�ɂȂ��Ă�
	struct A
	{
		string str;
		int x;
	};
	A test;
	test.str = "abc";
	test.x = 100;
	cout << "str = " << test.str << endl;
	cout << "x = " << test.x << endl;


#endif
	// ���p��
	// �����̃f�[�^�����o�������Ƃ��ł���^����
	// ���ۂɋL���ł���̂�1�̃����o�̂�
	// ���ꂼ��̕ϐ��̈�ԑ傫�ȗ̈悪�m�ۂ����
	union Account
	{
		int x;
		double y;
		char c[4];
		bool b[32];
	};

	Account a;
	a.x = 100;
	a.y = 3.14;
	cout << "a.x = " << a.x << endl;
	cout << "a.y = " << a.y << endl;

	union Free
	{
		int x;
		double y;
		char c[4];
		bool b[32];
	};
	class Enemy
	{
		Free free[4];
	};

	return 0;
}
