using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;    //UI�g�p

public class test12 : MonoBehaviour
{
    public Text textCmp;  //�e�L�X�g�N���X�̃R���|�[�l���g

    //�ō����A�̃L�����z��
    string[] rareTable =
    {
        "�n�~���g��",
        "�t�F���X�b�^�y��",
        "���N���[��",
    };

    //
    const int cost = 300;  //���ɕK�v�ȋ��z
    int money = 0;        //���ۂɎg��������

    void Start()
    {

    }

    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Return))
        {
            //�����_���l���擾
            int random = 0;
            //Random.Range()���\�b�h
            //1�ڂ̈����̒l����A2�ڂ̒l-1��
            //�l�̒����烉���_���Œl���擾
            //0����9�̒l������͓�����
            random = Random.Range(0, 10);

            if (random == 0)
            {
                //0�̂Ƃ�
                textCmp.text += "10%�̓�����ł���\n";
                //�A�^���L�������ǉ�
                textCmp.text += DispRareString();
                textCmp.text += "\n";

            }
            else if (random <= 2)
            {
                //1,2�̂Ƃ�
                textCmp.text += "20%�̓�����ł���\n";
            }
            else
            {
                //����ȊO
                textCmp.text += "�O��ł���;(\n";
            }
            Debug.Log(random);

            //�����������z���v�Z
            money += cost;
        }
        //�X�y�[�X������������z��\��
        if (Input.GetKeyDown(KeyCode.Space))
        {
            textCmp.text += "�g����������" + money + "�~\n";
        }
    }
    //�ō����A�������_���Ŏ擾���郁�\�b�h
    string DispRareString()
    {
        //�z��̐����擾
        int num = rareTable.Length;
        int random = Random.Range(0, num);
        //�z��̕�����ԋp
        string str = rareTable[random];
        //������ԋp
        return str;
    }
}