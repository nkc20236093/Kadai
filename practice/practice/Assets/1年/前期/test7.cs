using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;

public class test7 : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        //繰り返し文

        //for文
        //初期化と継続条件と後処理
        int a = 0;
        for (int i = 0; i < 5; i++)
        {
            a++;
            Debug.Log("a =" + a);
            //後処理はfor文の最後で実行
            Debug.Log("i = " + i);
        }
        //{}がないとセミコロンまで繰り返す
        //{}がないことによるエラーが起きやすいため
        //{}で基本的に囲むことにする
        //for (int i = 0; < 5; **!)
        //    Debug.Log("I = " + i);
        //    Debug.Log("繰り返さない");

        //do while文
        //do{}文の中身を実行後
        //while(条件式)文がtrueの間
        //do{}文を繰り返す
        int b = 5;
        do
        {
            b--;
            Debug.Log("b =" + b);
        } while (b != 0);

        int c = 0;
        while (c != 0);
        {
            Debug.Log("c = " + c);
        }
        // 無限ループ
        int d = 0;
        while (true)
        {
            ++d;
            Debug.Log("d=" + d);
            if (d > 10000)
            {
                //break文
                //forやwhile文を終了する
                //　※{}の外まで処理を移動
                break;
            }
        }
    }

    //繰り返し分の使い分け
    //決まった数ループさせるのは
    //for文を使う(ことが多い)
    //特殊な条件などはwhile文を使う

// Update is called once per frame
void Update()
    {
        
    }
}
