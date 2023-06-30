using System.Collections;
using System.Collections.Generic;
using TMPro;
using Unity.VisualScripting;
using UnityEngine;

public class test9_sub : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        // 課題9-1
        // 1,2,3,4,5の要素を持つ
        // 整数型の配列aを作成し、
        // for文を使って、aの配列の値を全て表示する

        int[] a = { 1, 2, 3, 4, 5, };
        for (int i = 0; i < a.Length; i++)
        {
            Debug.Log("a [" + i + " ] =" + a[i]);
        }

        // 課題9-2
        // 春、夏、秋、冬という文字列の要素を持つ
        // 文字列型の配列bを作成し、
        // for文を使って、bの配列の文字を全て表示する
        // その後、
        // 「好きな季節は〇〇です」※〇〇は配列を使う
        // と表示する

        string[] b = { "春", "夏", "秋", "冬" };
        for (int w = 0; w < b.Length; ++w)
        {
            Debug.Log(b[w]);
        }
        Debug.Log("好きな季節は" + b[3] +"です");

        // 課題9-3
        // 20,42,58,31,68
        // 上記の要素を持つ整数型の配列cを作成し、
        // 配列cの全ての値を計算し、
        // 「配列cの要素を足した合計は○○」
        // 配列cの全ての値の平均値を計算し
        // 「配列cの要素の平均値は○○」
        // となるように表示 ※〇〇は変数を使った計算結果

        int[] c = { 20, 42, 58, 31, 68 };
        int lenghe = c.Length;
        int sum = 0;
        for(int q = 0; q < lenghe; ++q) 
        {
            sum += c[q];
        }
        Debug.Log("配列cの要素を足した合計は" + sum );
        Debug.Log("配列cの要素の平均値は"+ sum/5);

         
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
