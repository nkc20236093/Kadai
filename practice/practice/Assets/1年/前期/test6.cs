using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class test6 : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        int a = 1;
        if (a == 1)
        {
            Debug.Log("a��1�ł�");
        }

        else if (a == 2)
        {
            Debug.Log("a��2�ł�");
        }

        else if (a <= 5)
        {
            Debug.Log("a��5�ȉ��ł��ł�");
        }

        else
        {
            Debug.Log("����ȊO");
        }

        //�����̏�������������Ƃ���
        //else�@if�����g��
        //else�@if�����g������ɏ������else����
        //�S�Ă�if���̏������ɓ��͂܂�Ȃ�������
        //���s�����

        //swicth��
        int b = 1;
        switch (b)
        {
            case 0:
                Debug.Log("b��0�ł�");
                break;  //break����swicth���𔲂���
            
            case 1:
                Debug.Log("b��1�ł�");
                break;

            default:
                Debug.Log("����ȊO�ł�");
                break;

        }
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
