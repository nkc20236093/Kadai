using System.Collections;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Security.Cryptography;
using Unity.VisualScripting;
using UnityEngine;

public class test7_sub : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        //�ۑ�7-1
        //for�����g����
        //�����^�̕ϐ�a�̒l��
        //0����5�ɂȂ�悤��
        //�C���N�������g��
        //�C���N�������g�������
        //�ua�̒l�́Z�Z�ł��v�ƂȂ�悤�ɕ\��
        int a = 0;
        for(int i = 0; a < 5; i++)
        {
            a++;

            Debug.Log("a�̒l��" + a);
        }

        //�ۑ�7-2
        //�����^�̕ϐ�b��10�ŏ�����
        //whiled�����g����b���f�N�������g��
        //�f�N�������g�������
        //�ub�̒l�́����ł��v�ƂȂ�悤�ɕ\��
        //b��0�ɂȂ�����while�����I��������

        int b = 10;
        do
        {
            b--;
            Debug.Log("b�̒l��" + b);
        } while (b != 0);

        //�ۑ�7-3
        //1����10�̒l��S�đ�����
        //�v�Z���ʂ�ϐ�sum�ɑ�����
        //�u1����10�̒l�𑫂����l�́����ł��v
        //�Ȃ��A�J��Ԃ������g����
        //10�񏈗����J��Ԃ�����Ɍv�Z���ʂ��o������

        int f = 0;
        int sum = 0;
        while (true)
        {

            f++;
            sum = sum + f;
            if (f == 10)
            {
                Debug.Log("�P����P�O�̒l�𑫂����l��" + sum + "�ł�");
                break;
            }
        }
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
