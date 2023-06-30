using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class test13_sub : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        // 課題１４－１
        // 再帰メソッドを作成
        // 戻り値：なし
        // 名前：NumberDisp
        // 引数：整数型のn
        // 再帰呼び出しをして、
        // 引数の数値を０になるまで順番に表示
        // 例)NumberDisp(5)
        // 5,4,3,2,1
        NumberDisp(5);

        // 課題１４－２
        // 再帰メソッドを作成②
        // 戻り値：int
        // 名前：NumberAdd
        // 引数：整数型のn
        // 再帰呼び出しを行い、
        // 引数の数値が０になるまで値をデクリメントし、
        // 全ての値の合計値を返却する
        // 例）Debug.log(NumberAdd(10))で55と表示される
        // 10+9+8+7+6+5+4+3+2+1が実行される
        int sum = NumberAdd(10);
        Debug.Log(sum);
    }

    // Update is called once per frame
    void Update()
    {
        
    }
    
    void NumberDisp(int n)
    {
        if (n <= 0)
        {
            return;
        }

        Debug.Log(n);
        NumberDisp(n - 1);
    }
    int NumberAdd(int n)
    {
        if (n <= 0)
        {
            return 0;
        }

        return n + NumberAdd(n - 1);
    }
}
