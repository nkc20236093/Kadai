using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class test21_sub : MonoBehaviour
{
    // �ۑ�21 �N���X
    // 21-1
    // ���N���X�iAxe�N���X�j���쐬
    // �����o�ϐ�(�A�N�Z�X�w��q��private)��
    // ������^��name,�����^��atkPow,vital������
    // �R���X�g���N�^���쐬���A
    // name, atkPow, vital�ɒl��������悤�ɂ���B
    // �����o�֐�Print���쐬���A
    // �����o�ϐ���S�ĕ\������B
    // ��j
    // ���O�F�Z�Z�A�b�N�X�i�Z�Z�͍D���Ȗ��O������j
    // �U���́F�Z�Z�i�Z�Z�͐ݒ肵���l�j
    // �ϋv�l�F�Z�Z�i�Z�Z�͐ݒ肵���l�j
    //
    // 21-2
    // ���N���X�iShield�N���X�j���쐬
    // �����o�ϐ�(private�j��
    // ���O�A�h��́A�ϋv�l�����B(�ϐ����͎��R�j
    // �R���X�g���N�^�Ń����o�ϐ���������
    // Print�֐��Ń����o�ϐ���S�ĕ\������B
    // ��21-1�Ɠ����悤�ȗl���ŕ\��
    //
    // 21-3
    // ���N���X�̍U���͂ƁA���N���X�̖h��͂ŁA
    // ���݂��̒l���ׁA���������̑ϋv��
    // �U���́[�h��͂̍����ō�鏈�������
    //
    // ���s��j
    // �Z�Z���̍U��:10 VS �Z�Z���̖h��:8
    // �Z�Z���̏���
    // �Z�Z���̑ϋv���Z�Z�ɂȂ�܂���
    //
    // ���쐬�̃q���g
    // �N���X�̃����o�ϐ���private�Ȃ̂ŁA�ʓ|�ł��B
    // �֐����g���Ēl���Q�Ƃ�����A
    // �ݒ�ł���悤���킵�Ă�������
    class Axe
    {
        private string name;
        private int atkPow;
        private int vital;

        public Axe(string n, int p, int v)
        {
            name = n;
            atkPow = p;
            vital = v;
        }
        public void Print()
        {
            Debug.Log($"{name}�A�b�N�X");
            Debug.Log(atkPow);
            Debug.Log(vital);
        }
        public void SetName(string n)
        {
            name = n;
        }
        public void SetaktPow(int p)
        {
            atkPow = p;
        }
        public void SetVital(int v)
        {
            vital = v;
        }
        public string GetName()
        {
            return name;
        }
        public int GetatkPow()
        {
            return atkPow;
        }
        public int GetVital()
        {
            return vital;
        }
    }
    class Shield 
    {
        private string name_1;
        private int defense;
        private int vital_1;
        public Shield(string n, int d, int v)
        {
            name_1 = n;
            defense = d;
            vital_1 = v;
        }
        public void Print()
        {
            Debug.Log($"{name_1}�V�[���h");
            Debug.Log(defense);
            Debug.Log(vital_1);
        }
        public void SetName(string n)
        {
            name_1 = n;
        }
        public void SetDefence(int d)
        {
            defense = d;
        }
        public void SetVital(int v)
        {
            vital_1 = v;
        }
        public string GetName()
        {
            return name_1;
        }
        public int GetDefence()
        {
            return defense;
        }
        public int GetVital()
        {
            return vital_1;
        }
    }
    // Start is called before the first frame update
    void Start()
    {
        Axe axe = new Axe("��", 600, 500);
        axe.Print();
        string a = axe.GetName();
        int b = axe.GetatkPow();
        int c = axe.GetVital();

        Shield shield = new Shield("��", 500, 600);
        shield.Print();
        string aa = shield.GetName();
        int bb = shield.GetDefence();
        int cc = shield.GetVital();

        int zz = axe.GetatkPow() - shield.GetDefence();
        string zzz;

        Debug.Log($"{a}�̍U��:{b} VS {aa}�̖h��:{bb}");
        if (b > bb)
        {
            zzz = aa;
            Debug.Log($"{aa}�̏���");
        }
        else
        {
            zzz = a;
            Debug.Log($"{a}�̏���");
        }
        Debug.Log($"{zzz}�̑ϋv��{zz}�ɂȂ�܂���");
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
