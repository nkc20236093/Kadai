using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;

public class test2_sub : MonoBehaviour
{
    //���1
    //�����^�̕ϐ��unum�v��錾���A125�̒l�ŏ�����
    //unity�̃R���\�[����
    //num�̒l��125�ł�
    //�ƂȂ�悤�ɕ\���B(�֐����g����)
    
    //���2
    //�����^�̕ϐ����ua�v�A�ub�v�A�uc�v�����ꂼ��錾���A
    //a��2.5�Ab��3.6�Ac��4.3������
    //Unity�̃R���\�[����
    //a=2.5  b =3.6 c =4.3
    //�ƂȂ�悤�ɕ\���i�֐����g���j

    //���3
    //���2�ō쐬����a,b,c
    //�𑫂����l��������ϐ��usum�v���쐬���A
    //Unity�̃R���\�[����
    //sum�̒l�́Z�Z�i�v�Z���ʁj�ł��B
    //�ƂȂ�悤�ɕ\���i�ϐ����g���j

    int num = 125;
    float a = 2.5f;
    float b = 3.6f;
    float c = 4.3f;

    // Start is called before the first frame update
    void Start()
    {
        float sum = a + b + c;
        Debug.Log("num�̒l��" + num);

        Debug.Log("a�̒l��" + a);
        Debug.Log("b�̒l��" + b);
        Debug.Log("c�̒l��" + c);
        

        Debug.Log("sum�̒l��" + sum);
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
