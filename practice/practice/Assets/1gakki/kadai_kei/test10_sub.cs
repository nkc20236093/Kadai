using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UIElements;

public class test10_sub : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        // �ۑ�10-1
        // 10,32,46,59,25
        // �̗v�f�����z��a,
        // �v�f��5����z��b���쐬
        // �z��a�̒l��b�ɑS�ăR�s�[������A
        // �z��b�̒l��for�����g����
        // b[0] = �Z�Z
        // �ƂȂ�悤�ɕ\���i�S�Ă̗v�f���\���j

        int[] a = { 10, 32, 46, 59, 25 };
        int[] b = new int[5];
        b = a;

        for (int i = 0; i < a.Length; ++i)
        {
            Debug.Log("b[" + i + "]=" + b[i]);
        }

        // �ۑ�10-2
        // �z��a�̗v�f�̏��Ԃ𔽓]������悤��
        // �z��a�̗v�f�����ւ��A
        // �z��a�̒l��for�����g����
        // a[0] = �Z�Z
        // �ƂȂ�悤�ɕ\���i�S�Ă̗v�f��\���j
        // ���Z�Z�͔z����g���ĕ\��
            for (int i = 0; i < a.Length / 2; ++i)
        {
            int num = a.Length - 1;
            int temp = a[i];
            a[i] = a[num - i];
            a[num - i] = temp;
        }
        for (int i = 0; i < a.Length; i++)
        {
            Debug.Log("a[" + i + "]=" + a[i]);
        }
        //�\��
        for (int i = 0; i < a.Length; ++i)
        {
            Debug.Log(a[i]);
        }

        // �ۑ�10-3
        // �v�f��3*3�̓񎟌��z��c���쐬
        // ��d���[�v���g���āA
        // 1,2,3, 2,4,6, 3,6,9
        // ��L�̒l��z��c�ɏ��Ԃɑ��
        // ��c[0,0]��c[0,1]��c[0,2]��c[1,0]��c[1,1]...�̂悤�ȏ���
        // for�����g����
        // 1,2,3,
        // 2,4,6,
        // 3,6,9,
        // �ƂȂ�悤�ɕ\��
        // ���z��̒l���g���ĕ\�����邱��

        //int[,] c = new int[3, 3];
        //c[0, 0] = 0;
        //c[0, 1] = 1;
        //c[0, 2] = 2;
        //c[1, 0] = 3;
        //c[1, 1] = 4;
        //c[1, 2] = 5;
        //c[2, 0] = 6;
        //c[2, 1] = 7;
        //c[2, 2] = 8;
        //for (int i = 0; i < 3; ++i)
        //{
        //    for (int j = 0; j < 3; ++j)
        //    {
        //        Debug.Log(c[i, j]);
        //    }
        //}

        int[]q = new int[3];
        q[0] = 1;
        q[1] = 2;
        q[2] = 3;
        int[]r = new int[3];
        r[0] = 2;
        r[1] = 4;
        r[2] = 6;
        int[]s = new int[3];
        s[0] = 3;
        s[1] = 6;
        s[2] = 9;

        for (int i = 0; i < 3; ++i)
        {
            Debug.Log(q[i] + "," + r[i]+","+ s[i]); 
        }
    }
}
