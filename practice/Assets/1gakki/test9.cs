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
        //配列の簡単な初期化
        //配列の要素数は初期化の数で自動的胃決まる
        //b[] = 2;
        //b[] = 4…以下略
        int[]b = {2,4,6,8};
        //配列の要素数の求め方
        int num = b.Length; //現状4の値

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
