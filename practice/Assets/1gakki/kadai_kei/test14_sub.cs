using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;

public class test14_sub : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        // �ۑ�P�T
        // ���\�b�h�̃I�[�o�[���[�h���g����
        // �ȉ��̃��\�b�h������
        // ���\�b�h���FAdd
        // �@int�^�̈���2���󂯎��A
        // �������l��ԋp���郁�\�b�h
        // �Adouble���̈���2���󂯎��A
        // �������l��ԋp���郁�\�b�h
        // �Bstring���̈���2���󂯎��A
        // �����̕���������������������ԋp���郁�\�b�h
        // �@�`�B���\�b�h��Start���\�b�h�ŌĂяo���A
        // �Ăяo�����l��Debug.log�ŕ\������
        Add(10, 20);
        Add(1.2, 3.5);
        Add("hello", "world");

    }

    int Add(int a , int b)
    {
        int sum = a + b;
        Debug.Log(sum);
        return sum;
    }
    double Add(double a, double b)
    {
        double sum = a + b;
        Debug.Log(sum);
        return sum;
    }
    string Add(string a , string b)
    {
        string sum = a + b;
        Debug.Log(sum);
        return sum;
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
