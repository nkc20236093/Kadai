using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class test11 : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        //メソッドとは？
        //戻り値＋メソッド名（引数）｛関数の中身｝

        DispText();
        DispText2("DispText呼び出し");//引数を設定

        int max = 0;
        max = Max(10, 20);
        Debug.Log(max);
    }

    //　戻り値：void　名前:DispText　引数:なし
    void DispText()
    {
        Debug.Log("メソッドの文字表示");
    }
    //戻り値:void 名前:DispText2 引数:あり
    void DispText2(string s)
    {
        Debug.Log(s);
    }
    //最大値を求めるメソッド
    //戻り値：int　名前：Max　引数：整数型
    int Max(int a , int b)
    {
        if (a > b) 
        {
            return a;        
        }
        else
        {
            return b;
        }
    }
    // Update is called once per frame
    void Update()
    {
        
    }
}
