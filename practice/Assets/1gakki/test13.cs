using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class test13 : MonoBehaviour
{

    void Start()
    {
        //再帰メソッド
        Repeat(5);

        //階乗の呼び出し
        Debug.Log(factrial(5));
    }

    void Update()
    {

    }

    //再帰呼び出しメソッド
    //再帰メソッドとは
    //メソッドの中で自分のメソッドを呼び出すメソッド
    int Repeat(int num)
    {
        if (num != 0)
        {
            num--;
            Debug.Log(num);
            Repeat(num); //自身のメソッドを呼び出し
        }
        return 0;
    }

    //階乗を求める回帰メソッド
    int factrial(int num)
    {
        int sum;
        if (num == 0)
        {
            return 1;
        }
        sum = factrial(num - 1);   //再帰呼び出し
        return num * sum;
    }
}