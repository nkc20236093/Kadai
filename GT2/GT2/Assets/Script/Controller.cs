using UnityEngine;
using Photon.Pun;
using UnityEngine.UI;
using System.Collections;
using UnityEngine.SceneManagement;

public class Controller : MonoBehaviourPunCallbacks, IPunObservable
{
    [SerializeField] int Speed = 5;
    PTest pTest;
    Rigidbody rigid;
    private Text[] text = new Text[4];      //サーバーの点数表示
    private void Start()
    {
        Vector3 r = transform.localEulerAngles;
        r.y = 180;
        transform.localEulerAngles = r;
        pTest = GameObject.Find("GameObject").GetComponent<PTest>();
        // 端末IDを取得
        string id = GetComponent<PhotonView>().ViewID.ToString();
        // プレイヤーの色を変更
        if (id == "1001") GetComponent<Renderer>().material.color = Color.red;
        if (id == "2001") GetComponent<Renderer>().material.color = Color.blue;
        if (id == "3001") GetComponent<Renderer>().material.color = Color.green;
        if (id == "4001") GetComponent<Renderer>().material.color = Color.yellow;
        rigid = GetComponent<Rigidbody>();
        text[0] = GameObject.Find("Text1").GetComponent<Text>();
        text[1] = GameObject.Find("Text2").GetComponent<Text>();
        text[2] = GameObject.Find("Text3").GetComponent<Text>();
        text[3] = GameObject.Find("Text4").GetComponent<Text>();
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
        else
        {
            //移動速度を指定する
            rigid.velocity = velo;
            //回転速度を指定する
            rigid.angularVelocity = angul;
        }
    }

    // データの送受信
    Vector3 velo;    //受信した移動速度
    Vector3 angul;   //受信した回転速度
    void IPunObservable.OnPhotonSerializeView(PhotonStream stream, PhotonMessageInfo info)
    {
        if (stream.IsWriting) //自分のオブジェクトの時
        {
            stream.SendNext(transform.position);                        //表示座標送信
            stream.SendNext(transform.localEulerAngles);                //回転角度送信
            stream.SendNext(GetComponent<Rigidbody>().velocity);        //移動速度送信
            stream.SendNext(GetComponent<Rigidbody>().angularVelocity); //回転速度送信
        }
        else   //他人のオブジェクトの時
        {
            transform.position = (Vector3)stream.ReceiveNext();         //表示座標受信
            transform.localEulerAngles = (Vector3)stream.ReceiveNext(); //回転角度受信
            velo = (Vector3)stream.ReceiveNext();                       //移動速度受信
            angul = (Vector3)stream.ReceiveNext();                      //回転速度受信
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
        if (GameManeger.instance.ServerFlg)        //サーバーだけが行う
        {
            bool b = false;
            //プレイヤーがSphereに接触したとき 
            if (col.gameObject.CompareTag("Sphere"))
            {
                b = true;
                StartCoroutine(Partical(col.gameObject,b));
            }
            else if (col.gameObject.CompareTag("Bomb"))
            {
                b = false;
                StartCoroutine(Partical(col.gameObject, b));
            }
        }
    }
    IEnumerator Partical(GameObject g, bool plmi)
    {
        ScoreEffec(g);
        string id = GetComponent<PhotonView>().ViewID.ToString();  //端末のIDを取得
        if (plmi)
        {
            if (id == "1001") pTest.sc[0]++;
            if (id == "2001") pTest.sc[1]++;
            if (id == "3001") pTest.sc[2]++;
            if (id == "4001") pTest.sc[3]++;
        }
        else
        {
            if (id == "1001") pTest.sc[0]--;
            if (id == "2001") pTest.sc[1]--;
            if (id == "3001") pTest.sc[2]--;
            if (id == "4001") pTest.sc[3]--;
        }
        //RPC(遠隔手続き呼び出し)
        photonView.RPC(nameof(TargetHit), RpcTarget.All, pTest.sc[0], pTest.sc[1], pTest.sc[2], pTest.sc[3]);
        yield return new WaitForSeconds(0.5f);
        //ネットワークオブジェクトの削除
        PhotonNetwork.Destroy(g.gameObject);
    }

    //すべての端末で実行される
    [PunRPC]
    private void TargetHit(int sc1, int sc2, int sc3, int sc4)
    {
        text[0].text = sc1.ToString();        //サーバーの点数表示
        text[1].text = sc2.ToString();        //クライアント１の点数表示
        text[2].text = sc3.ToString();        //クライアント２の点数表示
        text[3].text = sc4.ToString();        //クライアント３の点数表示
    }
    [PunRPC]
    public void ScoreEffec(GameObject g)
    {
        AudioSource audioSource = g.GetComponent<AudioSource>();
        audioSource.Play();
        ParticleSystem particleSystem = g.GetComponentInChildren<ParticleSystem>();
        particleSystem.Play();
        SphereCollider sphere = g.GetComponent<SphereCollider>();
        sphere.enabled = false;
    }
}