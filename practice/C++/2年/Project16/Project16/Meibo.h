#pragma once
#include <iostream>
#include <string>
using namespace std;

class Meibo
{
	string name;			// ���O
	double bw;				// �̏d
	double bl;				// �g��
	static int No_of_obj;	// ����N���X�̐�
public:
	static double bw_total;	// �ÓI�f�[�^�����o
	static double bl_total; // �ÓI�f�[�^�����o

	void SetData();

	Meibo();				// �R���X�g���N�^
	static void GetMean();	// �ÓI�����o�֐�
};
