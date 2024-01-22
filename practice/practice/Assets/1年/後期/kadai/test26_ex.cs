using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class test26_ex : MonoBehaviour
{
    // 課題26ex
    // プレイヤー、敵、ボス、クラスを作成
    // それぞれ攻撃力、攻撃属性、防御属性、を持ちます。
    // 属性は炎、水、草の属性で
    // 炎＞草、草＞水、水＞炎　というような相性があり、
    // 弱点をついた場合は攻撃力が2倍、
    // 耐性を持つ場合は攻撃力が0.5倍になります。
    // 例）炎が草に攻撃は2倍、草が炎に攻撃は0.5倍
    public interface Attribute
    {
        public void attribute();
    }
    public interface Attack
    {
        public void attack();
    }
    public interface Defense
    {
        public void defense();
    }
    public class Player : Attribute, Attack, Defense
    {
        int attacks;
        string attribute_attack;
        string attribute_defense;
        public void attribute()
        {
            attribute_attack = "水";
        }
        public void attack()
        {
            attacks = 50;
        }
        public void defense()
        {
            attribute_defense = "火";
        }
        public int Get_attacks()
        {
            return attacks;
        }
        public string Get_attribute_attack()
        {
            return attribute_attack;
        }
        public string Get_attribute_defense()
        {
            return attribute_defense;
        }
    }
    public class Enemy : Attribute, Attack, Defense
    {
        int attacks;
        string attribute_attack;
        string attribute_defense;
        public void attribute()
        {
            attribute_attack = "草";
        }
        public void attack()
        {
            attacks = 10;
        }
        public void defense()
        {
            attribute_defense = "草";
        }
        public int Get_attacks()
        {
            return attacks;
        }
        public string Get_attribute_attack()
        {
            return attribute_attack;
        }
        public string Get_attribute_defense()
        {
            return attribute_defense;
        }
    }
    public class Boss : Attribute, Attack, Defense
    {
        int attacks;
        string attribute_attack;
        string attribute_defense;
        public void attribute()
        {
            attribute_attack = "火";
        }
        public void attack()
        {
            attacks = 100;
        }
        public void defense()
        {
            attribute_defense = "草";
        }
        public int Get_attacks()
        {
            return attacks;
        }
        public string Get_attribute_attack()
        {
            return attribute_attack;
        }
        public string Get_attribute_defense()
        {
            return attribute_defense;
        }
    }

    // プレイヤー、敵、ボスの攻撃力、属性を自由に設定
    //
    // プレイヤーVS敵
    // プレイヤーVSボス
    // 敵VSボス
    // それぞれの攻撃、防御でのダメージ計算を行い表示する
    //
    // 表示例
    // PLの攻撃：炎、威力10
    // 敵の属性：草
    // 効果抜群!! 20ダメージ
    //
    // 条件
    // 抽象クラスまたはインターフェースクラスを用いて実装
    // Start is called before the first frame update
    void Start()
    {
        Player player = new Player();
        player.attack();
        player.attribute();
        player.defense();
        int pl_attack= player.Get_attacks();
        string pl_attri_attack = player.Get_attribute_attack();
        string pl_attri_defense = player.Get_attribute_defense();
        Enemy enemy = new Enemy();
        enemy.attack();
        enemy.defense();
        enemy.attribute();
        int ene_attack = enemy.Get_attacks();
        string ene_attri_attack = enemy.Get_attribute_attack();
        string ene_attri_defence = enemy.Get_attribute_defense();
        Boss boss = new Boss();
        boss.attribute();
        boss.attack();
        boss.defense();
        int boss_attack = boss.Get_attacks();
        string boss_attri_attack = boss.Get_attribute_attack();
        string boss_attri_defense = boss.Get_attribute_defense();
        //pl vs ene
        Debug.Log("Player VS Enemy");
        Debug.Log($"Playerの攻撃属性：{pl_attri_attack}、威力{pl_attack}");
        Debug.Log($"Enemyの防御属性：{ene_attri_defence}");
        if (ene_attri_defence == "草")
        {
            float Info = pl_attack * 0.5f;
            Debug.Log($"あまり効果はないようだ…{Info}ダメージ");
        }
        else if (ene_attri_defence == "火")
        {
            int Info = pl_attack * 2;
            Debug.Log($"効果抜群!!{Info}ダメージ");
        }
        else
        {
            Debug.Log($"{pl_attack}ダメージ");
        }
        // pl vs boss
        Debug.Log($"Player VS Boss");
        Debug.Log($"Playerの攻撃属性：{pl_attri_attack}、威力{pl_attack}");
        Debug.Log($"Bossの防御属性：{boss_attri_defense}");
        if (boss_attri_defense == "草")
        {
            float Info = pl_attack * 0.5f;
            Debug.Log($"あまり効果はないようだ…{Info}ダメージ");
        }
        else if(ene_attri_defence == "火")
        {
            int Info = pl_attack * 2;
            Debug.Log($"効果抜群!!{Info}ダメージ");
        }
        else
        {
            Debug.Log($"{pl_attack}");
        }
        // ene vs boss
        Debug.Log($"Enemy VS Boss");
        Debug.Log($"Enemyの攻撃属性：{ene_attri_attack}、威力{ene_attack}");
        Debug.Log($"Bossの防御属性：{boss_attri_defense}");
        if (boss_attri_defense == "水")
        {
            float Info = ene_attack * 0.5f;
            Debug.Log($"あまり効果はないようだ…{Info}ダメージ");
        }
        else if(ene_attri_defence == "火")
        {
            int Info = ene_attack * 2;
            Debug.Log($"効果抜群!!{Info}ダメージ");
        }
        else
        {
            Debug.Log($"{ene_attack}ダメージ");
        }
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
