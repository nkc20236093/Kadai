using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Photon.Pun;
using UnityEngine.SceneManagement;

public class GameManager : MonoBehaviour
{
    private void Start()
    {
        //ネットワーク接続されていない場合
        if (!PhotonNetwork.IsConnected)
        {
            //タイトルに戻る
            SceneManager.LoadScene(0);
        }
        else
        {
            //ネットワークオブジェクト生成
            PhotonNetwork.Instantiate("Player", new Vector3(0, 0, 0), Quaternion.identity);
        }
    }
}
