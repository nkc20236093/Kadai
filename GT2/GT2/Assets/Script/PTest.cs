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
    public int[] sc = new int[4];     //サーバーの点数
    public Text time;
    const int MaxTime = 45;
    float NowTime;
    float ResultTime;

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
        NowTime = MaxTime;
        time.enabled = false;
    }
    float TimerCount = 0; //時間のカウンタ
    //接続状態の表示
    private void Update()
    {
        if (GameManeger.instance.GameEnd)
        {
            //時間制限
            TimeUP();
        }
        //サーバーのときのみ
        if (GameManeger.instance.ServerFlg)
        {
            //ゲームが開始したら
            if (GameManeger.instance.GameEnd)
            {
                time.enabled = true;
                ResultTime = 0;
                //N秒経過したらSohereを作成する
                TimeCreate();
            }
            else
            {
                time.enabled = false;
                ResultTime = Mathf.Clamp(ResultTime, 0, 8);
                ResultTime += Time.deltaTime;                
                time.text = MaxTime.ToString();
                if (ResultTime >= 5)
                {
                    GameManeger.instance.Finish();
                }
            }
            for (int i = 0; i < sc.Length; i++)
            {
                sc[i] = Mathf.Clamp(sc[i], -5, 30);
                if (sc[i] >= 30 || sc[i] <= -5)
                {
                    GameManeger.instance.GameEnd = false;
                }
            }
        }
    }
    void TimeCreate()
    {
        Quaternion rot = Quaternion.Euler(-90, 0, 180);
        var v = new Vector3(Random.Range(-9f, 9f), Random.Range(-3f, 4f), 0);
        var v2 = new Vector3(Random.Range(-9f, 9f), Random.Range(-3f, 4f), 0);
        if (NowTime < 45 && NowTime >= 30)
        {
            if (TimerCount > 3)
            {
                TimerCount = 0;
                //ネットワークオブジェクトのSphereをランダムの位置に配置する
                GameObject gos = PhotonNetwork.Instantiate("Sphere", v, Quaternion.identity);
                //ネットワークオブジェクトのbombをランダムの位置に配置する
                GameObject gob = PhotonNetwork.Instantiate("bomb", v2, rot);
            }
        }
        else if (NowTime < 30 && NowTime >= 20)
        {
            if (TimerCount > 2.5f)
            {
                TimerCount = 0;
                //ネットワークオブジェクトのSphereをランダムの位置に配置する
                GameObject gos = PhotonNetwork.Instantiate("Sphere", v, Quaternion.identity);
                //ネットワークオブジェクトのbombをランダムの位置に配置する
                GameObject gob = PhotonNetwork.Instantiate("bomb", v2, rot);
            }
        }
        else if (NowTime < 20 && NowTime >= 10)
        {
            if (TimerCount > 1.5f)
            {
                TimerCount = 0;
                //ネットワークオブジェクトのSphereをランダムの位置に配置する
                GameObject gos = PhotonNetwork.Instantiate("Sphere", v, Quaternion.identity);
                //ネットワークオブジェクトのbombをランダムの位置に配置する
                GameObject gob = PhotonNetwork.Instantiate("bomb", v2, rot);
            }
        }
        else if (NowTime < 10 && NowTime >= 5)
        {
            if (TimerCount > 1)
            {
                TimerCount = 0;
                Debug.Log("作成");
                //ネットワークオブジェクトのSphereをランダムの位置に配置する
                GameObject gos = PhotonNetwork.Instantiate("Sphere", v, Quaternion.identity);
                //ネットワークオブジェクトのbombをランダムの位置に配置する
                GameObject gob = PhotonNetwork.Instantiate("bomb", v2, rot);
            }
        }
        else if (NowTime < 5)
        {
            if (TimerCount > 0.75f)
            {
                TimerCount = 0;
                //ネットワークオブジェクトのSphereをランダムの位置に配置する
                GameObject gos = PhotonNetwork.Instantiate("Sphere", v, Quaternion.identity);
                //ネットワークオブジェクトのbombをランダムの位置に配置する
                GameObject gob = PhotonNetwork.Instantiate("bomb", v2, rot);
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
    [PunRPC]
    private void TimeUP()
    {
        //時間のカウント
        TimerCount += Time.deltaTime;
        //タイムアップ
        NowTime -= Time.deltaTime;
        NowTime = Mathf.Clamp(NowTime, 0, MaxTime);
        time.text = NowTime.ToString();
        if (NowTime <= 0)
        {
            GameManeger.instance.GameEnd = false;
        }
    }
}
