using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;
using UnityEngine.SocialPlatforms.Impl;

public class test19_sub : MonoBehaviour
{
    
    // Start is called before the first frame update
    void Start()
    {
        int[] score = new int[5];
        // �ۑ�19�@�z��ɂ��Ă̂����炢���
        // �@�v�f����5�̐����^�z��score��錾
        // �A�J��Ԃ������g���āA�z��̗v�f�O����A
        // �v�f�S�܂łɁA�������g���ĂQ���̒l����
        for (int i = 0; i < score.Length; i++)
        {
            score[i] = Random.Range(10, 100);
        }
        //score[1] = Random.Range(10, 99);
        //score[2] = Random.Range(10, 99);
        //score[3] = Random.Range(10, 99);
        //score[4] = Random.Range(10, 99);
        // �B�z��̗v�f��S�ĕ\��
        // �\����j
        // score[0] = �Z�Z
        // score[1] = �Z�Z...�i�ȉ����j
        for (int i = 0; i < score.Length; ++i)
        {
            Debug.Log("score["+i+"]" + score[i]);
        }
        
        //Debug.Log("score[1]" + score[1]);
        //Debug.Log("score[2]" + score[2]);
        //Debug.Log("score[3]" + score[3]);
        //Debug.Log("score[4]" + score[4]);
        // �Cscore�̑S�Ă̗v�f�̍��v�l��\��
        int goukei = score[0]+ score[1]+ score[2]+ score[3]+ score[4];
        Debug.Log("score�z��̍��v�l��" + goukei);
        // �\����jscore�z��̍��v�l�́Z�Z
        // �Dscore�̕��ϒl��\��
        int heikinn = (score[0] + score[1] + score[2] + score[3] + score[4]) / 5;
        Debug.Log("score�z��̕��ϒl��" + heikinn);
        // �\����jscore�z��̕��ϒl�́Z�Z
        // �Escore�z��̕��т𔽓]��������A
        // score�z��̗v�f��S�ĕ\��
        // �\����j
        // score�z��𔽓]���܂����B
        // score[0] = �Z�Z
        // score[1] = �Z�Z...
        // �����]�̗�
        // {22, 31, 55, 0, 99}�̔z�񂪂������Ƃ�����
        // {99, 0, 55, 31, 22}�Ƃ����z��ɂȂ�悤�ɂ���
        System.Array.Reverse(score);
        Debug.Log("score�z��𔽓]���܂����B");
        for (int i = 0; i < score.Length; i++)
        {
            Debug.Log("score[" + i + "]=" + score[i]);
        }
        // EX�i�o��������_�A�o���Ȃ��Ă���o���Ă悢�j
        // �����A�~���ɕ��ѕς��ĕ\��

        //����
        Debug.Log("�����ɕύX");
        System.Array.Sort(score);
        for(int i = 0;i < score.Length; i++)
        {
            Debug.Log("score[" + i + "]" + score[i]);
        }
        //�~��
        Debug.Log("�~���ɕύX");
        System.Array.Sort(score);
        System.Array.Reverse(score);
        for (int i = 0; i < score.Length; i++)
        {
            Debug.Log("score["+i+"]" + score[i]);
        }
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
