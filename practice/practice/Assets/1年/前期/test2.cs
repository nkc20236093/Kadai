using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class test2 : MonoBehaviour
{
    int b = 0;
    //変数bはクラス内で全てで使える
    // Start is called before the first frame update
    void Start()
    {
        //intはintegerの略、整数のこと
        int i = 100;
        //flat 少数を扱う型
        //foatの型だと分かるよう、最後にfをつける
        float f = 3.12f;
        //double 　少数を扱う型
        //floatより大きな変数を扱うときに使う
        double d = 3.14159265;
        //string　文字列を扱う型
        string s = "文字列です";

        int a = 10;
        Debug.Log(a);
        //debug.logは変数も文字列も表示できる
        //文字数と変数を両方表示したいときや、
        //複数文字を表示するときは「＋」で結合する
        Debug.Log("整数a =" + a);
        Debug.Log("整数a =" + b);
        Debug.Log("整数f =" + f);
        Debug.Log("整数i =" + i);
        Debug.Log("整数s =" + s);
    }

    // Update is called once per frame
    void Update()
    {
        b = b + 1;
        Debug.Log("変数b =" + b);
    }
}
