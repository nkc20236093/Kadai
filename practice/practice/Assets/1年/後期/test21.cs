using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class test21 : MonoBehaviour
{
    //�����N���X
    class Sword
    {
        //�����o�ϐ��̐錾
        //�A�N�Z�X�w��q(�w�肪�Ȃ���private)
        //private ���̃N���X����������ǂ̃��\�b�h�����������
        //public  ���N���X����������ĕ֗������o�O�������₷��
        private string name;  //���O
        private int atkPow;   //�U����
        private int vital;    //�ϋv��
        public Sword(string n, int p, int v)
        {
            name = n;
            atkPow = p;
            vital = v;
        }

        public void Print()
        {
            Debug.Log("����:" + name);
            Debug.Log("�U����:" + atkPow);
            Debug.Log("�ϋv��:" + vital);
        }
        public void SetName(string n)
        {
            name = n;
        }
        public void SetPower(int p)
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
        public int GetPower()
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
        //Sword�N���X�̃C���X�^���X����(���̎��������ɔz�u)
        Sword mSword = new Sword("���̐�c�s���I", 1000, 100);
        mSword.Print();
        //mSword.SetName("���̐�c�s���I");
        //mSword.SetPower(1000);
        //mSword.SetVital(100);
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
