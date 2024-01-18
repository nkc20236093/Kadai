using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class test25 : MonoBehaviour
{
    /// <summary>
    /// �����N���X
    /// abstract��t����n���ۃN���X�ƂȂ�
    /// ���ۃN���X�͌p�������O��̃N���X��
    /// ���̂���邱�Ƃ��ł��Ȃ�
    /// </summary>
    abstract class Animal
    {
        //�����o�ϐ�
        public string name; //���O
        // �����o���\�b�h
        // ���z���\�b�h��
        // ���z���\�b�h�͌p�����ꂽ��ŏ㏑������邱�ƑO��̃��\�b�h
        public virtual void Voice()
        {
            Debug.Log("����");
        }
        public virtual void Move()
        {
            Debug.Log("�s��");
        }
    }
    class Cat: Animal 
    {
        public override void Voice()
        {
            Debug.Log("�����F�ɂ�[");
        }
        public override void Move()
        {
            Debug.Log("����F�ۂ��Ȃ�");
        }
    }
    /// <summary>
    /// ���N���X(Animal���p�������N���X)
    /// </summary>
    class Dog : Animal
    {
        public override void Voice()
        {
            Debug.Log("�����F��������");
        }
        public override void Move()
        {
            Debug.Log("����F�삯�܂��");
        }
    }

    // Start is called before the first frame update
    void Start()
    {
        Cat cat1 = new Cat();
        cat1.name = "�L";
        Debug.Log($"���O�F{cat1.name}");
        cat1.Voice();
        cat1.Move();

        Dog dog1 = new Dog();
        dog1.name = "��";
        Debug.Log($"���O�G{dog1.name}");
        dog1.Voice();
        dog1.Move();
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
