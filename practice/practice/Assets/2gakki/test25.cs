using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class test25 : MonoBehaviour
{
    /// <summary>
    /// 動物クラス
    /// abstractを付ける地抽象クラスとなる
    /// 抽象クラスは継承される前提のクラスで
    /// 実体を作ることができない
    /// </summary>
    abstract class Animal
    {
        //メンバ変数
        public string name; //名前
        // メンバメソッド
        // 仮想メソッド化
        // 仮想メソッドは継承された先で上書きされること前提のメソッド
        public virtual void Voice()
        {
            Debug.Log("鳴き声");
        }
        public virtual void Move()
        {
            Debug.Log("行動");
        }
    }
    class Cat: Animal 
    {
        public override void Voice()
        {
            Debug.Log("鳴き声：にゃー");
        }
        public override void Move()
        {
            Debug.Log("動作：丸くなる");
        }
    }
    /// <summary>
    /// 犬クラス(Animalを継承したクラス)
    /// </summary>
    class Dog : Animal
    {
        public override void Voice()
        {
            Debug.Log("鳴き声：ワンワン");
        }
        public override void Move()
        {
            Debug.Log("動作：駆けまわる");
        }
    }

    // Start is called before the first frame update
    void Start()
    {
        Cat cat1 = new Cat();
        cat1.name = "猫";
        Debug.Log($"名前：{cat1.name}");
        cat1.Voice();
        cat1.Move();

        Dog dog1 = new Dog();
        dog1.name = "犬";
        Debug.Log($"名前；{dog1.name}");
        dog1.Voice();
        dog1.Move();
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
