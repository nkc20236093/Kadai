using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class test13 : MonoBehaviour
{

    void Start()
    {
        //�ċA���\�b�h
        Repeat(5);

        //�K��̌Ăяo��
        Debug.Log(factrial(5));
    }

    void Update()
    {

    }

    //�ċA�Ăяo�����\�b�h
    //�ċA���\�b�h�Ƃ�
    //���\�b�h�̒��Ŏ����̃��\�b�h���Ăяo�����\�b�h
    int Repeat(int num)
    {
        if (num != 0)
        {
            num--;
            Debug.Log(num);
            Repeat(num); //���g�̃��\�b�h���Ăяo��
        }
        return 0;
    }

    //�K������߂��A���\�b�h
    int factrial(int num)
    {
        int sum;
        if (num == 0)
        {
            return 1;
        }
        sum = factrial(num - 1);   //�ċA�Ăяo��
        return num * sum;
    }
}