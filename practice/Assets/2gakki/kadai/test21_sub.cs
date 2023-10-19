using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class test21_sub : MonoBehaviour
{
    // 課題21 クラス
    // 21-1
    // 斧クラス（Axeクラス）を作成
    // メンバ変数(アクセス指定子はprivate)に
    // 文字列型のname,整数型のatkPow,vitalを持つ
    // コンストラクタを作成し、
    // name, atkPow, vitalに値を入れられるようにする。
    // メンバ関数Printを作成し、
    // メンバ変数を全て表示する。
    // 例）
    // 名前：〇〇アックス（〇〇は好きな名前を入れる）
    // 攻撃力：〇〇（〇〇は設定した値）
    // 耐久値：〇〇（〇〇は設定した値）
    //
    // 21-2
    // 盾クラス（Shieldクラス）を作成
    // メンバ変数(private）に
    // 名前、防御力、耐久値を持つ。(変数名は自由）
    // コンストラクタでメンバ変数を初期化
    // Print関数でメンバ変数を全て表示する。
    // ※21-1と同じような様式で表示
    //
    // 21-3
    // 斧クラスの攻撃力と、盾クラスの防御力で、
    // お互いの値を比べ、小さい方の耐久を
    // 攻撃力ー防御力の差分で削る処理を作る
    //
    // 実行例）
    // 〇〇斧の攻撃:10 VS 〇〇盾の防御:8
    // 〇〇盾の勝利
    // 〇〇盾の耐久が〇〇になりました
    //
    // ■作成のヒント
    // クラスのメンバ変数がprivateなので、面倒です。
    // 関数を使って値を参照したり、
    // 設定できるよう挑戦してください
    class Axe
    {
        private string name;
        private int atkPow;
        private int vital;

        public Axe(string n, int p, int v)
        {
            name = n;
            atkPow = p;
            vital = v;
        }
        public void Print()
        {
            Debug.Log($"アックス");
            //Debug.Log();
            //Debug.Log();
        }
        public void SetName(string n)
        {
            name = n;
        }
        public void SetaktPow(int p)
        {
            atkPow = p;
        }
        public void SetVital(int v)
        {
            vital = v;
        }
        public string GetName()
        {
            return name;
        }
        public int GetatkPow()
        {
            return atkPow;
        }
        public int GetVital()
        {
            return vital;
        }
    }

    // Start is called before the first frame update
    void Start()
    {
        Axe axe = new Axe("斧", 500, 500);
        axe.Print();
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
