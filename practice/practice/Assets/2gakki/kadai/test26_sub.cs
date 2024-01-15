using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class test26_sub : MonoBehaviour
{
    // �ۑ�26�@�C���^�[�t�F�[�X�N���X

    // �`��֘A�̃C���^�[�t�F�[�X���쐬
    // �@Area�Ƃ����C���^�[�t�F�[�X�N���X���쐬
    // �ʐς����߂郁�\�b�hCalcArea()���`
    // �APrint�Ƃ����C���^�[�t�F�[�X�N���X���쐬
    // �`��̏���\�����郁�\�b�h��PrintInfo()���`
    public interface Area
    {
        public void CalcArea();
    }
    public interface Print
    {
        public void PrintInfo();
    }
    // �~�N���X�iCircle�N���X�j���쐬
    // Area��Print�̃C���^�[�t�F�[�X���p��
    // �����o�ϐ��Ɏ����^�̔��a������
    // �����o�ϐ��Ɏ����^�̖ʐς�����
    // CalcArea���\�b�h�ł͖ʐς̌v�Z������
    // PrintInfo���\�b�h�ł͔��a�A�ʐς̕\��������
    public class Circle : Area, Print
    {
        float radius = 5;
        float area;
        public void CalcArea()
        {
            area = Mathf.Pow(radius, 2) * Mathf.PI;
        }
        public void PrintInfo()
        {
            Debug.Log($"���a�F{radius}");
            Debug.Log($"�ʐρF{area}");
        }
    }
    // ��`�N���X�iRectAngle�N���X�j���쐬
    // Area��Print�̃C���^�[�t�F�[�X���p��
    // �����o�ϐ��Ɏ����^�̕��A����������
    // �����o�ϐ��Ɏ����^�̖ʐς�����
    // CalcArea���\�b�h�ł͖ʐς̌v�Z������
    // PrintInfo���\�b�h�ł͔��a�A���A�����A�ʐς̕\��������
    public class RectAngle : Area, Print
    {
        float w = 5;
        float h = 10;
        float area;
        public void CalcArea()
        {
            area = w * h;
        }
        public void PrintInfo()
        {
            Debug.Log($"���F{w}");
            Debug.Log($"����{h}");
            Debug.Log($"�ʐ�{area}");
        }
    }
    // test26_sub��Start���\�b�h���ŁA
    // Circle�N���X�ARectAngle�N���X�̎��̂��쐬
    // CalcArea���\�b�h�APrintInfo���\�b�h���Ăяo��

    // Start is called before the first frame update
    void Start()
    {
        Circle c = new Circle();
        c.CalcArea();
        c.PrintInfo();
        RectAngle r = new RectAngle();
        r.CalcArea();
        r.PrintInfo();
    }
}
