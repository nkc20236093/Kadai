using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class test22 : MonoBehaviour
{
    //�N���X�̒�`
    class Test1
    {
        //�����o�ϐ�(�A�N�Z�X�w��q���Ȃ��ꍇ��private)
        int x;
        //�R���X�g���N�^
        public Test1(int value) { x = value; }
        //�A�N�Z�T
        public int GetX() { return x; }             //�Q�b�^
        public void SetX(int value) { x = value; }  //�Z�b�^
    }

    //
    class Test2
    {
        private int x;
        //�����Ȃ��R���X�g���N�^
        public Test2() { x = -1; }
        //��������R���X�g���N�^
        public Test2(int value) { x = value; }

        //�v���p�e�B
        public int X
        {
            get { return x; }
            set { x = value; }
        }
    }

    void Start()
    {
        //�N���X�̎��̂̍쐬(�R���X�g���N�^�̌Ăяo��)
        Test1 t1 = new Test1(100);
        Debug.Log("x=" + t1.GetX());
        t1.SetX(200);
        Debug.Log("x=" + t1.GetX());

        //Test2�N���X�̎��̂̍쐬
        Test2 t2a = new Test2();      //�����Ȃ�
        Test2 t2b = new Test2(100);   //��������
        //�v���p�e�B��p���ĕ\��
        //���\�b�h�ƈ����()��t����K�v���Ȃ�
        Debug.Log("t2a.x =" + t2a.X);
        Debug.Log("t2b.x =" + t2b.X);
        //�v���p�e�B��set
        //���Z�q���g���Ēl�����ł���
        t2a.X = 0;
        t2a.X += 100;
        t2b.X -= 200;
        Debug.Log("t2a.x =" + t2a.X);
        Debug.Log("t2b.x =" + t2b.X);
    }

}
