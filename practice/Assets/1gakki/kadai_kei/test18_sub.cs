using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;

public class test18_sub : MonoBehaviour
{
    public int targetValue = 7;
    // Start is called before the first frame update
    void Start()
    {
        //課題１８
        //②エンターキーを入力したとき，
        //１～６の値がランダムでDebug.Logを表示する
        
        // ②スペースキーを入力した時、
        // １～６の値をランダムで２回表示し、その後
        // その値を足した値を表示する
        // 表示例）ダイス二つの合計値は〇〇です。

        // ③ ②で表示したランダムの値が同じ値だった場合
        // ゾロ目ですと表示する。
        // 表示例）1,1のゾロ目です！

        // ④左シフトキーを入力した際、
        // 二つのサイコロの目の合計値が７になる
        // 組み合わせを全て表示する。
        // 合計値の組み合わせを表示する際は
        // 多重ループを用いること。
        // 表示例）
        // 合計値が７になる組み合わせは
        // 1+6
        // 2+5....（以下略
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Return))
        {
            int toi1 = Random.Range(1, 7);
            Debug.Log("ダイスの目は" + toi1);
        }
        if (Input.GetKeyDown(KeyCode.Space))
        {
            int toi2_1= Random.Range(1, 7);
            int toi2_2 = Random.Range(1, 7);
            if (toi2_1 == toi2_2)
            {
                Debug.Log(toi2_1 + "," + toi2_2 + "のゾロ目です");
            }
            int toi2 = toi2_1 + toi2_2;
            Debug.Log("ダイス二つの合計値は"+ toi2 +"です");
        }
        if(Input.GetKeyDown(KeyCode.LeftShift))
        {
                Debug.Log("合計値が" + targetValue + "になる組み合わせは");
                for (int i = 1; i < 6; i++)
                {
                    for (int j = 1; j <= 6; j++)
                    {
                        if (i + j == targetValue)
                        {
                            Debug.Log(i + "+" + j);
                        }
                    }
                }
        }
        

    }
}
