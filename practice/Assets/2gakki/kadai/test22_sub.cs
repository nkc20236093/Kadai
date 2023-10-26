using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class test22_sub : MonoBehaviour
{
    // 課題２２
    // Humanクラスの作成
    // 文字列変数name,整数型変数ageを持つ
    // (変数のアクセス指定子はprivate）
    // 引数なしコンストラクタを実装
    // nameに"無名"、ageに-1を入れる
    // 引数ありコンストラクタを実装
    // name,ageに値を設定できるようにする
    class Human
    {
        private string name;
        private int age;
        public Human() { name = "無名"; age = -1; }
        public Human(string a, int b) { name = a; age = b; }
        public string Y
        {
            get { return name; }
            set { name = value; }
        }
        public int X
        {
            get { return age; }
            set { age = value; }
        }
    }

    // Startメソッド内で、
    // Humanクラスのインスタンスを二つ作成
    // 片方は引数なし
    // もう片方は引数ありコンストラクタを呼び出し、
    // 自分の名前、年齢を入れる

    // Humanクラスにプロパティを実装
    // 名前、年齢を設定、取得できるようにする
    // Startメソッド内で、Debug.logを用いて
    // 二つのインスタンスの名前、年齢を表示する
    // 表示例）
    // 一人目の名前：無名、年齢：-1歳
    // 二人目の名前：中山亮太（自分の名前）、年齢：17歳
    // Start is called before the first frame update
    void Start()
    {
        Human human1 = new Human();
        Debug.Log("名前:" + human1.Y + ":年齢" + human1.X);
        Human human2 = new Human("滝瑛太", 17);
        Debug.Log("名前:" + human2.Y + ":年齢" + human2.X);
    }
}
