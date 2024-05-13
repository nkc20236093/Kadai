using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Director : MonoBehaviour
{
    public GameObject Object; //メインスクリプト
    public GameObject inputField; //IPアドレスの入力欄
    public GameObject toggle;     //サーバーのチェックボックス

    public void OnClick()
    {
        //ゲームが終了していたら
        if (!Object.GetComponent<PTest>().GameEnd)
        {
            //IPアドレスの取得
            string ip = inputField.GetComponent<InputField>().text;
            //サーバーのチェック
            bool server = toggle.GetComponent<Toggle>().isOn;
            //ログイン処理を呼び出す
            Object.GetComponent<PTest>().Login(ip, server, true);
            //親オブジェクトを非表示(Panelを非表示)
            transform.parent.gameObject.SetActive(false);
        }
    }
}