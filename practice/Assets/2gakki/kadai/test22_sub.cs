using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class test22_sub : MonoBehaviour
{
    // �ۑ�Q�Q
    // Human�N���X�̍쐬
    // ������ϐ�name,�����^�ϐ�age������
    // (�ϐ��̃A�N�Z�X�w��q��private�j
    // �����Ȃ��R���X�g���N�^������
    // name��"����"�Aage��-1������
    // ��������R���X�g���N�^������
    // name,age�ɒl��ݒ�ł���悤�ɂ���
    class Human
    {
        private string name;
        private int age;
        public Human() { name = "����"; age = -1; }
        public Human(string a, int b) { name = a; age = b; }
        public string Y
        {
            get { return name; }
            set { name = value; }
        }
        public int X
        {
            get { return age; }
            set { age = value; }
        }
    }

    // Start���\�b�h���ŁA
    // Human�N���X�̃C���X�^���X���쐬
    // �Е��͈����Ȃ�
    // �����Е��͈�������R���X�g���N�^���Ăяo���A
    // �����̖��O�A�N�������

    // Human�N���X�Ƀv���p�e�B������
    // ���O�A�N���ݒ�A�擾�ł���悤�ɂ���
    // Start���\�b�h���ŁADebug.log��p����
    // ��̃C���X�^���X�̖��O�A�N���\������
    // �\����j
    // ��l�ڂ̖��O�F�����A�N��F-1��
    // ��l�ڂ̖��O�F���R�����i�����̖��O�j�A�N��F17��
    // Start is called before the first frame update
    void Start()
    {
        Human human1 = new Human();
        Debug.Log("���O:" + human1.Y + ":�N��" + human1.X);
        Human human2 = new Human("��l��", 17);
        Debug.Log("���O:" + human2.Y + ":�N��" + human2.X);
    }
}
