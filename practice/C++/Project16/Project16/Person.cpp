#include <iostream>
#include "Person.h"
using namespace std;

// �R���X�g���N�^�̒�`
// ���������X�g���g���ă����o�ϐ���������
// �֐����ł̏�������菉�������X�g�̕��������̌���������
Person::Person(const string& nm, int n, char s) :name(nm), age(n), sex(s)
{
	cout << "Person�̃R���X�g���N�^�Ăяo��\n";
}
int Person::Show()
{
	cout << "���� : " << name << endl;
	cout << "�N�� : " << age << endl;
	cout << "���� : " << sex << endl;
	return 0;
};