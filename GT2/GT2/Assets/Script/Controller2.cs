using UnityEngine;
using Photon.Pun;
using UnityEngine.UI;

public class Controller2 : MonoBehaviourPunCallbacks, IPunObservable
{
    GameObject target;
    Animator animator;
    public int Speed = 5;
    PTest2 pTest;
    Rigidbody rigid;
    Text text1;      //サーバーの点数表示
    Text text2;      //クライアント1の点数表示
    Text text3;      //クライアント2の点数表示
    Text text4;      //クライアント3の点数表示
    private void Start()
    {
        Vector3 r = transform.localEulerAngles;
        r.y = 180;
        transform.localEulerAngles = r;
        animator = GetComponent<Animator>();
        pTest = GameObject.Find("GameObject").GetComponent<PTest2>();
        text1 = GameObject.Find("Text1").GetComponent<Text>();
        text2 = GameObject.Find("Text2").GetComponent<Text>();
        text3 = GameObject.Find("Text3").GetComponent<Text>();
        text4 = GameObject.Find("Text4").GetComponent<Text>();
        // 端末IDを取得
        string id = GetComponent<PhotonView>().ViewID.ToString();
        // プレイヤーの色を変更
        if (id == "1001") GetComponent<Renderer>().material.color = Color.red;
        if (id == "2001") GetComponent<Renderer>().material.color = Color.blue;
        if (id == "3001") GetComponent<Renderer>().material.color = Color.green;
        if (id == "4001") GetComponent<Renderer>().material.color = Color.yellow;
        rigid = GetComponent<Rigidbody>();
        //if (photonView.IsMine)
        //{        
        //    if (pTest.ServerFlg)
        //    {
        //        GetComponent<Renderer>().material.color = Color.red;
        //    }
        //    else
        //    {
        //        GetComponent<Renderer>().material.color = Color.blue;
        //    }
        //}
        //else
        //{
        //    if (pTest.ServerFlg)
        //    {
        //        GetComponent<Renderer>().material.color = Color.blue;
        //    }
        //    else
        //    {
        //        GetComponent<Renderer>().material.color = Color.red;
        //    }
        //}
    }
    void Update()
    {
        if (photonView.IsMine)
        {     //自分のオブジェクトの時
            //カーソルキーの上矢印が押されたとき(Idoleのアニメーション)
            if (Input.GetKey(KeyCode.UpArrow))
            {
                animator.SetInteger("Action", 0);
            }
            //カーソルキーの左矢印が押されたとき(Walkのアニメーション)
            if (Input.GetKey(KeyCode.LeftArrow))
            {
                animator.SetInteger("Action", 1);
            }
            //カーソルキーの左矢印が押されたとき(Runのアニメーション)
            if (Input.GetKey(KeyCode.RightArrow))
            {
                animator.SetInteger("Action", 2);
            }
            //ネットワークオブジェクトの移動する
            float x = Input.GetAxis("Horizontal");
            float y = Input.GetAxis("Vertical");
            transform.Translate(new Vector3(x, y, 0) * Time.deltaTime * Speed);
        }
    }

    // データの送受信
    Vector3 velo;    //受信した移動速度
    Vector3 angul;   //受信した回転速度
    //データの送受信
    void IPunObservable.OnPhotonSerializeView(PhotonStream stream, PhotonMessageInfo info)
    {
        if (stream.IsWriting)   //自分のオブジェクトの時
        {
            //アニメーションパラメーター送信
            stream.SendNext(animator.GetInteger("Action"));
        }
        else                    //他人のオブジェクトの時
        {
            //アニメーションパラメーター受信
            animator.SetInteger("Action", int.Parse(stream.ReceiveNext().ToString()));
        }
    }

    //文字列をVector3に変換
    Vector3 Str2vec3(string str)
    {
        string[] xyz = str.Trim('(', ')').Split(',');   //カッコを削除してカンマで分割
        return (new Vector3(float.Parse(xyz[0]), float.Parse(xyz[1]), float.Parse(xyz[2])));
    }

    //プレイヤーがSphereに接触したとき 
    void OnTriggerEnter(Collider col)
    {
        if (pTest.ServerFlg)        //サーバーだけが行う
        {
            string id = GetComponent<PhotonView>().ViewID.ToString();  //端末のIDを取得
            if (id == "1001") pTest.sc1++;
            if (id == "2001") pTest.sc2++;
            if (id == "3001") pTest.sc3++;
            if (id == "4001") pTest.sc4++;            //RPC(遠隔手続き呼び出し)
            photonView.RPC("TargetHit", RpcTarget.All, pTest.sc1, pTest.sc2, pTest.sc3, pTest.sc4);
            //ネットワークオブジェクトの削除
            PhotonNetwork.Destroy(col.gameObject);
        }
    }
    //すべての端末で実行される
    [PunRPC]
    private void TargetHit(int sc1, int sc2, int sc3, int sc4)
    {
        text1.text = sc1.ToString();        //サーバーの点数表示
        text2.text = sc2.ToString();        //クライアント１の点数表示
        text3.text = sc3.ToString();        //クライアント２の点数表示
        text4.text = sc4.ToString();        //クライアント３の点数表示
    }
}