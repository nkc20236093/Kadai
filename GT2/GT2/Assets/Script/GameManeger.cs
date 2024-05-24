using Photon.Pun;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class GameManeger : MonoBehaviour
{
    public static GameManeger instance;
    /// <summary>
    /// ゲームが終了したか
    /// true = 試合中
    /// false = 試合終了
    /// </summary>
    public bool GameEnd;
    public bool ServerFlg;  //サーバーフラグ
    public bool OnSV;       //鯖主が存在するかどうか
    private void Awake()
    {
        if (instance == null)
        {
            instance = this;
            DontDestroyOnLoad(gameObject);
        }
        else
        {
            Destroy(gameObject);
        }
    }
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {

    }
    public void Login(string ip, bool sf)
    {
        //IPアドレスの設定
        PhotonNetwork.PhotonServerSettings.AppSettings.Server = ip;
        //ポート番号の設定
        PhotonNetwork.PhotonServerSettings.AppSettings.Port = 5055;
        //ネットワークへの接続
        PhotonNetwork.ConnectUsingSettings();
        ServerFlg = sf;
        if (ServerFlg && OnSV)
        {
            GameEnd = true;
        }
        //送信回数の設定
        PhotonNetwork.SerializationRate = 1;  //１秒に１回だけ通信する
        NextScene("GameScene");
    }
    public void NextScene(string scnename)
    {
        SceneManager.LoadScene(scnename);
    }
     public void Finish()
    {
#if UNITY_EDITOR
        UnityEditor.EditorApplication.isPlaying = false;//ゲームプレイ終了
#else
    Application.Quit();//ゲームプレイ終了
#endif
    }
}
