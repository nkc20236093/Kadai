using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class test23_sub : MonoBehaviour
{
    //�ۑ�Q�R

    class Student
    {
        private string name;
        private int age;
        private string gender;
        private int Class_Number;
        private string Class_name;
        private int Grades;
        public Student(string a, int b, string c, int d, string e, int f)
        {
            name = a;
            age = b;
            gender = c;
            Class_Number = d;
            Class_name = e;
            Grades = f;
        }
        public void DispInfo()
        {
            Debug.Log($"���O�F{name}");
            Debug.Log($"�N��F{age}");
            Debug.Log($"���ʁF{gender}");
            Debug.Log($"�w�Дԍ��F{Class_Number}");
            Debug.Log($"�N���X���F{Class_name}");
            Debug.Log($"���сF{Grades}");
        }
        public int GetGrades()
        {
            return Grades;
        }
        public string GetName()
        {
            return name;
        }
    }

    //���w���N���X(Student)�쐬
    //�ȉ���private�ϐ���p�Ӂi�ϐ����͊e���Ŏw��j
    //�E���O�i������^�j
    //�E�N��i�����^�j
    //�E���ʁi������^�j
    //�E�w�Дԍ��i�����^�j
    //�E�N���X���i������^�j
    //�E���сi�����^�j
    //���ꂼ��̃v���p�e�B������
    //�R���X�g���N�^�̎����A�����ɖ��O�A�N��A���ʁA�w�Дԍ�������
    //�w������S�ĕ\�����郁�\�b�h(DispInfo)���쐬
    //Debug.log��p���đS�Ă̏���\������B

    //��Start���\�b�h���Ŋw���N���X�̃C���X�^���X���쐬
    //�쐬������̃C���X�^���X�ɁA�N���X���A���т�ݒ�
    //(�C���X�^���X�ɂ͎����̏���ݒ�A�����Е��͎��R�ɐݒ�)

    //���C���X�^���X��DispInfo���\�b�h��p���āA
    //��̃C���X�^���X�̏���S�ĕ\������B
    //�\����j
    //��l��
    //���O�F���R����
    //�N��F�P�W
    //���ʁF�j
    //�w�Дԍ��F�Q�O�Q�R�O�O�O�O
    //�N���X���F�Q�[�������w��1�NC�g
    //���сF�P�O�O

    //��l�ځF
    //���O�F�c�����Y
    //�N��F�T�O
    //���ʁF�j
    //�w�Дԍ��F�P�Q�R�S�T�U�V�W
    //�N���X���F�Q�[���T�C�G���X�w��1�N
    //���сF�Q�O

    //����̃C���X�^���X�̐��т̕��ϓ_���v�Z���ĕ\��
    //�\����j
    //��l�̐��т̕��ϓ_�́Z�Z�ł��B

    //����̃C���X�^���X�̐��т��r���āA�傫�����̃C���X�^���X�̖��O��\��
    //�\����j
    //���т��ǂ��w���́Z�Z�ł��B
    // Start is called before the first frame update
    void Start()
    {
        Student student = new Student("��l��", 19, "�j", 20236093, "�Q�[�������w��1�NA�g", 100);
        student.DispInfo();
        Student second_student = new Student("�c�����Y", 18, "�j", 20239999, "�Q�[���T�C�G���X�w��1�N", 50);
        second_student.DispInfo();
        int first_Grades = student.GetGrades();
        int second_Grades=second_student.GetGrades();
        int average = (first_Grades + second_Grades) / 2;
        Debug.Log(average);
        string winner;
        if (first_Grades > second_Grades)
        {
            winner=student.GetName();
        }
        else
        {
            winner =second_student.GetName();
        }
        Debug.Log($"���т��ǂ��w����{winner}�ł��B");
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
