using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class test9 : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        int[] a = new int[3];
        a[0] = 1;
        a[1] = 2;
        a[2] = 3;
        Debug.Log("a[0] = " + a[0]);
        Debug.Log("a[0] = " + a[1]);
        Debug.Log("a[0] = " + a[2]);
        //�z��̊ȒP�ȏ�����
        //�z��̗v�f���͏������̐��Ŏ����I�݌��܂�
        //b[] = 2;
        //b[] = 4�c�ȉ���
        int[]b = {2,4,6,8};
        //�z��̗v�f���̋��ߕ�
        int num = b.Length; //����4�̒l

        for (int i = 0; i < num; i++)
        {
            Debug.Log("b[" + i + "] =" + b[i]);
        }
        string[] c = { "aaa", "bbb" };
        float[] d = { 1.2f, 3.14f };
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
