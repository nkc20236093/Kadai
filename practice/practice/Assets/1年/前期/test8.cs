using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;   //UI�֘A���g�� 

public class Test8 : MonoBehaviour
{
    Text textComponent;  //�e�L�X�g�R���|�[�l���g
    void Start()
    {
        //�R���|�[�l���g���擾���āA�ϐ��ɓ����
        textComponent = GetComponent<Text>();
        //�N���X�̕ϐ��Ƀh�b�g���Z�q���g����
        //�N���X�̒��g�ɃA�N�Z�X�o����

        textComponent.text = "���d���[�v�̃e�X�g";
        //���s����ꍇ�A���s����(\n)������
        textComponent.text += "\n";
        //�����ǉ�(����)
        textComponent.text += "2�s�ڂɏ�������\n";

        //���d���[�v�ɂ���
        //���\�i�r���j�����


#if false       //1����9�܂Ń��[�v����for��(i)
        for (int i =1; i < 10; ++i)
        {
            //for���̒���for��
            //1����9�܂Ń��[�v����for��(j)
            for(int j = 1;j < 10; ++j)
            {
                int sum = i * j;
                //�����^�̕ϐ��𕶎��ɕϊ�
                //ToString�ŕ�����ɕϊ����A
                //3���ŕ\������悤��
                string str = sum.ToString("00");
                str += " ";
                //�e�L�X�g�ݒ�
                textComponent.text += str;


            }
            //���s
            textComponent.text += "\n";

        }
#endif

        //�O�p�`����肽��
        //1�s�ڂɕ�����1��
        //2�s�ڂɂ�����2��
        //3�s�ڂɕ�����3�ɂ�����
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < (i + 1); ++j)
            {
                textComponent.text += "��";
            }
            textComponent.text += "\n";
        }
    }


}