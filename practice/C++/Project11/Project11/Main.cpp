#include <iostream>
#include <string>
#include <regex>
using namespace std;

//�@
//int�^�̕ϐ�a, b��錾
//a��10�Ab��20�ŏ�����
//�ϐ�a�̃A�h���X��\���ia�̃A�h���X�́Z�Z�ł��j
//�ϐ�b�̃A�h���X��\���ia�̃A�h���X�́Z�Z�ł��j
//a�̃A�h���X������|�C���^pa���쐬
//b�̃A�h���X������|�C���^pb���쐬
//���ꂼ��̃|�C���^����ԐڎQ�Ƃ�p���āA
//a�̒l��100�ɁAb�̒l��200�ɕύX
//a�̒l��\��(a�̒l�́Z�Z�ł��j
//b�̒l��\��(a�̒l�́Z�Z�ł��j

void funcA(int* pa)
{
	*pa = 100;
}

void funcB(int* pa)
{
	*pa = 200;
}

//�A
//�l��ύX����֐�changeValue���쐬�i�߂�l��void�A������int�^�̃|�C���^�j
//�֐����ł́A�󂯂Ƃ����|�C���^���ԐڎQ�Ɖ��Z�q��p���āA�l��500�ɕύX����B
//
//main�֐����ŁAchangeValue�֐����Ăяo���B
//�������ɇ@�̖��ō쐬�����ϐ�a�̃A�h���X������B
//���̌�A�ϐ�a�̒l�̕\���ichangeValue���Ăяo�������a�̒l�́Z�Z�ł��j

void changeValue(int* pa) 
{
	*pa = 500;
}

//�B
//int�^�̃|�C���^temp���쐬�B
//char�^�̕ϐ�input���쐬
//cin��input�ɓ��͂�����B
//
//input��'a'�������Ă�����Atemp�ɂ�a�̃A�h���X�����A
//'b'�������Ă�����temp�ɂ�b�̃A�h���X������B
//�i����ȊO�͓��̓G���[�ƕ\���j
//
//���̌�Atemp�̒l���ԐڎQ�Ƃŕ\������
//�i���͂��ꂽ�Z�Z�̒l�́Z�Z�ł��j

int main()
{
	int a = 10, b = 20;

	cout << "a�̃A�h���X��" << &a << "�ł�\n";
	cout << "b�̃A�h���X��" << &b << "�ł�\n";
	funcA(&a);
	cout << "a�̒l��" << a << "�ł�\n";
	funcB(&b);
	cout << "b�̒l��" << b << "�ł�\n";

	changeValue(&a);
	cout << "changeValue���Ăяo�������a�̒l��" << a << "�ł�\n";
	
	int* temp;
	char input;
	cin >> input;

	if (input == 'a')
	{
		temp = &a;
		cout << "���͂��ꂽtemp�̒l��" << *temp << "�ł�\n";
	}
	else if (input == 'b')
	{
		temp = &b;
		cout << "���͂��ꂽtemp�̒l��" << *temp << "�ł�\n";
	}
	else
	{
		cout << "�G���[\n";
	}
}
