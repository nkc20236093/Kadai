#include <iostream>
#include "MyClass.h"
#include "BMI.h"
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
#endif

	BMI b{};
	b.SetData();
	b.ShowBMI();
	return 0;
}