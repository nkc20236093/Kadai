using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class test10 : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        //�z��̃R�s�[
        int[] a = { 1, 2, 3, 4, 5 }; //5�̗v�f�����z��a
        int[] b = new int[5];�@//5�̗v�f�������z��b

        b = a;

        for (int i = 0; i < a.Length; ++i)
        {
            Debug.Log("b[" + i + "]=" + b[i]);
        }
        //�z��̗v�f������R�s�[
        //�z��̃R�s�[�̊�{�͂���
        for (int i = 0; i < a.Length; ++i)
        {
            b[i] = a[i];
        }

        //�z��̓���ւ�
        int[] c = { 100, 75, 50, 25, 0 };
        //���Ԃ̓���ւ�
        for (int i = 0; i < c.Length; ++i)
        {
            //
            int num = c.Length - 1;
            int temp = c[i];//�l���ꎞ�ۑ�
            c[i] = c[num - i];//����ւ�
            c[num - i] = temp;//�ۑ������l������
        }
        //�\��
        for (int i = 0; i < c.Length; ++i)
        {
            Debug.Log(c[i]);
        }

        //�������z��
        //[,]�ő��������w��
        int[,] d = new int[3, 3];
        d[0, 0] = 0;
        d[0, 1] = 1;
        d[0, 2] = 2;
        d[1, 0] = 3;
        d[1, 1] = 4;
        d[1, 2] = 5;
        d[2, 0] = 6;
        d[2, 1] = 7;
        d[2, 2] = 8;
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                Debug.Log("d[" + i + "," + j + "] = " + d[i, j]);
            }
        }
        //�O�����z�������i����܂�g��Ȃ��j

        //�񎟌��z��̏�����
        int[,] f = { { 1, 2, 3 }, { 4, 5, 6 } };
        for (int i = 0; i < 2; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                Debug.Log(f[i, j]);
            }
        }
        Debug.Log(f.GetLength(0));
        Debug.Log(f.GetLength(1));
    }


}
