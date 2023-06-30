using System.Collections;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Security.Cryptography;
using Unity.VisualScripting;
using UnityEngine;

public class test7_sub : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        //課題7-1
        //for文を使って
        //整数型の変数aの値を
        //0から5になるように
        //インクリメントし
        //インクリメントした後は
        //「aの値は〇〇です」となるように表示
        int a = 0;
        for(int i = 0; a < 5; i++)
        {
            a++;

            Debug.Log("aの値は" + a);
        }

        //課題7-2
        //整数型の変数bを10で初期化
        //whiled文を使ってbをデクリメントし
        //デクリメントした後に
        //「bの値は○○です」となるように表示
        //bが0になったらwhile文を終了させる

        int b = 10;
        do
        {
            b--;
            Debug.Log("bの値は" + b);
        } while (b != 0);

        //課題7-3
        //1から10の値を全て足して
        //計算結果を変数sumに足して
        //「1から10の値を足した値は○○です」
        //なお、繰り返し文を使って
        //10回処理を繰り返した後に計算結果を出すこと

        int f = 0;
        int sum = 0;
        while (true)
        {

            f++;
            sum = sum + f;
            if (f == 10)
            {
                Debug.Log("１から１０の値を足した値は" + sum + "です");
                break;
            }
        }
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
