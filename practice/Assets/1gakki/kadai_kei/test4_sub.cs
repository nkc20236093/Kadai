using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;

public class test4_sub : MonoBehaviour
{
    float a = 7.5f;
    float b = 3.14f;
    float sum = 0;

    // Start is called before the first frame update
    void Start()
    {
        //�ۑ�4-1
        // �ϐ�a��7.5�A�ϐ�b3.14�ŏ�����
        // �v�Z���ʂ�����ϐ�sum��0�ŏ�����
        // ����������Z�q��p����
        // sum��a�����Z�������̂�
        // �usum =�@�Z�Z�v�ƂȂ�悤�ɕ\��
        //�@sum��b�����Z�������̂�
        // �usum = �Z�Z�v�ƂȂ�悤�ɕ\��

        sum += a;
        Debug.Log("sum = " + a);
        sum -= b;
        Debug.Log("sum =" + b) ;

        //�ۑ�4-2
        //�ϐ�a���C���N�������g���A
        //�ϐ�b���f�N�������g����B
        //a + b�̒l��sum�ɑ����
        //�usum =�@�����v�ƂȂ�悤�ɕ\��

        a++;
        b--;
        sum = a + b;
        Debug.Log("sum =" + sum );

        //�ۑ�4-3
        //bool�^�̕ϐ�flag��錾���Afalase�ŏ�����
        //�������Z�q�A�܂��͕s�������Z�q��p����
        //a��b���r���A���̌��ʂ�flag�ɑ����
        //flag��^�̒l�ɂȂ�悤�ɂ���
        //�uflag = true�v�ƂȂ�悤�ɕ\�L
        //���\���̍ۂ�flag�ϐ����g������

        bool flag = false;

        flag = (a >= b);
        Debug.Log("flag =" + flag);

    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
