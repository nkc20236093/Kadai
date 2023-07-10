using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;
using UnityEngine.SocialPlatforms.Impl;

public class test19_sub : MonoBehaviour
{
    
    // Start is called before the first frame update
    void Start()
    {
        int[] score = new int[5];
        // 課題19　配列についてのおさらい問題
        // ①要素数が5の整数型配列scoreを宣言
        // ②繰り返し文を使って、配列の要素０から、
        // 要素４までに、乱数を使って２桁の値を代入
        for (int i = 0; i < score.Length; i++)
        {
            score[i] = Random.Range(10, 100);
        }
        //score[1] = Random.Range(10, 99);
        //score[2] = Random.Range(10, 99);
        //score[3] = Random.Range(10, 99);
        //score[4] = Random.Range(10, 99);
        // ③配列の要素を全て表示
        // 表示例）
        // score[0] = 〇〇
        // score[1] = 〇〇...（以下略）
        for (int i = 0; i < score.Length; ++i)
        {
            Debug.Log("score["+i+"]" + score[i]);
        }
        
        //Debug.Log("score[1]" + score[1]);
        //Debug.Log("score[2]" + score[2]);
        //Debug.Log("score[3]" + score[3]);
        //Debug.Log("score[4]" + score[4]);
        // ④scoreの全ての要素の合計値を表示
        int goukei = score[0]+ score[1]+ score[2]+ score[3]+ score[4];
        Debug.Log("score配列の合計値は" + goukei);
        // 表示例）score配列の合計値は〇〇
        // ⑤scoreの平均値を表示
        int heikinn = (score[0] + score[1] + score[2] + score[3] + score[4]) / 5;
        Debug.Log("score配列の平均値は" + heikinn);
        // 表示例）score配列の平均値は〇〇
        // ⑥score配列の並びを反転させた後、
        // score配列の要素を全て表示
        // 表示例）
        // score配列を反転しました。
        // score[0] = 〇〇
        // score[1] = 〇〇...
        // ※反転の例
        // {22, 31, 55, 0, 99}の配列があったとしたら
        // {99, 0, 55, 31, 22}という配列になるようにする
        System.Array.Reverse(score);
        Debug.Log("score配列を反転しました。");
        for (int i = 0; i < score.Length; i++)
        {
            Debug.Log("score[" + i + "]=" + score[i]);
        }
        // EX（出来たら加点、出来なくても提出してよい）
        // 昇順、降順に並び変えて表示

        //昇順
        Debug.Log("昇順に変更");
        System.Array.Sort(score);
        for(int i = 0;i < score.Length; i++)
        {
            Debug.Log("score[" + i + "]" + score[i]);
        }
        //降順
        Debug.Log("降順に変更");
        System.Array.Sort(score);
        System.Array.Reverse(score);
        for (int i = 0; i < score.Length; i++)
        {
            Debug.Log("score["+i+"]" + score[i]);
        }
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
