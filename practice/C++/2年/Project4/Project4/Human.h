//Human h
#pragma once  //�C���N���[�h�K�[�h
#include <iostream>

class Human    //�l�ԃN���X
{
private:       //�A�N�Z�X�w��q:�ȉ�private
    int age;            //�N��
    std::string gender; //���� 
    std::string name; //���O 
public:        //�A�N�Z�X�w��q:�ȉ�public
    //�R���X�g���N�^��ݒ�
    //(�N���X�ɂ͕K���R���X�g���N�^������)
    //�N���X�Ɠ������O�̊֐�
    //�R���X�g���N�^�ɂ͕ԋp�l�͖���
    //�������Ȃ��R���X�g���N�^��
    //�f�t�H���g�R���X�g���N�^�Ƃ���
    Human()
    {
        std::cout << "�R���X�g���N�^�̎���\n";
        //�R���X�g���N�^�ł̓N���X�̕ϐ��̏��������s��
        age = 0;
        name = "������";
        gender = "�j";
    }
    //����������R���X�g���N�^�̑��d��`�i�I�[�o�[���[�h�j
    Human(int _age, std::string _name, std::string _gender)
    {
        std::cout << "��������R���X�g���N�^���s\n";
        age = _age;
        name = _name;
        gender = _gender;
    }


    //�\���p�̊֐�
    void DispSpace()
    {
        std:: cout << "�N�� = " << age << "\n";
        std:: cout << "���O = " << name << "\n";
        std:: cout << "���� = " << gender << "\n";
    }
};