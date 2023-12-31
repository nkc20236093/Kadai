using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;
using UnityEngine.AI;
using static Unity.Collections.Unicode;

public class test20_sub : MonoBehaviour
{
    [Serialize] public int m = 1;

    // 課題20
    // 1から12の値を持つ列挙型、Monthを作成
    // 1...January, 2...February..といったような型を作る
    enum Month
    {
        none,
        January,
        February,
        March,
        April,
        May,
        June,
        July,
        August,
        September,
        October,
        November,
        December,
    };

    // int型の変数xを作成し、自分の誕生月をMonth型の列挙子で
    // キャストを用いて代入
    // Debug.logでxを表示
    // 表示例）誕生月は10

    // 整数型の変数mに好きな整数を入力し、
    // その月をMonth型の列挙子に変換して表示する
    // なお、０や９９といった値が入力された場合、
    // 無効な値ですと表示する
    // 表示例）
    // mが0の場合＞無効な値です
    // mが2の場合＞February
    string[] MonthTable =
    {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December",

    };
    // Start is called before the first frame update
    void Start()
    {
        int x = (int)Month.May;
        Debug.Log($"誕生日は{x}月");


        if (m > 0 && m <= 12)
        {
            Month month = (Month)(int)m;
            Debug.Log(month);
        }
        else
        {
            Debug.Log($"{m}は無効な値です");
        }
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
