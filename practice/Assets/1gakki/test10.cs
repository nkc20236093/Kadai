using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class test10 : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        //配列のコピー
        int[] a = { 1, 2, 3, 4, 5 }; //5つの要素を持つ配列a
        int[] b = new int[5];　//5つの要素を入れれる配列b

        b = a;

        for (int i = 0; i < a.Length; ++i)
        {
            Debug.Log("b[" + i + "]=" + b[i]);
        }
        //配列の要素を一つずつコピー
        //配列のコピーの基本はこれ
        for (int i = 0; i < a.Length; ++i)
        {
            b[i] = a[i];
        }

        //配列の入れ替え
        int[] c = { 100, 75, 50, 25, 0 };
        //順番の入れ替え
        for (int i = 0; i < c.Length; ++i)
        {
            //
            int num = c.Length - 1;
            int temp = c[i];//値を一時保存
            c[i] = c[num - i];//入れ替え
            c[num - i] = temp;//保存した値を入れる
        }
        //表示
        for (int i = 0; i < c.Length; ++i)
        {
            Debug.Log(c[i]);
        }

        //多次元配列
        //[,]で多次元を指定
        int[,] d = new int[3, 3];
        d[0, 0] = 0;
        d[0, 1] = 1;
        d[0, 2] = 2;
        d[1, 0] = 3;
        d[1, 1] = 4;
        d[1, 2] = 5;
        d[2, 0] = 6;
        d[2, 1] = 7;
        d[2, 2] = 8;
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                Debug.Log("d[" + i + "," + j + "] = " + d[i, j]);
            }
        }
        //三次元配列もある（あんまり使わない）

        //二次元配列の初期化
        int[,] f = { { 1, 2, 3 }, { 4, 5, 6 } };
        for (int i = 0; i < 2; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                Debug.Log(f[i, j]);
            }
        }
        Debug.Log(f.GetLength(0));
        Debug.Log(f.GetLength(1));
    }


}
