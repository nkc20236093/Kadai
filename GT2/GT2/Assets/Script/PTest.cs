using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Photon.Pun;
using Photon.Realtime;
using Unity.VisualScripting;
using UnityEngine.UI;
using System.Linq;

public class PTest : MonoBehaviourPunCallbacks
{
    [SerializeField] Text time;
    const int MAXTIME = 45;
    public float NowTime;

    public int[] sc = new int[4];     //サーバーの点数
    // サーバーへの接続が成功した時
    public override void OnConnectedToMaster()
    {
        //ルームが無ければ作成してからルーム参加する
        PhotonNetwork.JoinOrCreateRoom("room", new RoomOptions(), TypedLobby.Default);
    }

    // ルームに入った時
    public override void OnJoinedRoom()
    {
        // ランダムな位置にネットワークオブジェクトを生成する
        var v = new Vector3(Random.Range(-3f, 3f), Random.Range(-3f, 3f), 0);
        GameObject go = PhotonNetwork.Instantiate("Player", v, Quaternion.identity);
    }
    private void Start()
    {
        NowTime = MAXTIME;
    }
    //接続状態の表示
    private void Update()
    {
        time.text = NowTime.ToString("f");
        //サーバーのときのみ
        if (GameManeger.instance.ServerFlg)
        {
            for (int i = 0; i < sc.Length; i++)
            {
                sc[i] = Mathf.Clamp(sc[i], -5, 15);
                if (sc[i] >= 15 || sc[i] <= -5)
                {
                    GameManeger.instance.GameEnd = false;
                }
            }
        }
    }
    //int status = 0;
    private void FixedUpdate()
    {
        //if (PhotonNetwork.NetworkClientState.ToString() == "ConnectingToMasterserver" && status == 0)
        //{
        //    status = 1;
        //    Debug.Log("サーバーに接続中･･･");
        //}
        //if (PhotonNetwork.NetworkClientState.ToString() == "Authenticating" && status == 1)
        //{
        //    status = 2;
        //    Debug.Log("認証中･･･");
        //}
        //if (PhotonNetwork.NetworkClientState.ToString() == "Joining" && status == 2)
        //{
        //    status = 3;
        //    Debug.Log("ルームに参加中");
        //}
    }
}
