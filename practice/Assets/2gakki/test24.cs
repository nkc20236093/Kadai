using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;

public class test24 : MonoBehaviour
{
    //継承
    class Human  //人間クラス
    {
        private string name;   //名前
        private int age;       //年齢
        private string gender; //性別
        //メソッド
        public Human()  //引数なしコンストラクタ
        {
            name = "名無し";
            age = 0;
            gender = "不明";
        }
        public Human(string n, int a, string g)  //引数ありコンストラクタ
        {
            name = n;
            age = a;
            gender = g;
        }

        public void DispInfo()  //情報を表示するメソッド
        {
            Debug.Log("名前" + name);
            Debug.Log("年齢" + age);
            Debug.Log("性別" + gender);
        }
    }

    //学生クラス(Humanを継承したクラス、派生クラスと呼ぶ)
    //クラス定義:継承したいクラス名
    class Student : Human
    {
        private int studentID;    //学籍番号
        private string className; //クラス名
        //メソッド
        public Student()  //引数なしコンストラクタ
        {
            studentID = 0;
            className = "不明";
        }
        //コンストラクタ（引数あり
        public Student(int sID, string cName,
            string n, int a, string j)  //HUmanクラスのコンストラクタ
            : base(n, a, j)
        {
            studentID = sID;
            className = cName;
        }
        /// <summary>
        /// 表示用メソッド
        /// </summary>
        public void DispInfo2()
        {
            Debug.Log($"学籍番号:{studentID}");
            Debug.Log($"クラス名:{className}");
        }
    }
    /// <summary>
    /// 基底クラス(親クラス)
    /// </summary>
    class Master
    {
        public int a, b, c;
        public void Test()
        {
            Debug.Log("テスト");
        }
    }
    /// <summary>
    /// 派生クラス(子クラス)
    /// </summary>
    class Child : Master 
    {
        public int d, e, f;
    }
    void Start()
    {
        //Humanクラスのインスタンスを作成
        Human tanaka = new Human("田中太郎", 18, "男");
        //Humanクラスのメソッド呼び出し
        tanaka.DispInfo();

        //Studentクラスのインスタンスの作成
        Student nakayama = new Student(100, "ゲーム総合学科", "中山", 18, "男");
        //Humanクラスの機能使える(継承してるので)
        //HumanクラスのDispInfo呼び出し
        nakayama.DispInfo();
        nakayama.DispInfo2();
    }


    void Update()
    {

    }
}
