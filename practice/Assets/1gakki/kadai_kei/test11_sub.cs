using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class test11_sub : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        // �ۑ�11-1
        // �߂�l�F�Ȃ�
        // ���\�b�h���FDispString
        // �����F������^��s
        // ���\�b�h�̒��g�FDebug.log���g���Ĉ�����\��
        // ��L�̃��\�b�h���쐬���AStart���\�b�h�ŌĂт���
        DispString("�ۑ�11-1�̃��\�b�h");
        // �ۑ�11-2
        // �߂�l�F�����^
        // ���\�b�h���FAdd
        // �����F�����^a,b
        // ���\�b�h�̒��g�F����a,b�𑫂����l��ԋp
        // ��L�̃��\�b�h���쐬���A
        // Start���\�b�h�ŌĂяo���A�߂�l��Debug.log�ŕ\��
        // �����ɓ���鐮���̗��10,15
        int add = 0;
        add = Add(10, 15);
        Debug.Log(add);
        // �ۑ�11-3
        // �߂�l�F�����^
        // ���\�b�h���FMin
        // �����F�����^��a,b,c
        // ���\�b�h�̒��g�F����a,b,c���r���A�ŏ��l��ԋp
        // ��L�̃��\�b�h���쐬���A
        // Start���\�b�h�ŌĂяo���A�߂�l��Debug.log�ŕ\��
        // �����ɓ���鐮���̗��100, 50, 200
        int min = 0;
        min = Min(100, 50, 200);
        Debug.Log(min);
    }

    void DispString(string s)
    {
        Debug.Log(s);
    }
    int Add(int a,int b)
    {
        int sum = a + b;
            return sum;
    }
    int Min(int a ,int b,int c)
    {


        if (a < b && a < c)
        {
             return a;    
        }
        else if (b < c && b < a)
        {
            return b;
        }
        else
        {
            return c;
        }



    }
    // Update is called once per frame
    void Update()
    {
        
    }
}
