using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;    //UI使用

public class test12 : MonoBehaviour
{
    public Text textCmp;  //テキストクラスのコンポーネント

    //最高レアのキャラ配列
    string[] rareTable =
    {
        "ハミルトン",
        "フェルスッタペン",
        "ルクレール",
    };

    //
    const int cost = 300;  //一回に必要な金額
    int money = 0;        //実際に使ったお金

    void Start()
    {

    }

    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Return))
        {
            //ランダム値を取得
            int random = 0;
            //Random.Range()メソッド
            //1つ目の引数の値から、2つ目の値-1の
            //値の中からランダムで値を取得
            //0から9の値が今回は得られる
            random = Random.Range(0, 10);

            if (random == 0)
            {
                //0のとき
                textCmp.text += "10%の当たりですヨ\n";
                //アタリキャラも追加
                textCmp.text += DispRareString();
                textCmp.text += "\n";

            }
            else if (random <= 2)
            {
                //1,2のとき
                textCmp.text += "20%の当たりですヨ\n";
            }
            else
            {
                //それ以外
                textCmp.text += "外れですヨ;(\n";
            }
            Debug.Log(random);

            //かかった金額を計算
            money += cost;
        }
        //スペースを押したら金額を表示
        if (Input.GetKeyDown(KeyCode.Space))
        {
            textCmp.text += "使ったお金は" + money + "円\n";
        }
    }
    //最高レアをランダムで取得するメソッド
    string DispRareString()
    {
        //配列の数を取得
        int num = rareTable.Length;
        int random = Random.Range(0, num);
        //配列の文字を返却
        string str = rareTable[random];
        //文字を返却
        return str;
    }
}