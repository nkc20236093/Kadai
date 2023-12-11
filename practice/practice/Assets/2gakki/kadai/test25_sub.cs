using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class test25_sub : MonoBehaviour
{
    // �ۑ�25
    //
    // Shape(�`��j�Ƃ������ۃN���X���쐬
    // Shape�͏㏑����O��Ƃ���Area���\�b�h������
    // Area���\�b�h�͕ԋp�l�������^�A�����͖���

    class Shape
    {
        public virtual int Area(float a ,float b)
        {
            return (int)a;
        }
    }

    // Circle�i�~�j�N���X���쐬�iShape���p���j
    // �����o�ϐ��Ɏ����^�̔��a������
    // �R���X�g���N�^�Ŕ��a��ݒ�
    // Area���\�b�h���I�[�o�[���C�h���āA�ʐς��v�Z
    class Circle : Shape
    {
        public int radius;
        public override int Area(float a , float b)
        {
            radius = (int)a;
            return (int)a;
        }
    }

    // Rectangle(��`�j�N���X���쐬(Shape���p���j
    // �����o�ϐ��Ɏ����^�̕��A����������
    // �R���X�g���N�^�ŕ��A������ݒ�
    // Area���\�b�h���I�[�o�[���C�h���āA�ʐς��v�Z
    class Rectangle : Shape
    {
        public int width;
        public int length;
        public override int Area(float a, float b)
        {
            width = (int)a;
            length = (int)b;
            float c = a * b;
            return (int)c;
        }
    }

    //
    // test25_sub��Start���\�b�h���ŁA
    // Circle��Rectangle�̃C���X�^���X�𐶐��A
    // �ʐς�\������
    // ��j�������܂ŗ�Ȃ�ŎQ�l���x��OK
    // double c = c1.Area();
    // Debug.log("�~�̖ʐς�" + c);
    // Start is called before the first frame update
    void Start()
    {
        Circle circle = new Circle();
        double c = circle.Area(5, 0);
        Debug.Log($"�~�̖ʐς�{c * Mathf.PI}");

        Rectangle rectangle = new Rectangle();
        double r = rectangle.Area(5, 10);
        Debug.Log($"�Z�`�̖ʐς�{r}");
    }
}
