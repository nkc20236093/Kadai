using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class test12_sub : MonoBehaviour
{
    public Text textCmp;
    public Text moneyTextCmp;
    // 課題12
    // ガチャプログラムを作成しよう
    // 条件１：１０連ガチャの実装
    // 条件２：ガチャで使った金額を表示する
    // 条件３：確率は元となるゲームを参考に実装
    // ※特に元のゲームを思いつかない場合はウマ娘を参考に
    // ウマ娘の場合
    // 星3 = 3%  星2 = 18% 星1 = 79%
    // 条件４：文字列配列を使って、引いたモノを表示
    // ※最高レアだけで良い（数が多い場合は頑張りすぎないこと）
    // 条件５：表示はUnityのゲーム画面上に表示すること

    string[] rareTable =
    {
        "LR魔人ブウ(悪)",
        "小鳥悟空",
        "LR合体ザマス"
    };

    const int cost = 5; // 一回に必要な金額
    int money = 0;　　　　// 実際に使ったお金

    void Start()
    {
    }


    void Update()
    {
        // エンターキーを入力したとき
        //if (Input.GetKeyDown(KeyCode.Return))
        //{
        //    for (int i = 0; i < 10; i++)
        //    {
        //        gacha();
        //    }
        //}
    }

    // 最高レアをランダムで取得するメソッド
    public string DispRareString()
    {
        int num = rareTable.Length;
        // ランダムの値を取得
        int random = Random.Range(0, num);
        // ランダムで選ばれた文字を取得
        string str = rareTable[random];
        // 文字を返却
        return str;

    }

    public void gacha() {
        // ランダム値を取得
        int random = 0;
        // Random.Range() メソッド
        // 1つ目の引数の値から、2つ目の引数の値-1の
        // 値の中からランダムで値を取得
        // 0～9の値が今回は得られる
        random = Random.Range(0, 10);

        if (random == 0)
        {
            // 0のとき
            //textCmp.text += "SSR超サイヤ人悟空\n";
            // 当たりキャラを追加で表示
            textCmp.text += DispRareString();
            textCmp.text += "\n";  // 改行

            //Debug.Log("10の1の確立ですよ");  // 10％
        }
        else if(random <= 3) 
        {
            //textCmp.text += "LR合体ザマス\n";
            textCmp.text += DispRareString();
            textCmp.text += "\n";
        }
        else
        {
            //textCmp.text += "小鳥悟空";
            textCmp.text+= DispRareString();
            textCmp.text += "\n";
        }

    }
    public void gacha10()
    {
        //テキストをクリア
        textCmp.text = "";

        //10連
        for (int i = 0; i < 10; i++)
        {
            gacha();
            money += cost * i;
            moneyTextCmp.text = "使った金額" + money.ToString() + "円";
        }
    }

    public void gacha1()
    {
        //テキストのクリア
        textCmp.text = "";

        gacha();
        money += cost;
        moneyTextCmp.text =  "使った金額"+money.ToString()+"円";
    }

}