using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UIElements;

public class test6_sub : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        //�ۑ�6-1
        //�������̕ϐ�a��10�ŏ�����
        //else id�����g����
        //a��0�̎��ua��0�ł��v
        //a��10��菬�����Ƃ��ua��10��菬�����ł��ł��v
        //a��10�̎��ua��10�ł��v
        //a��10�ȏ�̎��ua��10�ȏ�ł��v
        //�ƕ\�������悤�ɂ���

        int a = 10;
        if (a == 0)
        {
            Debug.Log("a��0�ł�");
        }
        else if (a <= 10) 
        {
            Debug.Log("a��10��菬�����ł�");
        }
        else if (a == 10)
        {
            Debug.Log("a��10�ł�");
        }
        else
        {
            Debug.Log("a��10�ȏ�ł�");
        }

        //�ۑ�6-2
        //�����^�̕ϐ�b��5�ŏ�����
        //switch�����g����
        //b��0�̎��ub��0�ł��v
        //b��2�̎��ub��2�ł��v
        //b��5�̎��ub��5�ł��v
        //b����L�̏����ɓ��Ă͂܂�Ȃ��Ƃ�
        //�ub�̒l�͓��Ă͂܂�܂���ł����v
        //�ƕ\�������悤�ɂ���

        int b = 5;
        switch(b)
        {
            case 0:
                Debug.Log("b��0�ł�");
                break;
            case 2:
                Debug.Log("b��2�ł�");
                break;
            case 5:
                Debug.Log("b��5�ł�");
                break;
            default:
                Debug.Log("b�̒l�͓��Ă͂܂�܂���ł���");
                    break;
        }

        //�ۑ�6-3
        //������^�̕ϐ�s���쐬
        //s��abc����
        //swicth�����g����
        //s��abc�̎��us�́����ł��v
        //s��def�܂���ghi�̎�
        //�us��def��ghi�̂ǂ��炩�ł��v�ƕ\��
        //s������ȊO�̎�
        //�us������ȊO�̎�
        //�us�̕�����͏����ɂ��Ă͂܂�܂���ł����v
        //�ƕ\�������悤�ɂ���

        string s = "abc";
        switch(s)
        {
            case "abc":
                Debug.Log("s��" + s);
                break;

            case "def":
            case "ghi":
                Debug.Log("s��def��ghi�̂ǂ��炩�ł�");
                break;

            default:
                Debug.Log("s�̕�����͏����ɂ��Ă͂܂�܂���ł���");
                break;
        }
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
