using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UIElements;

public class test6_sub : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        //課題6-1
        //整数方の変数aを10で初期化
        //else id文を使って
        //aが0の時「aは0です」
        //aが10より小さいとき「aは10より小さいですです」
        //aが10の時「aは10です」
        //aが10以上の時「aは10以上です」
        //と表示されるようにする

        int a = 10;
        if (a == 0)
        {
            Debug.Log("aは0です");
        }
        else if (a <= 10) 
        {
            Debug.Log("aは10より小さいです");
        }
        else if (a == 10)
        {
            Debug.Log("aは10です");
        }
        else
        {
            Debug.Log("aは10以上です");
        }

        //課題6-2
        //整数型の変数bを5で初期化
        //switch文を使って
        //bが0の時「bは0です」
        //bが2の時「bは2です」
        //bが5の時「bは5です」
        //bが上記の条件に当てはまらないとき
        //「bの値は当てはまりませんでした」
        //と表示されるようにする

        int b = 5;
        switch(b)
        {
            case 0:
                Debug.Log("bは0です");
                break;
            case 2:
                Debug.Log("bは2です");
                break;
            case 5:
                Debug.Log("bは5です");
                break;
            default:
                Debug.Log("bの値は当てはまりませんでした");
                    break;
        }

        //課題6-3
        //文字列型の変数sを作成
        //sにabcを代入
        //swicth文を使って
        //sがabcの時「sは○○です」
        //sがdefまたはghiの時
        //「sはdefかghiのどちらかです」と表示
        //sがそれ以外の時
        //「sがそれ以外の時
        //「sの文字列は条件にあてはまりませんでした」
        //と表示されるようにする

        string s = "abc";
        switch(s)
        {
            case "abc":
                Debug.Log("sは" + s);
                break;

            case "def":
            case "ghi":
                Debug.Log("sはdefかghiのどちらかです");
                break;

            default:
                Debug.Log("sの文字列は条件にあてはまりませんでした");
                break;
        }
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
