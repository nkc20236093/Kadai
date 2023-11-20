using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class test24_sub : MonoBehaviour
{
    // �ۑ�24
    // ���N���X��Weapon�N���X���쐬
    // �����o�ϐ�
    // ���O�i������^�j
    // �U���́i�����^�j
    // �l�i�i�����^�j
    // ���ϐ��̃A�N�Z�X�w��q�͎��R
    // ���R���X�g���N�^�̎��������R
    class Weapon
    {
        private string name;
        private int attack;
        private int price;
        public Weapon()
        {
            name = "������";
            attack = 0;
            price = 0;
        }
        public Weapon(string a, int b, int c)
        {
            name = a;
            attack = b;
            price = c;
        }
        public void DispInfo1()
        {
            Debug.Log($"���햼:{name}");
            Debug.Log($"�U����:{attack}");
            Debug.Log($"�l�i:{price}�~");
        }
    }

    // �h���N���X��Sword�N���X���쐬
    // �����o�ϐ�
    // ����̎�ށi������^�j
    // ����Z���i������^�j
    // ���ϐ��̃A�N�Z�X�w��q�͎��R
    // �R���X�g���N�^�ł́A�������T��
    // ���O�A�U���́A�l�i�A�����ށA�Z����ݒ�
    // DispInfo���\�b�h�ŁA
    // �S�Ă̏���\��������
    // �\����j
    // ���햼�F�����O�\�[�h
    // �U���́F�T
    // �l�i�F�P�O�O�~
    // �����ށF��
    // �Z���F�Q�i�a��

    // test24_sub��Start���\�b�h�ŁA
    // Sword�N���X�̃C���X�^���X���쐬�B
    // ��̌��̏���\��������B

    class Sword : Weapon 
    {
        private string Sword_name;
        private string Sword_attack_name;
        public Sword()
        {
            Sword_name = "None";
            Sword_attack_name = "������";
        }
        public Sword(string d, string e, string a, int b, int c) : base(a, b, c)
        {
            Sword_name = d;
            Sword_attack_name = e;
        }
        public void DispInfo2()
        {
            Debug.Log($"������:{Sword_name}");
            Debug.Log($"�Z��:{Sword_attack_name}");
        }
    }

    // �h���N���X��Lance�N���X���쐬
    // �����o�ϐ�
    // ����̎�ށi������^�j
    // ����Z���i������^�j
    // �h��́i�����^�j
    // ���ϐ��̃A�N�Z�X�w��q�͎��R
    // �R���X�g���N�^�ł́A�����͂U��
    // ���햼�A�U���́A�l�i�A�����ށA�Z���A�h���
    // DispInfo���\�b�h�ŁA
    // �S�Ă̏���\��������
    //
    // �����X�N���X�̃C���X�^���X����쐬�B
    // ��̑��̏����\������B

    class Lance : Weapon 
    {
        private string Lance_name;
        private string Lance_attack_name;
        private int Defense;
        public Lance()
        {
            Lance_name = "������";
            Lance_attack_name = "������";
            Defense = 0;
        }
        public Lance(string f, string g, int h, string a, int b, int c) : base(a, b, c)
        {
            Lance_name = f;
            Lance_attack_name = g;
            Defense = h;
        }
        public void DispInfo3()
        {
            Debug.Log($"������{Lance_name}");
            Debug.Log($"�Z��{Lance_attack_name}");
            Debug.Log($"�h���{Defense}");
        }
    }
    // Start is called before the first frame update
    void Start()
    {
        Sword sword1 = new Sword("��", "2�i�؂�", "�����O�\�[�h", 10, 100);
        sword1.DispInfo1();
        sword1.DispInfo2();

        Sword sword2 = new Sword("��", "��]�؂�", "�A�C�A���\�[�h", 50, 150);
        sword2.DispInfo1();
        sword2.DispInfo2();

        Lance lance1 = new Lance("�����X", "�V�[���h�_�b�V��", 50, "�V���[�g�����X", 15, 100);
        lance1.DispInfo1();
        lance1.DispInfo3();

        Lance lance2 = new Lance("�����X", "���V�˂�", 50, "�A�C�A�������X", 50, 150);
        lance2.DispInfo1();
        lance2.DispInfo3();
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
