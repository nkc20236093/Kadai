using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;

public class test24 : MonoBehaviour
{
    //�p��
    class Human  //�l�ԃN���X
    {
        private string name;   //���O
        private int age;       //�N��
        private string gender; //����
        //���\�b�h
        public Human()  //�����Ȃ��R���X�g���N�^
        {
            name = "������";
            age = 0;
            gender = "�s��";
        }
        public Human(string n, int a, string g)  //��������R���X�g���N�^
        {
            name = n;
            age = a;
            gender = g;
        }

        public void DispInfo()  //����\�����郁�\�b�h
        {
            Debug.Log("���O" + name);
            Debug.Log("�N��" + age);
            Debug.Log("����" + gender);
        }
    }

    //�w���N���X(Human���p�������N���X�A�h���N���X�ƌĂ�)
    //�N���X��`:�p���������N���X��
    class Student : Human
    {
        private int studentID;    //�w�Дԍ�
        private string className; //�N���X��
        //���\�b�h
        public Student()  //�����Ȃ��R���X�g���N�^
        {
            studentID = 0;
            className = "�s��";
        }
        //�R���X�g���N�^�i��������
        public Student(int sID, string cName,
            string n, int a, string j)  //HUman�N���X�̃R���X�g���N�^
            : base(n, a, j)
        {
            studentID = sID;
            className = cName;
        }
        /// <summary>
        /// �\���p���\�b�h
        /// </summary>
        public void DispInfo2()
        {
            Debug.Log($"�w�Дԍ�:{studentID}");
            Debug.Log($"�N���X��:{className}");
        }
    }
    /// <summary>
    /// ���N���X(�e�N���X)
    /// </summary>
    class Master
    {
        public int a, b, c;
        public void Test()
        {
            Debug.Log("�e�X�g");
        }
    }
    /// <summary>
    /// �h���N���X(�q�N���X)
    /// </summary>
    class Child : Master 
    {
        public int d, e, f;
    }
    void Start()
    {
        //Human�N���X�̃C���X�^���X���쐬
        Human tanaka = new Human("�c�����Y", 18, "�j");
        //Human�N���X�̃��\�b�h�Ăяo��
        tanaka.DispInfo();

        //Student�N���X�̃C���X�^���X�̍쐬
        Student nakayama = new Student(100, "�Q�[�������w��", "���R", 18, "�j");
        //Human�N���X�̋@�\�g����(�p�����Ă�̂�)
        //Human�N���X��DispInfo�Ăяo��
        nakayama.DispInfo();
        nakayama.DispInfo2();
    }


    void Update()
    {

    }
}
