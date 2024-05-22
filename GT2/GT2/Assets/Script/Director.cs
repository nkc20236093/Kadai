using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Director : MonoBehaviour
{
    public GameObject inputField; //IPアドレスの入力欄
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
        //IPアドレスの取得
        string ip = inputField.GetComponent<InputField>().text;
        //親オブジェクトを非表示(Panelを非表示)
        transform.parent.gameObject.SetActive(false);
        GameManeger.instance.Login(ip, SV);
    }
}