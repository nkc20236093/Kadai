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
            Debug.Log($"�A�b�N�X");
            //Debug.Log();
            //Debug.Log();
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

    // Start is called before the first frame update
    void Start()
    {
        Axe axe = new Axe("��", 500, 500);
        axe.Print();
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
