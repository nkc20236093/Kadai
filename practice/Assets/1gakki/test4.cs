using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class test4 : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        //複合演算子について
        int a = 5, b = 3;
        int sum = 0;

        //複合代入演算子
        sum += a;   // += sum = sum + a;
        Debug.Log("sum=" + sum);
        sum -= b;   // -= sum = sum - b;
        Debug.Log("sum=" + sum);
        sum *= a;   // *= sum = sum * a;
        Debug.Log("sum=" + sum);
        sum /= b;   // /= sum = sum / b;
        Debug.Log("sum=" + sum);

        sum++; //インクリメント sum += 1
        Debug.Log("sum = " + sum);
        sum--; //デクリメント sum -= 1
        Debug.Log("sum = " + sum);

        // bool型（真偽を扱う型）
        // c♯ではtrueかfalseかのどちらか
        // 二つを扱う型
        //数値を表すとfalse = 0 true = 1

        bool flag = false;


        //等価演算子 ==
        //aとbが等しいならtrue、違うならfalse
        //を返却する

        flag = (a == b);
        Debug.Log("flag = " + flag);

        // !=
        // aとbが等しくなければtrue、等しければfalse
        flag = (a != b);
        Debug.Log("flag =" + flag);

        //aとbを比較するような演算子を
        //比較演算子という
        //「<」「>」、「<=」「>=」
        //などもある

        flag = (a < b);
        Debug.Log("flag = " + flag);
        flag = (a > b);
        Debug.Log("flag = " + flag);
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
