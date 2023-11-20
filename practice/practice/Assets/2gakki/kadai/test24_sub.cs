using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class test24_sub : MonoBehaviour
{
    // 課題24
    // 基底クラスのWeaponクラスを作成
    // メンバ変数
    // 名前（文字列型）
    // 攻撃力（整数型）
    // 値段（整数型）
    // ※変数のアクセス指定子は自由
    // ※コンストラクタの実装も自由
    class Weapon
    {
        private string name;
        private int attack;
        private int price;
        public Weapon()
        {
            name = "名無し";
            attack = 0;
            price = 0;
        }
        public Weapon(string a, int b, int c)
        {
            name = a;
            attack = b;
            price = c;
        }
        public void DispInfo1()
        {
            Debug.Log($"武器名:{name}");
            Debug.Log($"攻撃力:{attack}");
            Debug.Log($"値段:{price}円");
        }
    }

    // 派生クラスのSwordクラスを作成
    // メンバ変数
    // 武器の種類（文字列型）
    // 武器技名（文字列型）
    // ※変数のアクセス指定子は自由
    // コンストラクタでは、引数を５つ
    // 名前、攻撃力、値段、武器種類、技名を設定
    // DispInfoメソッドで、
    // 全ての情報を表示させる
    // 表示例）
    // 武器名：ロングソード
    // 攻撃力：５
    // 値段：１００円
    // 武器種類：剣
    // 技名：２段斬り

    // test24_subのStartメソッドで、
    // Swordクラスのインスタンスを二つ作成。
    // 二つの剣の情報を表示させる。

    class Sword : Weapon 
    {
        private string Sword_name;
        private string Sword_attack_name;
        public Sword()
        {
            Sword_name = "None";
            Sword_attack_name = "名無し";
        }
        public Sword(string d, string e, string a, int b, int c) : base(a, b, c)
        {
            Sword_name = d;
            Sword_attack_name = e;
        }
        public void DispInfo2()
        {
            Debug.Log($"武器種類:{Sword_name}");
            Debug.Log($"技名:{Sword_attack_name}");
        }
    }

    // 派生クラスのLanceクラスを作成
    // メンバ変数
    // 武器の種類（文字列型）
    // 武器技名（文字列型）
    // 防御力（整数型）
    // ※変数のアクセス指定子は自由
    // コンストラクタでは、引数は６つ
    // 武器名、攻撃力、値段、武器種類、技名、防御力
    // DispInfoメソッドで、
    // 全ての情報を表示させる
    //
    // ランスクラスのインスタンスも二つ作成。
    // 二つの槍の情報も表示する。

    class Lance : Weapon 
    {
        private string Lance_name;
        private string Lance_attack_name;
        private int Defense;
        public Lance()
        {
            Lance_name = "名無し";
            Lance_attack_name = "名無し";
            Defense = 0;
        }
        public Lance(string f, string g, int h, string a, int b, int c) : base(a, b, c)
        {
            Lance_name = f;
            Lance_attack_name = g;
            Defense = h;
        }
        public void DispInfo3()
        {
            Debug.Log($"武器種類{Lance_name}");
            Debug.Log($"技名{Lance_attack_name}");
            Debug.Log($"防御力{Defense}");
        }
    }
    // Start is called before the first frame update
    void Start()
    {
        Sword sword1 = new Sword("剣", "2段切り", "ロングソード", 10, 100);
        sword1.DispInfo1();
        sword1.DispInfo2();

        Sword sword2 = new Sword("剣", "回転切り", "アイアンソード", 50, 150);
        sword2.DispInfo1();
        sword2.DispInfo2();

        Lance lance1 = new Lance("ランス", "シールドダッシュ", 50, "ショートランス", 15, 100);
        lance1.DispInfo1();
        lance1.DispInfo3();

        Lance lance2 = new Lance("ランス", "昇天突き", 50, "アイアンランス", 50, 150);
        lance2.DispInfo1();
        lance2.DispInfo3();
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
