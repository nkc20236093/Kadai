using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;

public class test16_sub : MonoBehaviour
{
    public int kaijou;
    // Start is called before the first frame update
    void Start()
    {
        // �ۑ�16
        // public�ϐ���x,y���쐬(�l�͍D���Ȓl��OK)
        // �@��̈����̉��Z���ʂ�ԋp���郁�\�b�hAdd���쐬
        // Start���\�b�h�ŌĂяo���Ax��y�̉��Z���ʂ�Debug.Log�ŕ\��
        // ��jx��y�̉��Z���ʂ́Z�Z

        
        Debug.Log("x��y�̉��Z���ʂ�" + Add(4,5));
        // �A��ӂƍ����������ɎO�p�`�̖ʐς����߂郁�\�b�hTrianle���쐬
        // Start���\�b�h�ŌĂяo���A���x����y�̎O�p�`�̖ʐς�Debug.Log�ŕ\
        // ��j���x����y�̎O�p�`�̖ʐς́���

        
        Debug.Log("���4����5�̎O�p�`�̖ʐς�" + Trianle(4,5));
        // �B���a�������ɉ~�̖ʐς����߂郁�\�b�hCircle���쐬
        // Start���\�b�h�ŌĂяo���A���ax�̉~�̖ʐς�Debug.Log�ŕ\��
        // ��j���ax�̉~�̖ʐς́���
        
        Debug.Log("���a5�̉~�̖ʐς�" + Circle(4) );
        // �C�����̊K������߂郁�\�b�hFactrial���쐬
        // Start���\�b�h�ŌĂяo���Ax�̊K�挋�ʂ�Debug.Log�ŕ\��
        // ��jx�̊K�挋�ʂ́���
        
        Debug.Log("x�̊K�挋�ʂ�" + Factrial(5));
    }

    int Add(int x ,int y)
    {
        int sum = x + y;
        return sum;
    }
    int Trianle(int x , int y)
    {
        int menseki = x * y / 2;
        return menseki;
    }
    float Circle(int x)
    {
        float en = x * x * Mathf.PI;
        return en;
    }
    public static long Factrial(int n)
    {
        if (n == 0)
            return 1;
        return n * Factrial(n - 1);
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
