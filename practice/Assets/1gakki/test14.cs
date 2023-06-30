using System.Collections;
using System.Collections.Generic;
using System.Data;
using UnityEngine;

public class test15 : MonoBehaviour
{

    void Start()
    {
        Count(10);
        Count(10, 20);
        Count(3.14, 4.2);
        Count(10, 3.14);
        Count(1, 2, 3, 4);  //引数4つ
    }
    //メソッドのオーバーロード
    //オーバーロードとは
    //同じ名前のメソッドで
    //シグネチャが違うメソッドを定義すること
    //シグネチャとは
    //メソッドの戻り値、引数のこと
    int Count(int a)
    {
        Debug.Log(a);
        return a;
    }
    int Count(int a, int b)
    {
        int sum = a + b;
        Debug.Log(sum);
        return sum;
    }
    double Count(double a, double b)
    {
        double sum = a + b;
        Debug.Log(sum);
        return sum;
    }
    //
    int Count(int a, int b, int c, int d = 10)
    {
        int sum = a + b + c + d;
        {
            Debug.Log(sum);
            return sum;
        }
    }
}
