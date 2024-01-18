using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class test5 : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
     //if文について
     if(true)
        {
            Debug.Log("if文がtrueなので実行");
        }
     //if(false)
     //   {
     //       Debug.Log("if文がfalseなので実行しない");
     //   }
     //else文について
     if(false)
        {
            Debug.Log("実行されない");
        }
        else
        {
            Debug.Log("else文が実行される");
        }
        //比較演算を用いたif文
        int a = 10, b = 5;
        if (a > b)
        {
            Debug.Log("aはbより大きい");
        }
        else
        {
            Debug.Log("bがaより大きい");
        }
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
