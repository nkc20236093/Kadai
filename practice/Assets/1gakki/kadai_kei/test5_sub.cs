using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class test5_sub : MonoBehaviour
{
    int a = 10,b = 5 ,c = 20;
    // Start is called before the first frame update
    void Start()
    {
        //�ۑ�5-1
        //�����^��a��10�Ab��5�Ac�ɂ����Đ錾20
        //if����p����a��b�̑傫�����r���A���ʂ��^�ł����
        //�ua��b�����傫���v�ƕ\��
        //���ʂ��U�ł����
        //�ub��a�����傫���v�ƕ\��

        if (a>b)
        {
            Debug.Log("a��b�����傫��");
        }
        else if (a<b)
        {
            Debug.Log("b��a�����傫��");
        }

        //�ۑ�5-2
        //a * 2�̒l��c�̒l���̑傫����
        //���������ǂ�����ׁA���ʂ��^�ł����
        //�ua * 2��c�͓������v�ƕ\��
        //���ʂ��U�ł����
        //�ua*2��c�͓������Ȃ��v�ƕ\��

        if (a*2 == c)
        {
            Debug.Log("a * 2��c�͓�����");
        }
        else
        {
            Debug.Log("a*2��c�͓������Ȃ�");
        }

        //�ۑ�5-3
        //�ϐ�a,b,c�ň�ԑ傫�����l��
        //if�����g���ċ���
        //�u��ԑ傫���l�́Z�Z�ł��v�ƂȂ�悤�ɕ\��

        int ookii = a;

        if (b > ookii)
        {
            ookii = b;
        }

        else if (c > ookii)
        {
            ookii = c;
        }

        if(c < ookii && b > ookii)
        {
            ookii = a;
        }

        Debug.Log("��ԑ傫���l��" + ookii);
    }
}
