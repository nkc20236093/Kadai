using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class test26_sub : MonoBehaviour
{
    // 課題26　インターフェースクラス

    // 形状関連のインターフェースを作成
    // ①Areaというインターフェースクラスを作成
    // 面積を求めるメソッドCalcArea()を定義
    // ②Printというインターフェースクラスを作成
    // 形状の情報を表示するメソッドのPrintInfo()を定義
    public interface Area
    {
        public void CalcArea();
    }
    public interface Print
    {
        public void PrintInfo();
    }
    // 円クラス（Circleクラス）を作成
    // AreaとPrintのインターフェースを継承
    // メンバ変数に実数型の半径を持つ
    // メンバ変数に実数型の面積を持つ
    // CalcAreaメソッドでは面積の計算をする
    // PrintInfoメソッドでは半径、面積の表示をする
    public class Circle : Area, Print
    {
        float radius = 5;
        float area;
        public void CalcArea()
        {
            area = Mathf.Pow(radius, 2) * Mathf.PI;
        }
        public void PrintInfo()
        {
            Debug.Log($"半径：{radius}");
            Debug.Log($"面積：{area}");
        }
    }
    // 矩形クラス（RectAngleクラス）を作成
    // AreaとPrintのインターフェースを継承
    // メンバ変数に実数型の幅、高さを持つ
    // メンバ変数に実数型の面積を持つ
    // CalcAreaメソッドでは面積の計算をする
    // PrintInfoメソッドでは半径、幅、高さ、面積の表示をする
    public class RectAngle : Area, Print
    {
        float w = 5;
        float h = 10;
        float area;
        public void CalcArea()
        {
            area = w * h;
        }
        public void PrintInfo()
        {
            Debug.Log($"幅：{w}");
            Debug.Log($"高さ{h}");
            Debug.Log($"面積{area}");
        }
    }
    // test26_subのStartメソッド内で、
    // Circleクラス、RectAngleクラスの実体を作成
    // CalcAreaメソッド、PrintInfoメソッドを呼び出す

    // Start is called before the first frame update
    void Start()
    {
        Circle c = new Circle();
        c.CalcArea();
        c.PrintInfo();
        RectAngle r = new RectAngle();
        r.CalcArea();
        r.PrintInfo();
    }
}
