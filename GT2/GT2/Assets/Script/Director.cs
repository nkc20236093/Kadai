using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Director : MonoBehaviour
{
    public GameObject Object; //���C���X�N���v�g
    public GameObject inputField; //IP�A�h���X�̓��͗�
    public GameObject toggle;     //�T�[�o�[�̃`�F�b�N�{�b�N�X

    public void OnClick()
    {
        //IP�A�h���X�̎擾
        string ip = inputField.GetComponent<InputField>().text;
        //�T�[�o�[�̃`�F�b�N
        bool server = toggle.GetComponent<Toggle>().isOn;
        //���O�C���������Ăяo��
        Object.GetComponent<PTest>().Login(ip, server, true);
        //�e�I�u�W�F�N�g���\��(Panel���\��)
        transform.parent.gameObject.SetActive(false);
    }
}