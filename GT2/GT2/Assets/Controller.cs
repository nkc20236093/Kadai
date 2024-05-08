using UnityEngine;
using Photon.Pun;
using UnityEngine.UI;

public class Controller : MonoBehaviourPunCallbacks
{
    public int Speed = 5;

    PTest ptest;     //PTestスクリプト
    Text text1;      //サーバーの点数表示
    Text text2;      //クライアントの点数表示

    void Start()
    {
        ptest = GameObject.Find("GameObject").GetComponent<PTest>();
        text1 = GameObject.Find("Text1").GetComponent<Text>();
        text2 = GameObject.Find("Text2").GetComponent<Text>();
    }
    void Update()
    {
        if (photonView.IsMine)  //自分のネットワークオブジェクトのとき
        {
            float x = Input.GetAxis("Horizontal");
            float y = Input.GetAxis("Vertical");
            //加速度を加える
            GetComponent<Rigidbody>().AddForce(new Vector3(x, y, 0) * Speed);
        }
    }

    //プレイヤーがSphereに接触したとき 
    void OnTriggerEnter(Collider col)
    {
        if (photonView.IsMine)
        {    //自分のネットワークオブジェクトが接触した
            if (ptest.ServerFlg)
                ptest.sc1++;        //サーバーの点数加算
            else
                ptest.sc2++;        //クライアントの点数加算
        }
        else
        {                    //相手のネットワークオブジェクトが接触した
            if (ptest.ServerFlg)
                ptest.sc2++;        //クライアントの点数加算
            else
                ptest.sc1++;        //サーバーの点数加算
        }
        text1.text = ptest.sc1.ToString();        //サーバーの点数更新
        text2.text = ptest.sc2.ToString();        //クライアントの点数更新
        Destroy(col.gameObject);
    }
}