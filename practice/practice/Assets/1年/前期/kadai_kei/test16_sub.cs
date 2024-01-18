using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;

public class test16_sub : MonoBehaviour
{
    public int kaijou;
    // Start is called before the first frame update
    void Start()
    {
        // 課題16
        // public変数のx,yを作成(値は好きな値でOK)
        // ①二つの引数の加算結果を返却するメソッドAddを作成
        // Startメソッドで呼び出し、xとyの加算結果をDebug.Logで表示
        // 例）xとyの加算結果は〇〇

        
        Debug.Log("xとyの加算結果は" + Add(4,5));
        // ②底辺と高さを引数に三角形の面積を求めるメソッドTrianleを作成
        // Startメソッドで呼び出し、底辺x高さyの三角形の面積をDebug.Logで表
        // 例）底辺x高さyの三角形の面積は○○

        
        Debug.Log("底辺4高さ5の三角形の面積は" + Trianle(4,5));
        // ③半径を引数に円の面積を求めるメソッドCircleを作成
        // Startメソッドで呼び出し、半径xの円の面積をDebug.Logで表示
        // 例）半径xの円の面積は○○
        
        Debug.Log("半径5の円の面積は" + Circle(4) );
        // ④引数の階乗を求めるメソッドFactrialを作成
        // Startメソッドで呼び出し、xの階乗結果をDebug.Logで表示
        // 例）xの階乗結果は○○
        
        Debug.Log("xの階乗結果は" + Factrial(5));
    }

    int Add(int x ,int y)
    {
        int sum = x + y;
        return sum;
    }
    int Trianle(int x , int y)
    {
        int menseki = x * y / 2;
        return menseki;
    }
    float Circle(int x)
    {
        float en = x * x * Mathf.PI;
        return en;
    }
    public static long Factrial(int n)
    {
        if (n == 0)
            return 1;
        return n * Factrial(n - 1);
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
