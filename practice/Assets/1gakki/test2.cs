using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class test2 : MonoBehaviour
{
    int b = 0;
    //�ϐ�b�̓N���X���őS�ĂŎg����
    // Start is called before the first frame update
    void Start()
    {
        //int��integer�̗��A�����̂���
        int i = 100;
        //flat �����������^
        //foat�̌^���ƕ�����悤�A�Ō��f������
        float f = 3.12f;
        //double �@�����������^
        //float���傫�ȕϐ��������Ƃ��Ɏg��
        double d = 3.14159265;
        //string�@������������^
        string s = "������ł�";

        int a = 10;
        Debug.Log(a);
        //debug.log�͕ϐ�����������\���ł���
        //�������ƕϐ��𗼕��\���������Ƃ���A
        //����������\������Ƃ��́u�{�v�Ō�������
        Debug.Log("����a =" + a);
        Debug.Log("����a =" + b);
        Debug.Log("����f =" + f);
        Debug.Log("����i =" + i);
        Debug.Log("����s =" + s);
    }

    // Update is called once per frame
    void Update()
    {
        b = b + 1;
        Debug.Log("�ϐ�b =" + b);
    }
}
