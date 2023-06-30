using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class test6 : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        int a = 1;
        if (a == 1)
        {
            Debug.Log("aは1です");
        }

        else if (a == 2)
        {
            Debug.Log("aは2です");
        }

        else if (a <= 5)
        {
            Debug.Log("aは5以下ですです");
        }

        else
        {
            Debug.Log("それ以外");
        }

        //複数の条件分岐を扱うときは
        //else　if文を使う
        //else　if文を使った後に書かれるelse文は
        //全てのif文の条件式に当はまらなかった時
        //実行される

        //swicth文
        int b = 1;
        switch (b)
        {
            case 0:
                Debug.Log("bは0です");
                break;  //break文はswicth文を抜ける
            
            case 1:
                Debug.Log("bは1です");
                break;

            default:
                Debug.Log("それ以外です");
                break;

        }
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
