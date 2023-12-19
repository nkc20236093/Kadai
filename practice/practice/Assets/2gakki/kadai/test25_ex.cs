using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using static test25_ex;

public class test25_ex : MonoBehaviour
{
    //    ・人間クラスの実装（基底クラス）
    //文字列型の名前用のプロパティを持つ
    //仮想メソッドのTalkを実装し、名前をDebug.logで表示
    public class Human
    {
        public string name;
        public string ID;
        public virtual void Talk()
        {
            Debug.Log($"{name}です");
        }
    }

    //・学生クラスの実装（人間クラスを継承した派生クラス）
    //文字列型のクラス名用のプロパティを持つ
    //Talkメソッドをオーバーライドし、Debug.logでクラス名、名前を表示
    public class Student : Human
    {
        public override void Talk()
        {
            Debug.Log($"{ID}の{name}です");
        }
    }
    //・先生クラスの実装（人間クラスを継承した派生クラス）
    //文字列型の科目名用のプロパティを持つ
    //Talkメソッドをオーバーライドし、Debug.logで科目名、名前を表示
    public class Teacher : Human
    {
        public override void Talk()
        {
            Debug.Log($"{ID}の{name}です");
        }
    }

    //Startメソッド内で、人間クラス、学生クラス、先生クラスの実体を作成。

    //人間クラスの配列、またはリストを作成し、それぞれの実体を配列かリストに追加。
    //その配列またはリストを使って、for分などでまとめてTalkメソッドを呼び出し、
    //３つのTalkメソッドが呼び出されていることを確認する。
    Human[] humans = new Human[3];
    //実行例)
    //人間クラスのメソッド：田中です
    //学生クラスのメソッド：GT1Aの佐藤です
    //先生クラスのメソッド：プログラミング実習担当の中山です。
    // Start is called before the first frame update
    void Start()
    {
        Human human = new Human();
        human.name = "滝";
        Student student = new Student();
        student.ID = "GT1A";student.name = "滝";
        Teacher teacher = new Teacher();
        teacher.ID = "プログラミング実習担当";teacher.name = "中山";
        humans[0] = human;
        humans[1] = student;
        humans[2] = teacher;
        for (int i = 0; i < humans.Length; i++)
        {
            humans[i].Talk();
        }
    }
}
