using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class test11_sub : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        // 課題11-1
        // 戻り値：なし
        // メソッド名：DispString
        // 引数：文字列型のs
        // メソッドの中身：Debug.logを使って引数を表示
        // 上記のメソッドを作成し、Startメソッドで呼びだす
        DispString("課題11-1のメソッド");
        // 課題11-2
        // 戻り値：整数型
        // メソッド名：Add
        // 引数：整数型a,b
        // メソッドの中身：引数a,bを足した値を返却
        // 上記のメソッドを作成し、
        // Startメソッドで呼び出し、戻り値をDebug.logで表示
        // 引数に入れる整数の例は10,15
        int add = 0;
        add = Add(10, 15);
        Debug.Log(add);
        // 課題11-3
        // 戻り値：整数型
        // メソッド名：Min
        // 引数：整数型のa,b,c
        // メソッドの中身：引数a,b,cを比較し、最小値を返却
        // 上記のメソッドを作成し、
        // Startメソッドで呼び出し、戻り値をDebug.logで表示
        // 引数に入れる整数の例は100, 50, 200
        int min = 0;
        min = Min(100, 50, 200);
        Debug.Log(min);
    }

    void DispString(string s)
    {
        Debug.Log(s);
    }
    int Add(int a,int b)
    {
        int sum = a + b;
            return sum;
    }
    int Min(int a ,int b,int c)
    {


        if (a < b && a < c)
        {
             return a;    
        }
        else if (b < c && b < a)
        {
            return b;
        }
        else
        {
            return c;
        }



    }
    // Update is called once per frame
    void Update()
    {
        
    }
}
