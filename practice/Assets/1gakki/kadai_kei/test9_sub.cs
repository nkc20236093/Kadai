using System.Collections;
using System.Collections.Generic;
using TMPro;
using Unity.VisualScripting;
using UnityEngine;

public class test9_sub : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        // �ۑ�9-1
        // 1,2,3,4,5�̗v�f������
        // �����^�̔z��a���쐬���A
        // for�����g���āAa�̔z��̒l��S�ĕ\������

        int[] a = { 1, 2, 3, 4, 5, };
        for (int i = 0; i < a.Length; i++)
        {
            Debug.Log("a [" + i + " ] =" + a[i]);
        }

        // �ۑ�9-2
        // �t�A�āA�H�A�~�Ƃ���������̗v�f������
        // ������^�̔z��b���쐬���A
        // for�����g���āAb�̔z��̕�����S�ĕ\������
        // ���̌�A
        // �u�D���ȋG�߂́Z�Z�ł��v���Z�Z�͔z����g��
        // �ƕ\������

        string[] b = { "�t", "��", "�H", "�~" };
        for (int w = 0; w < b.Length; ++w)
        {
            Debug.Log(b[w]);
        }
        Debug.Log("�D���ȋG�߂�" + b[3] +"�ł�");

        // �ۑ�9-3
        // 20,42,58,31,68
        // ��L�̗v�f���������^�̔z��c���쐬���A
        // �z��c�̑S�Ă̒l���v�Z���A
        // �u�z��c�̗v�f�𑫂������v�́����v
        // �z��c�̑S�Ă̒l�̕��ϒl���v�Z��
        // �u�z��c�̗v�f�̕��ϒl�́����v
        // �ƂȂ�悤�ɕ\�� ���Z�Z�͕ϐ����g�����v�Z����

        int[] c = { 20, 42, 58, 31, 68 };
        int lenghe = c.Length;
        int sum = 0;
        for(int q = 0; q < lenghe; ++q) 
        {
            sum += c[q];
        }
        Debug.Log("�z��c�̗v�f�𑫂������v��" + sum );
        Debug.Log("�z��c�̗v�f�̕��ϒl��"+ sum/5);

         
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
