using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class test13_sub : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        // �ۑ�P�S�|�P
        // �ċA���\�b�h���쐬
        // �߂�l�F�Ȃ�
        // ���O�FNumberDisp
        // �����F�����^��n
        // �ċA�Ăяo�������āA
        // �����̐��l���O�ɂȂ�܂ŏ��Ԃɕ\��
        // ��)NumberDisp(5)
        // 5,4,3,2,1
        NumberDisp(5);

        // �ۑ�P�S�|�Q
        // �ċA���\�b�h���쐬�A
        // �߂�l�Fint
        // ���O�FNumberAdd
        // �����F�����^��n
        // �ċA�Ăяo�����s���A
        // �����̐��l���O�ɂȂ�܂Œl���f�N�������g���A
        // �S�Ă̒l�̍��v�l��ԋp����
        // ��jDebug.log(NumberAdd(10))��55�ƕ\�������
        // 10+9+8+7+6+5+4+3+2+1�����s�����
        int sum = NumberAdd(10);
        Debug.Log(sum);
    }

    // Update is called once per frame
    void Update()
    {
        
    }
    
    void NumberDisp(int n)
    {
        if (n <= 0)
        {
            return;
        }

        Debug.Log(n);
        NumberDisp(n - 1);
    }
    int NumberAdd(int n)
    {
        if (n <= 0)
        {
            return 0;
        }

        return n + NumberAdd(n - 1);
    }
}
