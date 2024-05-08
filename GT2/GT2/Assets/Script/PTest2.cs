using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Photon.Pun;
using Photon.Realtime;
using Unity.VisualScripting;

public class PTest2 : MonoBehaviourPunCallbacks
{
    public int sc1 = 0;     //サーバーの点数
    public int sc2 = 0;     //クライアント1の点数
    public int sc3 = 0;     //クライアント2の点数
    public int sc4 = 0;     //クライアント3の点数
    public bool ServerFlg;  //サーバーフラグ
    public void Login(string ip, bool sf)
    {
        //IPアドレスの設定
        PhotonNetwork.PhotonServerSettings.AppSettings.Server = ip;
        //ポート番号の設定
        PhotonNetwork.PhotonServerSettings.AppSettings.Port = 5055;
        //ネットワークへの接続
        PhotonNetwork.ConnectUsingSettings();
        ServerFlg = sf;
        //送信回数の設定
        PhotonNetwork.SerializationRate = 1;  //１秒に１回だけ通信する
    }

    // サーバーへの接続が成功した時
    public override void OnConnectedToMaster()
    {
        //ルームが無ければ作成してからルーム参加する
        PhotonNetwork.JoinOrCreateRoom("room", new RoomOptions(), TypedLobby.Default);
    }

    // ルームに入ったとき時
    GameObject go;
    public override void OnJoinedRoom()
    {
        // ランダムな位置にネットワークオブジェクトを生成する
        var v = new Vector3(Random.Range(-3f, 3f), Random.Range(-3f, 3f), 0);
        go = PhotonNetwork.Instantiate("Player", v, Quaternion.identity);
    }
    float TimerCount = 0; //時間のカウンタ
    //接続状態の表示
    int status = 0;
    private void Update()
    {
        //サーバーのときのみ
        if (ServerFlg)
        {
            Debug.Log(TimerCount);
            //時間のカウント
            TimerCount += Time.deltaTime;
            //５秒経過したらSohereを作成する
            if (TimerCount > 5)
            {
                Debug.Log("作成");
                TimerCount = 0;
                //ネットワークオブジェクトのSphereをランダムの位置に配置する
                var v = new Vector3(Random.Range(-3f, 3f), Random.Range(-3f, 3f), 0);
                GameObject go = PhotonNetwork.Instantiate("Sphere", v, Quaternion.identity);
            }
        }
    }
    private void FixedUpdate()
    {
        if (PhotonNetwork.NetworkClientState.ToString() == "ConnectingToMasterserver" && status == 0)
        {
            status = 1;
            Debug.Log("サーバーに接続中･･･");
        }
        if (PhotonNetwork.NetworkClientState.ToString() == "Authenticating" && status == 1)
        {
            status = 2;
            Debug.Log("認証中･･･");
        }
        if (PhotonNetwork.NetworkClientState.ToString() == "Joining" && status == 2)
        {
            status = 3;
            Debug.Log("ルームに参加中");
        }
    }
}
