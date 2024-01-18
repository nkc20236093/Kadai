using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;   //UI関連を使う 

public class Test8 : MonoBehaviour
{
    Text textComponent;  //テキストコンポーネント
    void Start()
    {
        //コンポーネントを取得して、変数に入れる
        textComponent = GetComponent<Text>();
        //クラスの変数にドット演算子を使うと
        //クラスの中身にアクセス出来る

        textComponent.text = "多重ループのテスト";
        //改行する場合、改行文字(\n)を入れる
        textComponent.text += "\n";
        //文字追加(足す)
        textComponent.text += "2行目に書きたい\n";

        //多重ループについて
        //九九表（途中）を作る


#if false       //1から9までループするfor文(i)
        for (int i =1; i < 10; ++i)
        {
            //for文の中のfor文
            //1から9までループするfor文(j)
            for(int j = 1;j < 10; ++j)
            {
                int sum = i * j;
                //整数型の変数を文字に変換
                //ToStringで文字列に変換し、
                //3桁で表示するように
                string str = sum.ToString("00");
                str += " ";
                //テキスト設定
                textComponent.text += str;


            }
            //改行
            textComponent.text += "\n";

        }
#endif

        //三角形を作りたい
        //1行目に文字を1つ
        //2行目にもじを2つ
        //3行目に文字を3つにしたい
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < (i + 1); ++j)
            {
                textComponent.text += "■";
            }
            textComponent.text += "\n";
        }
    }


}