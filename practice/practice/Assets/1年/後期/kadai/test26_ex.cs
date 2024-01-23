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
        public string attribute();
    }
    public interface Attack
    {
        public int attack();
    }
    public interface Defense
    {
        public string defense();
    }
    public interface Weakness
    {
        public string weakness();
    }

    public interface Name
    {
        public string name();
    }

    public class Player : Attribute, Attack, Defense,Name,Weakness
    {
        string Weak;
        string names;
        int attacks;
        string attribute_attack;
        string attribute_defense;
        public Player(string n, int a, string att_a, string att_d, string weak)
        {
            names = n;
            attacks = a;
            attribute_attack = att_a;
            attribute_defense = att_d;
            Weak = weak;
        }
        public string name()
        {
            return names;
        }
        public string attribute()
        {
            return attribute_attack;
        }
        public int attack()
        {
            return attacks;
        }
        public string defense()
        {
            return attribute_defense;
        }
        public string weakness()
        {
            return Weak;
        }
        /// <summary>
        /// Player被弾
        /// </summary>
        /// <param name="name">攻撃してくる相手の名前</param>
        /// <param name="partner_attribute_a">攻撃してくる相手の攻撃属性</param>
        /// <param name="partner_attribute__d">攻撃してくる相手の防御属性</param>
        /// <param name="a">攻撃してくる相手の攻撃力
        public void Damage(string name, string partner_attribute_a, string partner_attribute__d, int a)
        {
            // 表示例
            // PLの攻撃：炎、威力10
            // 敵の属性：草
            // 効果抜群!! 20ダメージ
            Debug.Log($"{name} VS {names}");
            Debug.Log($"{name}の攻撃属性:{partner_attribute_a}、威力{a}");
            Debug.Log($"{names}の防御属性:{attribute_defense}");
            if (partner_attribute_a == attribute_attack)
            {
                Debug.Log($"効果抜群!!{a * 2}ダメージ");
            }
            else if (partner_attribute_a == Weak)
            {
                Debug.Log($"あまり効果はないようだ…{a * 0.5f}ダメージ");
            }
            else if (partner_attribute_a == attribute_defense)
            {
                Debug.Log($"{a}ダメージ");
            }
        }
    }
    public class Enemy : Attribute, Attack, Defense
    {
        string Weak;
        string names;
        int attacks;
        string attribute_attack;
        string attribute_defense;
        public Enemy(string n, int a, string att_a, string att_d, string weak)
        {
            names = n;
            attacks = a;
            attribute_attack = att_a;
            attribute_defense = att_d;
            Weak = weak;
        }
        public string name()
        {
            return names;
        }
        public string attribute()
        {
            return attribute_attack;
        }
        public int attack()
        {
            return attacks;
        }
        public string defense()
        {
            return attribute_defense;
        }
        public string weakness()
        {
            return Weak;
        }
        /// <summary>
        /// Player被弾
        /// </summary>
        /// <param name="name">攻撃してくる相手の名前</param>
        /// <param name="partner_attribute_a">攻撃してくる相手の攻撃属性</param>
        /// <param name="partner_attribute__d">攻撃してくる相手の防御属性</param>
        /// <param name="a">攻撃してくる相手の攻撃力
        public void Damage(string name, string partner_attribute_a, string partner_attribute__d, int a)
        {
            // 表示例
            // PLの攻撃：炎、威力10
            // 敵の属性：草
            // 効果抜群!! 20ダメージ
            Debug.Log($"{name} VS {names}");
            Debug.Log($"{name}の攻撃属性:{partner_attribute_a}、威力{a}");
            Debug.Log($"{names}の防御属性:{attribute_defense}");
            if (partner_attribute_a == attribute_attack)
            {
                Debug.Log($"効果抜群!!{a * 2}ダメージ");
            }
            else if (partner_attribute_a == Weak)
            {
                Debug.Log($"あまり効果はないようだ…{a * 0.5f}ダメージ");
            }
            else if (partner_attribute_a == attribute_defense)
            {
                Debug.Log($"{a}ダメージ");
            }
        }
    }
    public class Boss : Attribute, Attack, Defense
    {
        string Weak;
        string names;
        int attacks;
        string attribute_attack;
        string attribute_defense;
        public Boss(string n, int a, string att_a, string att_d, string weak)
        {
            names = n;
            attacks = a;
            attribute_attack = att_a;
            attribute_defense = att_d;
            Weak = weak;
        }
        public string name()
        {
            return names;
        }
        public string attribute()
        {
            return attribute_attack;
        }
        public int attack()
        {
            return attacks;
        }
        public string defense()
        {
            return attribute_defense;
        }
        public string weakness()
        {
            return Weak;
        }
        /// <summary>
        /// Player被弾
        /// </summary>
        /// <param name="name">攻撃してくる相手の名前</param>
        /// <param name="partner_attribute_a">攻撃してくる相手の攻撃属性</param>
        /// <param name="partner_attribute__d">攻撃してくる相手の防御属性</param>
        /// <param name="a">攻撃してくる相手の攻撃力
        public void Damage(string name, string partner_attribute_a, string partner_attribute__d, int a)
        {
            // 表示例
            // PLの攻撃：炎、威力10
            // 敵の属性：草
            // 効果抜群!! 20ダメージ
            Debug.Log($"{name} VS {names}");
            Debug.Log($"{name}の攻撃属性:{partner_attribute_a}、威力{a}");
            Debug.Log($"{names}の防御属性:{attribute_defense}");
            if (partner_attribute_a == attribute_attack)
            {
                Debug.Log($"効果抜群!!{a * 2}ダメージ");
            }
            else if (partner_attribute_a == Weak)
            {
                Debug.Log($"あまり効果はないようだ…{a * 0.5f}ダメージ");
            }
            else if (partner_attribute_a == attribute_defense)
            {
                Debug.Log($"{a}ダメージ");
            }
        }
    }
    void Start()
    {
        // プレイヤー、敵、ボスの攻撃力、属性を自由に設定
        //
        // プレイヤーVS敵
        // プレイヤーVSボス
        // 敵VSボス
        // それぞれの攻撃、防御でのダメージ計算を行い表示する
        //
        // 条件
        // 抽象クラスまたはインターフェースクラスを用いて実装
        // Start is called before the first frame update

        Player player = new Player("Player", 50, "水", "火","草");
        Boss boss = new Boss("Boss", 100, "水", "火", "草");
        Enemy enemy = new Enemy("Enemy", 10, "火", "草", "水");
        // Player VS Enemy
        player.Damage(enemy.name(), enemy.attribute(), enemy.defense(), enemy.attack());
        // Boss VS Player
        boss.Damage(player.name(), player.attribute(), player.defense(), player.attack());
        // Enemy VS Boss
        enemy.Damage(boss.name(), boss.attribute(), boss.defense(), boss.attack());
    }
}
