using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class test22 : MonoBehaviour
{
    //クラスの定義
    class Test1
    {
        //メンバ変数(アクセス指定子がない場合はprivate)
        int x;
        //コンストラクタ
        public Test1(int value) { x = value; }
        //アクセサ
        public int GetX() { return x; }             //ゲッタ
        public void SetX(int value) { x = value; }  //セッタ
    }

    //
    class Test2
    {
        private int x;
        //引数なしコンストラクタ
        public Test2() { x = -1; }
        //引数ありコンストラクタ
        public Test2(int value) { x = value; }

        //プロパティ
        public int X
        {
            get { return x; }
            set { x = value; }
        }
    }

    void Start()
    {
        //クラスの実体の作成(コンストラクタの呼び出し)
        Test1 t1 = new Test1(100);
        Debug.Log("x=" + t1.GetX());
        t1.SetX(200);
        Debug.Log("x=" + t1.GetX());

        //Test2クラスの実体の作成
        Test2 t2a = new Test2();      //引数なし
        Test2 t2b = new Test2(100);   //引数あり
        //プロパティを用いて表示
        //メソッドと違って()を付ける必要がない
        Debug.Log("t2a.x =" + t2a.X);
        Debug.Log("t2b.x =" + t2b.X);
        //プロパティのset
        //演算子を使って値を代入できる
        t2a.X = 0;
        t2a.X += 100;
        t2b.X -= 200;
        Debug.Log("t2a.x =" + t2a.X);
        Debug.Log("t2b.x =" + t2b.X);
    }

}
