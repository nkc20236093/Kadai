using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class test25_sub : MonoBehaviour
{
    // 課題25
    //
    // Shape(形状）という抽象クラスを作成
    // Shapeは上書きを前提とするAreaメソッドを持つ
    // Areaメソッドは返却値が実数型、引数は無し

    class Shape
    {
        public virtual int Area(float a ,float b)
        {
            return (int)a;
        }
    }

    // Circle（円）クラスを作成（Shapeを継承）
    // メンバ変数に実数型の半径を持つ
    // コンストラクタで半径を設定
    // Areaメソッドをオーバーライドして、面積を計算
    class Circle : Shape
    {
        public int radius;
        public override int Area(float a , float b)
        {
            radius = (int)a;
            return (int)a;
        }
    }

    // Rectangle(矩形）クラスを作成(Shapeを継承）
    // メンバ変数に実数型の幅、高さを持つ
    // コンストラクタで幅、高さを設定
    // Areaメソッドをオーバーライドして、面積を計算
    class Rectangle : Shape
    {
        public int width;
        public int length;
        public override int Area(float a, float b)
        {
            width = (int)a;
            length = (int)b;
            float c = a * b;
            return (int)c;
        }
    }

    //
    // test25_subのStartメソッド内で、
    // CircleとRectangleのインスタンスを生成、
    // 面積を表示する
    // 例）※あくまで例なんで参考程度でOK
    // double c = c1.Area();
    // Debug.log("円の面積は" + c);
    // Start is called before the first frame update
    void Start()
    {
        Circle circle = new Circle();
        double c = circle.Area(5, 0);
        Debug.Log($"円の面積は{c * Mathf.PI}");

        Rectangle rectangle = new Rectangle();
        double r = rectangle.Area(5, 10);
        Debug.Log($"短形の面積は{r}");
    }
}
