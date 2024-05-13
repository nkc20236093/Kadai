using UnityEngine;
using Photon.Pun;
using UnityEngine.UI;
using System.Collections;
using UnityEditor.SceneManagement;

public class Controller : MonoBehaviourPunCallbacks, IPunObservable
{
    GameObject target;
    public int Speed = 5;
    PTest pTest;
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
        pTest = GameObject.Find("GameObject").GetComponent<PTest>();
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
        //自分のオブジェクトの時
        if (photonView.IsMine)
        {
            Vector3 pos = transform.position;
            pos.z = Mathf.Clamp(pos.z, 0, 0);
            transform.position = pos;
            //ネットワークオブジェクトの移動する
            float x = Input.GetAxis("Horizontal");
            float y = Input.GetAxis("Vertical");
            transform.Translate(new Vector3(-x, y, 0) * Time.deltaTime * Speed);
        }
    }

    // データの送受信
    Vector3 velo;       //移動速度の保存
    Vector3 angul;      //回転速度の保存
    // データの送受信
    void IPunObservable.OnPhotonSerializeView(PhotonStream stream, PhotonMessageInfo info)
    {
        if (stream.IsWriting) //自分のオブジェクトの時
        {
            string msg = transform.position + ";"                   //表示座標
                       + transform.localEulerAngles + ";"           //回転角度
                       + GetComponent<Rigidbody>().velocity + ";"   //移動速度
                       + GetComponent<Rigidbody>().angularVelocity; //回転速度
            stream.SendNext(msg);                                   //メッセージ出力
        }
        else                //他人のオブジェクトの時
        {
            string msg = stream.ReceiveNext().ToString();           //メッセージ入力
            string[] p = msg.Split(';');                            //「;」で区切る
            transform.position = Str2vec3(p[0]);                    //表示座標修正
            transform.localEulerAngles = Str2vec3(p[1]);            //回転角度修正
            velo = Str2vec3(p[2]);                                  //移動速度保存
            angul = Str2vec3(p[3]);                                 //回転速度保存
        }
    }

    //文字列をVector3に変換
    Vector3 Str2vec3(string str)
    {
        string[] xyz = str.Trim('(', ')').Split(',');   //カッコを削除してカンマで分割
        return (new Vector3(float.Parse(xyz[0]), float.Parse(xyz[1]), float.Parse(xyz[2])));
    }

    void OnTriggerEnter(Collider col)
    {
        if (pTest.ServerFlg)        //サーバーだけが行う
        {
            bool b = false;
            //プレイヤーがSphereに接触したとき 
            if (col.gameObject.CompareTag("Sphere"))
            {
                b = true;
                Debug.Log("s");
                StartCoroutine(Partical(col.gameObject,b));
            }
            else if (col.gameObject.CompareTag("Bomb"))
            {
                b = false;
                Debug.Log("b");
                StartCoroutine(Partical(col.gameObject, b));
            }
        }
    }
    IEnumerator Partical(GameObject g, bool plmi)
    {
        ParticleSystem particleSystem = g.GetComponentInChildren<ParticleSystem>();
        particleSystem.Play();
        string id = GetComponent<PhotonView>().ViewID.ToString();  //端末のIDを取得
        if (plmi)
        {
            if (id == "1001") pTest.sc1++;
            if (id == "2001") pTest.sc2++;
            if (id == "3001") pTest.sc3++;
            if (id == "4001") pTest.sc4++;
        }
        else
        {
            if (id == "1001") pTest.sc1--;
            if (id == "2001") pTest.sc2--;
            if (id == "3001") pTest.sc3--;
            if (id == "4001") pTest.sc4--;
        }
        //RPC(遠隔手続き呼び出し)
        photonView.RPC(nameof(TargetHit), RpcTarget.All, pTest.sc1, pTest.sc2, pTest.sc3, pTest.sc4);
        Destroy(GetComponent<SphereCollider>());
        yield return new WaitForSeconds(0.5f);
        //ネットワークオブジェクトの削除
        PhotonNetwork.Destroy(g.gameObject);
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