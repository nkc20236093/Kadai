using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;

public class test3_sub : MonoBehaviour
{
    //���K���1
    //�ϐ�x��10.5�A�ϐ�y��3.14
    //�v�Z���ʂ�����ϐ�sum���쐬
    //x + y = �Z�Z(�v�Z����sum�̒l)
    //x - y = �Z�Z(�v�Z����sum�̒l)
    //x * y = �Z�Z(�v�Z����sum�̒l)
    //x / y = �Z�Z(�v�Z����sum�̒l)
    //x % y = �Z�Z(�v�Z����sum�̒l)
    //�ƂȂ�悤�ADebug.log���g���ĕ\������

    //int + float�̌v�Z�͏����float�ɂȂ�
    //���̂悤�ɏ���Ɍ^���ύX����邱�Ƃ�
    //�Öق̌^�ϊ��Ƃ���

    float x = 10.5f;
    float y = 3.14f;
    float sum;
    // Start is called before the first frame update
    void Start()
    {
        sum = x + y;
        Debug.Log("x + y ="  + sum);

        sum = x - y; 
        Debug.Log("x - y =" + sum);

        sum = x * y;
        Debug.Log("x * y =" + sum);
        sum = x / y;
        Debug.Log("x / y =" + sum);

        sum = x % y;
        Debug.Log("x % y =" + sum);
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
