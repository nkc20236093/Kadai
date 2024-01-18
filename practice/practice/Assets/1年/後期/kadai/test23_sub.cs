using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class test23_sub : MonoBehaviour
{
    //課題２３

    class Student
    {
        private string name;
        private int age;
        private string gender;
        private int Class_Number;
        private string Class_name;
        private int Grades;
        public Student(string a, int b, string c, int d, string e, int f)
        {
            name = a;
            age = b;
            gender = c;
            Class_Number = d;
            Class_name = e;
            Grades = f;
        }
        public void DispInfo()
        {
            Debug.Log($"名前：{name}");
            Debug.Log($"年齢：{age}");
            Debug.Log($"性別：{gender}");
            Debug.Log($"学籍番号：{Class_Number}");
            Debug.Log($"クラス名：{Class_name}");
            Debug.Log($"成績：{Grades}");
        }
        public int GetGrades()
        {
            return Grades;
        }
        public string GetName()
        {
            return name;
        }
    }

    //■学生クラス(Student)作成
    //以下のprivate変数を用意（変数名は各自で指定）
    //・名前（文字列型）
    //・年齢（整数型）
    //・性別（文字列型）
    //・学籍番号（整数型）
    //・クラス名（文字列型）
    //・成績（整数型）
    //それぞれのプロパティを実装
    //コンストラクタの実装、引数に名前、年齢、性別、学籍番号を入れる
    //学生情報を全て表示するメソッド(DispInfo)を作成
    //Debug.logを用いて全ての情報を表示する。

    //■Startメソッド内で学生クラスのインスタンスを二つ作成
    //作成した二つのインスタンスに、クラス名、成績を設定
    //(インスタンスには自分の情報を設定、もう片方は自由に設定)

    //■インスタンスのDispInfoメソッドを用いて、
    //二つのインスタンスの情報を全て表示する。
    //表示例）
    //一人目
    //名前：中山亮太
    //年齢：１８
    //生別：男
    //学籍番号：２０２３００００
    //クラス名：ゲーム総合学科1年C組
    //成績：１００

    //二人目：
    //名前：田中太郎
    //年齢：５０
    //生別：男
    //学籍番号：１２３４５６７８
    //クラス名：ゲームサイエンス学科1年
    //成績：２０

    //■二つのインスタンスの成績の平均点を計算して表示
    //表示例）
    //二人の成績の平均点は〇〇です。

    //■二つのインスタンスの成績を比較して、大きい方のインスタンスの名前を表示
    //表示例）
    //成績が良い学生は〇〇です。
    // Start is called before the first frame update
    void Start()
    {
        Student student = new Student("滝瑛太", 19, "男", 20236093, "ゲーム総合学科1年A組", 100);
        student.DispInfo();
        Student second_student = new Student("田中太郎", 18, "男", 20239999, "ゲームサイエンス学科1年", 50);
        second_student.DispInfo();
        int first_Grades = student.GetGrades();
        int second_Grades=second_student.GetGrades();
        int average = (first_Grades + second_Grades) / 2;
        Debug.Log(average);
        string winner;
        if (first_Grades > second_Grades)
        {
            winner=student.GetName();
        }
        else
        {
            winner =second_student.GetName();
        }
        Debug.Log($"成績が良い学生は{winner}です。");
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
