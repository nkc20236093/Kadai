using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;

public class test18_sub : MonoBehaviour
{
    public int targetValue = 7;
    // Start is called before the first frame update
    void Start()
    {
        //�ۑ�P�W
        //�A�G���^�[�L�[����͂����Ƃ��C
        //�P�`�U�̒l�������_����Debug.Log��\������
        
        // �A�X�y�[�X�L�[����͂������A
        // �P�`�U�̒l�������_���łQ��\�����A���̌�
        // ���̒l�𑫂����l��\������
        // �\����j�_�C�X��̍��v�l�́Z�Z�ł��B

        // �B �A�ŕ\�����������_���̒l�������l�������ꍇ
        // �]���ڂł��ƕ\������B
        // �\����j1,1�̃]���ڂł��I

        // �C���V�t�g�L�[����͂����ہA
        // ��̃T�C�R���̖ڂ̍��v�l���V�ɂȂ�
        // �g�ݍ��킹��S�ĕ\������B
        // ���v�l�̑g�ݍ��킹��\������ۂ�
        // ���d���[�v��p���邱�ƁB
        // �\����j
        // ���v�l���V�ɂȂ�g�ݍ��킹��
        // 1+6
        // 2+5....�i�ȉ���
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Return))
        {
            int toi1 = Random.Range(1, 7);
            Debug.Log("�_�C�X�̖ڂ�" + toi1);
        }
        if (Input.GetKeyDown(KeyCode.Space))
        {
            int toi2_1= Random.Range(1, 7);
            int toi2_2 = Random.Range(1, 7);
            if (toi2_1 == toi2_2)
            {
                Debug.Log(toi2_1 + "," + toi2_2 + "�̃]���ڂł�");
            }
            int toi2 = toi2_1 + toi2_2;
            Debug.Log("�_�C�X��̍��v�l��"+ toi2 +"�ł�");
        }
        if(Input.GetKeyDown(KeyCode.LeftShift))
        {
                Debug.Log("���v�l��" + targetValue + "�ɂȂ�g�ݍ��킹��");
                for (int i = 1; i < 6; i++)
                {
                    for (int j = 1; j <= 6; j++)
                    {
                        if (i + j == targetValue)
                        {
                            Debug.Log(i + "+" + j);
                        }
                    }
                }
        }
        

    }
}
