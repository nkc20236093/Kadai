using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;

public class test3_sub : MonoBehaviour
{
    //練習問題1
    //変数xに10.5、変数yに3.14
    //計算結果を入れる変数sumを作成
    //x + y = 〇〇(計算したsumの値)
    //x - y = 〇〇(計算したsumの値)
    //x * y = 〇〇(計算したsumの値)
    //x / y = 〇〇(計算したsumの値)
    //x % y = 〇〇(計算したsumの値)
    //となるよう、Debug.logを使って表示する

    //int + floatの計算は勝手にfloatになる
    //このように勝手に型が変更されることを
    //暗黙の型変換という

    float x = 10.5f;
    float y = 3.14f;
    float sum;
    // Start is called before the first frame update
    void Start()
    {
        sum = x + y;
        Debug.Log("x + y ="  + sum);

        sum = x - y; 
        Debug.Log("x - y =" + sum);

        sum = x * y;
        Debug.Log("x * y =" + sum);
        sum = x / y;
        Debug.Log("x / y =" + sum);

        sum = x % y;
        Debug.Log("x % y =" + sum);
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
