using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class test26 : MonoBehaviour
{
    // インターフェースクラス
    // 継承を前提としたクラス
    // （継承したクラスは機能を実装しなければならない）
    // インターフェースは複数継承できる
    public interface IDamage
    {
        void DamegeReaction(); // ダメージリアクション
    }
    public interface IAttack
    {
        void AttackReaction(); // 攻撃
    }

    // IDamageを継承(DamageReactionを実装しなければならない)
    public class Player : IDamage, IAttack
    {
        public void DamegeReaction()
        {
            Debug.Log("Playerのダメージ");
        }
        public void AttackReaction()
        {
            Debug.Log("Playerの攻撃");
        }
    }
    public class Enemy : IDamage
    {
        public void DamegeReaction()
        {
            Debug.Log("Enemyのダメージ");
        }
    }
    public class Boss : IDamage
    {
        public void DamegeReaction()
        {
            Debug.Log("Bossのダメージ");
        }
    }

    Player pl = new Player();
    Enemy em = new Enemy();
    Boss bs = new Boss();

    void Update()
    {
        IDamage dmg = null;
        if (Input.GetKeyDown(KeyCode.Z))
        {
            // ZキーはEnemyを攻撃
            pl.AttackReaction();
            // ダメージリアクションを行うのは敵
            dmg = em;
        }
        if (Input.GetKeyDown(KeyCode.X))
        {
            // XキーはBossを攻撃
            pl.AttackReaction();
            // ダメージリアクション
            dmg = bs;
        }
        // ダメージ対象がnullじゃなければ
        if (dmg != null)
        {
            // それぞれのダメージリアクションを行う
            dmg.DamegeReaction();
        }
    }
}
