using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class test11 : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        //���\�b�h�Ƃ́H
        //�߂�l�{���\�b�h���i�����j�o�֐��̒��g�p

        DispText();
        DispText2("DispText�Ăяo��");//������ݒ�

        int max = 0;
        max = Max(10, 20);
        Debug.Log(max);
    }

    //�@�߂�l�Fvoid�@���O:DispText�@����:�Ȃ�
    void DispText()
    {
        Debug.Log("���\�b�h�̕����\��");
    }
    //�߂�l:void ���O:DispText2 ����:����
    void DispText2(string s)
    {
        Debug.Log(s);
    }
    //�ő�l�����߂郁�\�b�h
    //�߂�l�Fint�@���O�FMax�@�����F�����^
    int Max(int a , int b)
    {
        if (a > b) 
        {
            return a;        
        }
        else
        {
            return b;
        }
    }
    // Update is called once per frame
    void Update()
    {
        
    }
}
