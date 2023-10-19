using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class test21 : MonoBehaviour
{
    //内部クラス
    class Sword
    {
        //メンバ変数の宣言
        //アクセス指定子(指定がないとprivate)
        //private このクラス内だったらどのメソッドからも扱える
        //public  他クラスからも扱えて便利だがバグも増えやすい
        private string name;  //名前
        private int atkPow;   //攻撃力
        private int vital;    //耐久力
        public Sword(string n, int p, int v)
        {
            name = n;
            atkPow = p;
            vital = v;
        }

        public void Print()
        {
            Debug.Log("剣名:" + name);
            Debug.Log("攻撃力:" + atkPow);
            Debug.Log("耐久力:" + vital);
        }
        public void SetName(string n)
        {
            name = n;
        }
        public void SetPower(int p)
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
        public int GetPower()
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
        //Swordクラスのインスタンス生成(この時メモリに配置)
        Sword mSword = new Sword("この川…不快！", 1000, 100);
        mSword.Print();
        //mSword.SetName("この川…不快！");
        //mSword.SetPower(1000);
        //mSword.SetVital(100);
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
