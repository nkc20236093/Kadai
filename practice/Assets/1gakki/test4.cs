using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class test4 : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        //�������Z�q�ɂ���
        int a = 5, b = 3;
        int sum = 0;

        //����������Z�q
        sum += a;   // += sum = sum + a;
        Debug.Log("sum=" + sum);
        sum -= b;   // -= sum = sum - b;
        Debug.Log("sum=" + sum);
        sum *= a;   // *= sum = sum * a;
        Debug.Log("sum=" + sum);
        sum /= b;   // /= sum = sum / b;
        Debug.Log("sum=" + sum);

        sum++; //�C���N�������g sum += 1
        Debug.Log("sum = " + sum);
        sum--; //�f�N�������g sum -= 1
        Debug.Log("sum = " + sum);

        // bool�^�i�^�U�������^�j
        // c��ł�true��false���̂ǂ��炩
        // ��������^
        //���l��\����false = 0 true = 1

        bool flag = false;


        //�������Z�q ==
        //a��b���������Ȃ�true�A�Ⴄ�Ȃ�false
        //��ԋp����

        flag = (a == b);
        Debug.Log("flag = " + flag);

        // !=
        // a��b���������Ȃ����true�A���������false
        flag = (a != b);
        Debug.Log("flag =" + flag);

        //a��b���r����悤�ȉ��Z�q��
        //��r���Z�q�Ƃ���
        //�u<�v�u>�v�A�u<=�v�u>=�v
        //�Ȃǂ�����

        flag = (a < b);
        Debug.Log("flag = " + flag);
        flag = (a > b);
        Debug.Log("flag = " + flag);
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
