#include <iostream>
using namespace std;

#include "Human.h" //����w�b�_���C���N���[�h

void main()
{
    cout << "project4\n";
    //Human�N���X�̎��̂��쐬
    //�N���X�̎��́i�ϐ��j���쐬����ƁA
    //�R���X�g���N�^���Ăяo�����
    Human h1;
    h1.DispSpace();  //�\���֐��Ăяo��

    //��������R���X�g���N�^�̌Ăяo��
    //���́i�ϐ��j���`����ۂ�()��t����
    //�R���X�g���N�^���Ăяo��

    Human h2(18, "��l��", "�j");
    h2.DispSpace();  //�\���֐��Ăяo��
}
