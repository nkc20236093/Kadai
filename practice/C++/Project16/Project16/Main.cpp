#include <iostream>
#include "MyClass.h"
#include "BMI.h"
#include "Person.h"
#include "Menseki.h"
using namespace std;

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
#endif

	Test3 a1;
	Test3(5);
	Test3(1, 2, 3);
	return 0;
}
