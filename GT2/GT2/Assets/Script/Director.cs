using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Director : MonoBehaviour
{
    public GameObject inputField; //IP�A�h���X�̓��͗�
    bool SV;
    public void OnClick()
    {
        if (GameManeger.instance.OnSV > 0)
        {
            SV = true;
        }
        else
        {
            SV = false;
        }
        //IP�A�h���X�̎擾
        string ip = inputField.GetComponent<InputField>().text;
        //�e�I�u�W�F�N�g���\��(Panel���\��)
        transform.parent.gameObject.SetActive(false);
        GameManeger.instance.Login(ip, SV);
    }
}