using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;

public class test2_sub : MonoBehaviour
{
    //問題1
    //整数型の変数「num」を宣言し、125の値で初期化
    //unityのコンソールに
    //numの値は125です
    //となるように表示。(関数を使って)
    
    //問題2
    //実数型の変数を「a」、「b」、「c」をそれぞれ宣言し、
    //aに2.5、bに3.6、cに4.3を代入し
    //Unityのコンソールに
    //a=2.5  b =3.6 c =4.3
    //となるように表示（関数を使う）

    //問題3
    //問題2で作成したa,b,c
    //を足した値を代入する変数「sum」を作成し、
    //Unityのコンソールに
    //sumの値は〇〇（計算結果）です。
    //となるように表示（変数を使う）

    int num = 125;
    float a = 2.5f;
    float b = 3.6f;
    float c = 4.3f;

    // Start is called before the first frame update
    void Start()
    {
        float sum = a + b + c;
        Debug.Log("numの値は" + num);

        Debug.Log("aの値は" + a);
        Debug.Log("bの値は" + b);
        Debug.Log("cの値は" + c);
        

        Debug.Log("sumの値は" + sum);
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
