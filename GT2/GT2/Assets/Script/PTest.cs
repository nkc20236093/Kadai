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
    public bool ServerFlg;  //サーバーフラグ
    public bool GameEnd;    //ゲームが終了したか

    public Text time;
    const int MaxTime = 45;
    float NowTime;
    float ResultTime;
    float MatchTime;
    public void Login(string ip, bool sf, bool start)
    {
        //IPアドレスの設定
        PhotonNetwork.PhotonServerSettings.AppSettings.Server = ip;
        //ポート番号の設定
        PhotonNetwork.PhotonServerSettings.AppSettings.Port = 5055;
        //ネットワークへの接続
        PhotonNetwork.ConnectUsingSettings();
        ServerFlg = sf;
        GameEnd = start;
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
    public override void OnJoinedRoom()
    {
        //途中参加不可
        //ゲームが終了するまで待機
        if (GameEnd)
        {
            // ランダムな位置にネットワークオブジェクトを生成する
            var v = new Vector3(Random.Range(-3f, 3f), Random.Range(-3f, 3f), 0);
            GameObject go = PhotonNetwork.Instantiate("Player", v, Quaternion.identity);
        }
    }
    private void Start()
    {
        NowTime = MaxTime;
        time.enabled = false;
    }
    float TimerCount = 0; //時間のカウンタ
    //接続状態の表示
    int status = 0;
    private void Update()
    {
        //サーバーのときのみ
        if (ServerFlg)
        {
            //ゲームが開始したら
            if (GameEnd)
            {
                ResultTime = 0;
                //時間のカウント
                TimerCount += Time.deltaTime;
                //N秒経過したらSohereを作成する
                TimeCreate();
            }
            else
            {
                ResultTime = Mathf.Clamp(ResultTime, 0, 8);
                ResultTime += Time.deltaTime;                time.text = MaxTime.ToString();
                if (ResultTime >= 5)
                {
                    GameEnd = true;
                }
            }
            for (int i = 0; i < sc.Length; i++)
            {
                sc[i] = Mathf.Clamp(sc[i], -5, 30);
                if (sc[i] >= 30 || sc[i] <= -5)
                {
                    GameEnd = false;
                }
            }
        }
    }
    void TimeCreate()
    {
        if (NowTime < 45 && NowTime >= 30)
        {
            if (TimerCount > 3)
            {
                TimerCount = 0;
                int r = Random.Range(0, 2);
                var v = new Vector3(Random.Range(-3f, 3f), Random.Range(-3f, 3f), 0);
                if (r == 0)
                {
                    Debug.Log("S作成");
                    //ネットワークオブジェクトのSphereをランダムの位置に配置する
                    GameObject go = PhotonNetwork.Instantiate("Sphere", v, Quaternion.identity);
                }
                else
                {
                    Debug.Log("B作成");
                    Quaternion rot = Quaternion.Euler(-90, 0, 180);
                    //ネットワークオブジェクトのbombをランダムの位置に配置する
                    GameObject go = PhotonNetwork.Instantiate("bomb", v, rot);
                }
            }
        }
        else if (NowTime < 30 && NowTime >= 20)
        {
            if (TimerCount > 2.5f)
            {
                TimerCount = 0;
                int r = Random.Range(0, 2);
                var v = new Vector3(Random.Range(-3f, 3f), Random.Range(-3f, 3f), 0);
                if (r == 0)
                {
                    Debug.Log("S作成");
                    //ネットワークオブジェクトのSphereをランダムの位置に配置する
                    GameObject go = PhotonNetwork.Instantiate("Sphere", v, Quaternion.identity);
                }
                else
                {
                    Debug.Log("B作成");
                    Quaternion rot = Quaternion.Euler(-90, 0, 180);
                    //ネットワークオブジェクトのbombをランダムの位置に配置する
                    GameObject go = PhotonNetwork.Instantiate("bomb", v, rot);
                }
            }
        }
        else if (NowTime < 20 && NowTime >= 10)
        {
            if (TimerCount > 1.5f)
            {
                TimerCount = 0;
                int r = Random.Range(0, 2);
                var v = new Vector3(Random.Range(-3f, 3f), Random.Range(-3f, 3f), 0);
                if (r == 0)
                {
                    Debug.Log("S作成");
                    //ネットワークオブジェクトのSphereをランダムの位置に配置する
                    GameObject go = PhotonNetwork.Instantiate("Sphere", v, Quaternion.identity);
                }
                else
                {
                    Debug.Log("B作成");
                    Quaternion rot = Quaternion.Euler(-90, 0, 180);
                    //ネットワークオブジェクトのbombをランダムの位置に配置する
                    GameObject go = PhotonNetwork.Instantiate("bomb", v, rot);
                }
            }
        }
        else if (NowTime < 10 && NowTime >= 5)
        {
            if (TimerCount > 1)
            {
                TimerCount = 0;
                int r = Random.Range(0, 2);
                var v = new Vector3(Random.Range(-3f, 3f), Random.Range(-3f, 3f), 0);
                if (r == 0)
                {
                    Debug.Log("S作成");
                    //ネットワークオブジェクトのSphereをランダムの位置に配置する
                    GameObject go = PhotonNetwork.Instantiate("Sphere", v, Quaternion.identity);
                }
                else
                {
                    Debug.Log("B作成");
                    Quaternion rot = Quaternion.Euler(-90, 0, 180);
                    //ネットワークオブジェクトのbombをランダムの位置に配置する
                    GameObject go = PhotonNetwork.Instantiate("bomb", v, rot);
                }
            }
        }
        else if (NowTime < 50)
        {
            if (TimerCount > 0.75f)
            {
                TimerCount = 0;
                int r = Random.Range(0, 2);
                var v = new Vector3(Random.Range(-3f, 3f), Random.Range(-3f, 3f), 0);
                if (r == 0)
                {
                    Debug.Log("S作成");
                    //ネットワークオブジェクトのSphereをランダムの位置に配置する
                    GameObject go = PhotonNetwork.Instantiate("Sphere", v, Quaternion.identity);
                }
                else
                {
                    Debug.Log("B作成");
                    Quaternion rot = Quaternion.Euler(-90, 0, 180);
                    //ネットワークオブジェクトのbombをランダムの位置に配置する
                    GameObject go = PhotonNetwork.Instantiate("bomb", v, rot);
                }
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
