using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UIElements;

public class test10_sub : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        // 課題10-1
        // 10,32,46,59,25
        // の要素を持つ配列a,
        // 要素が5個入る配列bを作成
        // 配列aの値をbに全てコピーした後、
        // 配列bの値をfor文を使って
        // b[0] = 〇〇
        // となるように表示（全ての要素文表示）

        int[] a = { 10, 32, 46, 59, 25 };
        int[] b = new int[5];
        b = a;

        for (int i = 0; i < a.Length; ++i)
        {
            Debug.Log("b[" + i + "]=" + b[i]);
        }

        // 課題10-2
        // 配列aの要素の順番を反転させるように
        // 配列aの要素を入れ替え、
        // 配列aの値をfor文を使って
        // a[0] = 〇〇
        // となるように表示（全ての要素を表示）
        // ※〇〇は配列を使って表示
            for (int i = 0; i < a.Length / 2; ++i)
        {
            int num = a.Length - 1;
            int temp = a[i];
            a[i] = a[num - i];
            a[num - i] = temp;
        }
        for (int i = 0; i < a.Length; i++)
        {
            Debug.Log("a[" + i + "]=" + a[i]);
        }
        //表示
        for (int i = 0; i < a.Length; ++i)
        {
            Debug.Log(a[i]);
        }

        // 課題10-3
        // 要素が3*3の二次元配列cを作成
        // 二重ループを使って、
        // 1,2,3, 2,4,6, 3,6,9
        // 上記の値を配列cに順番に代入
        // ※c[0,0]→c[0,1]→c[0,2]→c[1,0]→c[1,1]...のような順番
        // for文を使って
        // 1,2,3,
        // 2,4,6,
        // 3,6,9,
        // となるように表示
        // ※配列の値を使って表示すること

        //int[,] c = new int[3, 3];
        //c[0, 0] = 0;
        //c[0, 1] = 1;
        //c[0, 2] = 2;
        //c[1, 0] = 3;
        //c[1, 1] = 4;
        //c[1, 2] = 5;
        //c[2, 0] = 6;
        //c[2, 1] = 7;
        //c[2, 2] = 8;
        //for (int i = 0; i < 3; ++i)
        //{
        //    for (int j = 0; j < 3; ++j)
        //    {
        //        Debug.Log(c[i, j]);
        //    }
        //}

        int[]q = new int[3];
        q[0] = 1;
        q[1] = 2;
        q[2] = 3;
        int[]r = new int[3];
        r[0] = 2;
        r[1] = 4;
        r[2] = 6;
        int[]s = new int[3];
        s[0] = 3;
        s[1] = 6;
        s[2] = 9;

        for (int i = 0; i < 3; ++i)
        {
            Debug.Log(q[i] + "," + r[i]+","+ s[i]); 
        }
    }
}
