using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class test12_sub : MonoBehaviour
{
    public Text textCmp;
    public Text moneyTextCmp;
    // �ۑ�12
    // �K�`���v���O�������쐬���悤
    // �����P�F�P�O�A�K�`���̎���
    // �����Q�F�K�`���Ŏg�������z��\������
    // �����R�F�m���͌��ƂȂ�Q�[�����Q�l�Ɏ���
    // �����Ɍ��̃Q�[�����v�����Ȃ��ꍇ�̓E�}�����Q�l��
    // �E�}���̏ꍇ
    // ��3 = 3%  ��2 = 18% ��1 = 79%
    // �����S�F������z����g���āA���������m��\��
    // ���ō����A�����ŗǂ��i���������ꍇ�͊撣�肷���Ȃ����Ɓj
    // �����T�F�\����Unity�̃Q�[����ʏ�ɕ\�����邱��

    string[] rareTable =
    {
        "LR���l�u�E(��)",
        "�������",
        "LR���̃U�}�X"
    };

    const int cost = 5; // ���ɕK�v�ȋ��z
    int money = 0;�@�@�@�@// ���ۂɎg��������

    void Start()
    {
    }


    void Update()
    {
        // �G���^�[�L�[����͂����Ƃ�
        //if (Input.GetKeyDown(KeyCode.Return))
        //{
        //    for (int i = 0; i < 10; i++)
        //    {
        //        gacha();
        //    }
        //}
    }

    // �ō����A�������_���Ŏ擾���郁�\�b�h
    public string DispRareString()
    {
        int num = rareTable.Length;
        // �����_���̒l���擾
        int random = Random.Range(0, num);
        // �����_���őI�΂ꂽ�������擾
        string str = rareTable[random];
        // ������ԋp
        return str;

    }

    public void gacha() {
        // �����_���l���擾
        int random = 0;
        // Random.Range() ���\�b�h
        // 1�ڂ̈����̒l����A2�ڂ̈����̒l-1��
        // �l�̒����烉���_���Œl���擾
        // 0�`9�̒l������͓�����
        random = Random.Range(0, 10);

        if (random == 0)
        {
            // 0�̂Ƃ�
            //textCmp.text += "SSR���T�C���l���\n";
            // ������L������ǉ��ŕ\��
            textCmp.text += DispRareString();
            textCmp.text += "\n";  // ���s

            //Debug.Log("10��1�̊m���ł���");  // 10��
        }
        else if(random <= 3) 
        {
            //textCmp.text += "LR���̃U�}�X\n";
            textCmp.text += DispRareString();
            textCmp.text += "\n";
        }
        else
        {
            //textCmp.text += "�������";
            textCmp.text+= DispRareString();
            textCmp.text += "\n";
        }

    }
    public void gacha10()
    {
        //�e�L�X�g���N���A
        textCmp.text = "";

        //10�A
        for (int i = 0; i < 10; i++)
        {
            gacha();
            money += cost * i;
            moneyTextCmp.text = "�g�������z" + money.ToString() + "�~";
        }
    }

    public void gacha1()
    {
        //�e�L�X�g�̃N���A
        textCmp.text = "";

        gacha();
        money += cost;
        moneyTextCmp.text =  "�g�������z"+money.ToString()+"�~";
    }

}