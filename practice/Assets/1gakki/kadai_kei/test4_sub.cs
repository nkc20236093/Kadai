using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;

public class test4_sub : MonoBehaviour
{
    float a = 7.5f;
    float b = 3.14f;
    float sum = 0;

    // Start is called before the first frame update
    void Start()
    {
        //課題4-1
        // 変数aを7.5、変数b3.14で初期化
        // 計算結果を入れる変数sumを0で初期化
        // 複合代入演算子を用いて
        // sumにaを加算したものを
        // 「sum =　〇〇」となるように表示
        //　sumにbを減算したものを
        // 「sum = 〇〇」となるように表示

        sum += a;
        Debug.Log("sum = " + a);
        sum -= b;
        Debug.Log("sum =" + b) ;

        //課題4-2
        //変数aをインクリメントし、
        //変数bをデクリメントする。
        //a + bの値をsumに代入し
        //「sum =　○○」となるように表示

        a++;
        b--;
        sum = a + b;
        Debug.Log("sum =" + sum );

        //課題4-3
        //bool型の変数flagを宣言し、falaseで初期化
        //等価演算子、または不等価演算子を用いて
        //aとbを比較し、その結果をflagに代入し
        //flagを真の値になるようにして
        //「flag = true」となるように表記
        //※表示の際はflag変数を使うこと

        bool flag = false;

        flag = (a >= b);
        Debug.Log("flag =" + flag);

    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
