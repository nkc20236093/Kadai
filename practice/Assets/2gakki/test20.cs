using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class test20 : MonoBehaviour
{
    //定数（変更できない）
    //定数だと分かるように名前を変更すると良い
    const int MaxHP = 10;

    //変数（変更できる）
    int nowHP = 0;

    //列挙型
    //enum + 型名{列挙子};
    enum Season
    {
        Spring = 100, //0
        Summer,     //↑+1
        Autumn,     //↑+1     
        Winter,     //↑+1
    };

    Season s = Season.Winter;

    //武器の列挙型
    enum Weapon
    {
        Sword, Lance, Axe, Hammer, Gun, Bow,
    };
    //列挙型に対応した配列
    string[] nameTable = {    //名前
    "剣","槍","斧","ハンマー","銃","弓"
    };                        //攻撃力
    int[] attackPowerTable =
    {
        10,6,20,15,500,2,
    };
    Weapon w = Weapon.Gun;



    void Start()
    {
        //maxHP = 20;
        nowHP = MaxHP;
        //列挙子の表示
        Debug.Log(s);
        //列挙子の数値の確認(intにキャスト)
        Debug.Log((int)s);

        Debug.Log("選んだ武器");
        int wNo = (int)w;      //数値に変換
        Debug.Log("武器名" + nameTable[wNo]);
        Debug.Log("攻撃力" + attackPowerTable[wNo]);
    }

    void Update()
    {

    }
}
