using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class test5_sub : MonoBehaviour
{
    int a = 10,b = 5 ,c = 20;
    // Start is called before the first frame update
    void Start()
    {
        //課題5-1
        //整数型のaに10、bに5、cにを入れて宣言20
        //if文を用いてaとbの大きさを比較し、結果が真であれば
        //「aがbよりも大きい」と表示
        //結果が偽であれば
        //「bがaよりも大きい」と表示

        if (a>b)
        {
            Debug.Log("aがbよりも大きい");
        }
        else if (a<b)
        {
            Debug.Log("bがaよりも大きい");
        }

        //課題5-2
        //a * 2の値とcの値をの大きさを
        //等しいかどうか比べ、結果が真であれば
        //「a * 2とcは等しい」と表示
        //結果が偽であれば
        //「a*2とcは等しくない」と表示

        if (a*2 == c)
        {
            Debug.Log("a * 2とcは等しい");
        }
        else
        {
            Debug.Log("a*2とcは等しくない");
        }

        //課題5-3
        //変数a,b,cで一番大きい数値を
        //if文を使って求め
        //「一番大きい値は〇〇です」となるように表示

        int ookii = a;

        if (b > ookii)
        {
            ookii = b;
        }

        else if (c > ookii)
        {
            ookii = c;
        }

        if(c < ookii && b > ookii)
        {
            ookii = a;
        }

        Debug.Log("一番大きい値は" + ookii);
    }
}
