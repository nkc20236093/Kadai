#include "Meibo.h"
using namespace std;

// statick�ϐ��̏�����
// statick�ϐ��̓N���X�̊O���ŏ���������
double Meibo::bw_total = 0.0;
double Meibo::bl_total = 0.0;
int Meibo::No_of_obj = 0;

// �ÓI�����o�֐�
// �ÓI�����o�֐���this�|�C���^�֐��������Ȃ�
// �N���X��static�ł͂Ȃ��ϐ��A�֐��ɃA�N�Z�X�ł��Ȃ�
void Meibo::GetMean()
{
	if (No_of_obj != 0)
	{
		cout << "���݂̃f�[�^����" << No_of_obj << "��\n";
		cout << "���݂̑̏d�̍��v��" << bw_total << endl;
		cout << "���݂̐g���̍��v��" << bl_total << endl;
		cout << "���݂̕��ϑ̏d��" << bw_total / No_of_obj << endl;
		cout << "���݂̕��ϐg����" << bl_total / No_of_obj << endl;
	}
	else
	{
		cout << "Error!!\n";
	}
}

void Meibo::SetData()
{
	cout << "���� --- "; cin >> name;
	cout << "�̏d --- "; cin >> bw;
	cout << "�g�� --- "; cin >> bl;
	bw_total += bw;	// �̏d�̍��v�l�����Z
	bl_total += bl;	// �g���̍��v�l�����Z
}

// �R���X�g���N�^
Meibo::Meibo()
{
	SetData();
	// ���������琔�����Z
	No_of_obj++;
}
