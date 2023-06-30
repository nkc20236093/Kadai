using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;

public class test14_sub : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        // 課題１５
        // メソッドのオーバーロードを使って
        // 以下のメソッドを実装
        // メソッド名：Add
        // ①int型の引数2つを受け取り、
        // 足した値を返却するメソッド
        // ②double方の引数2つを受け取り、
        // 足した値を返却するメソッド
        // ③string方の引数2つを受け取り、
        // それらの文字列を結合した文字列を返却するメソッド
        // ①～③メソッドをStartメソッドで呼び出し、
        // 呼び出した値をDebug.logで表示する
        Add(10, 20);
        Add(1.2, 3.5);
        Add("hello", "world");

    }

    int Add(int a , int b)
    {
        int sum = a + b;
        Debug.Log(sum);
        return sum;
    }
    double Add(double a, double b)
    {
        double sum = a + b;
        Debug.Log(sum);
        return sum;
    }
    string Add(string a , string b)
    {
        string sum = a + b;
        Debug.Log(sum);
        return sum;
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
