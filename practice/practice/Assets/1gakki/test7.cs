using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;

public class test7 : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        //�J��Ԃ���

        //for��
        //�������ƌp�������ƌ㏈��
        int a = 0;
        for (int i = 0; i < 5; i++)
        {
            a++;
            Debug.Log("a =" + a);
            //�㏈����for���̍Ō�Ŏ��s
            Debug.Log("i = " + i);
        }
        //{}���Ȃ��ƃZ�~�R�����܂ŌJ��Ԃ�
        //{}���Ȃ����Ƃɂ��G���[���N���₷������
        //{}�Ŋ�{�I�Ɉ͂ނ��Ƃɂ���
        //for (int i = 0; < 5; **!)
        //    Debug.Log("I = " + i);
        //    Debug.Log("�J��Ԃ��Ȃ�");

        //do while��
        //do{}���̒��g�����s��
        //while(������)����true�̊�
        //do{}�����J��Ԃ�
        int b = 5;
        do
        {
            b--;
            Debug.Log("b =" + b);
        } while (b != 0);

        int c = 0;
        while (c != 0);
        {
            Debug.Log("c = " + c);
        }
        // �������[�v
        int d = 0;
        while (true)
        {
            ++d;
            Debug.Log("d=" + d);
            if (d > 10000)
            {
                //break��
                //for��while�����I������
                //�@��{}�̊O�܂ŏ������ړ�
                break;
            }
        }
    }

    //�J��Ԃ����̎g������
    //���܂��������[�v������̂�
    //for�����g��(���Ƃ�����)
    //����ȏ����Ȃǂ�while�����g��

// Update is called once per frame
void Update()
    {
        
    }
}
