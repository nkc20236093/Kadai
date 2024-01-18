using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using static test25_ex;

public class test25_ex : MonoBehaviour
{
    //    �E�l�ԃN���X�̎����i���N���X�j
    //������^�̖��O�p�̃v���p�e�B������
    //���z���\�b�h��Talk���������A���O��Debug.log�ŕ\��
    public class Human
    {
        public string name;
        public string ID;
        public virtual void Talk()
        {
            Debug.Log($"{name}�ł�");
        }
    }

    //�E�w���N���X�̎����i�l�ԃN���X���p�������h���N���X�j
    //������^�̃N���X���p�̃v���p�e�B������
    //Talk���\�b�h���I�[�o�[���C�h���ADebug.log�ŃN���X���A���O��\��
    public class Student : Human
    {
        public override void Talk()
        {
            Debug.Log($"{ID}��{name}�ł�");
        }
    }
    //�E�搶�N���X�̎����i�l�ԃN���X���p�������h���N���X�j
    //������^�̉Ȗږ��p�̃v���p�e�B������
    //Talk���\�b�h���I�[�o�[���C�h���ADebug.log�ŉȖږ��A���O��\��
    public class Teacher : Human
    {
        public override void Talk()
        {
            Debug.Log($"{ID}��{name}�ł�");
        }
    }

    //Start���\�b�h���ŁA�l�ԃN���X�A�w���N���X�A�搶�N���X�̎��̂��쐬�B

    //�l�ԃN���X�̔z��A�܂��̓��X�g���쐬���A���ꂼ��̎��̂�z�񂩃��X�g�ɒǉ��B
    //���̔z��܂��̓��X�g���g���āAfor���Ȃǂł܂Ƃ߂�Talk���\�b�h���Ăяo���A
    //�R��Talk���\�b�h���Ăяo����Ă��邱�Ƃ��m�F����B
    Human[] humans = new Human[3];
    //���s��)
    //�l�ԃN���X�̃��\�b�h�F�c���ł�
    //�w���N���X�̃��\�b�h�FGT1A�̍����ł�
    //�搶�N���X�̃��\�b�h�F�v���O���~���O���K�S���̒��R�ł��B
    // Start is called before the first frame update
    void Start()
    {
        Human human = new Human();
        human.name = "��";
        Student student = new Student();
        student.ID = "GT1A";student.name = "��";
        Teacher teacher = new Teacher();
        teacher.ID = "�v���O���~���O���K�S��";teacher.name = "���R";
        humans[0] = human;
        humans[1] = student;
        humans[2] = teacher;
        for (int i = 0; i < humans.Length; i++)
        {
            humans[i].Talk();
        }
    }
}
