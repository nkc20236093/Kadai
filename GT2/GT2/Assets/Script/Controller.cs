using UnityEngine;
using Photon.Pun;
using UnityEngine.UI;
using System.Collections;
using UnityEngine.SceneManagement;

public class Controller : MonoBehaviourPunCallbacks, IPunObservable
{
    float ResultTime;
    float TimerCount = 0; //���Ԃ̃J�E���^
    Text time;
    const int MAXTIME = 45;
    float NowTime;
    [SerializeField] int Speed = 5;
    PTest pTest;
    Rigidbody rigid;
    private Text[] text = new Text[4];      //�T�[�o�[�̓_���\��
    [PunRPC]
    private void Start()
    {
        time = GameObject.Find("Time").GetComponent<Text>();
        NowTime = MAXTIME;
        Vector3 r = transform.localEulerAngles;
        r.y = 180;
        transform.localEulerAngles = r;
        pTest = GameObject.Find("GameObject").GetComponent<PTest>();
        // �[��ID���擾
        string id = GetComponent<PhotonView>().ViewID.ToString();
        // �v���C���[�̐F��ύX
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
        //�Q�[�����J�n������
        if (GameManeger.instance.GameEnd)
        {
            //���Ԑ���
            TimeUP();
            if (GameManeger.instance.ServerFlg)
            {
                if (GameManeger.instance.GameEnd)
                {
                    ResultTime = 0;
                    //N�b�o�߂�����Sohere���쐬����
                    TimeCreate();
                }
            }
        }
        else
        {
            ResultTime = Mathf.Clamp(ResultTime, 0, 8);
            ResultTime += Time.deltaTime;
            if (ResultTime >= 5)
            {
                GameManeger.instance.Finish();
            }
        }
        //�����̃I�u�W�F�N�g�̎�
        if (photonView.IsMine)
        {
            Vector3 pos = transform.position;
            pos.z = Mathf.Clamp(pos.z, 0, 0);
            transform.position = pos;
            //�l�b�g���[�N�I�u�W�F�N�g�̈ړ�����
            float x = Input.GetAxis("Horizontal");
            float y = Input.GetAxis("Vertical");
            transform.Translate(new Vector3(-x, y, 0) * Time.deltaTime * Speed);
        }
        else
        {
            //�ړ����x���w�肷��
            rigid.velocity = velo;
            //��]���x���w�肷��
            rigid.angularVelocity = angul;
        }
    }

    // �f�[�^�̑���M
    Vector3 velo;    //��M�����ړ����x
    Vector3 angul;   //��M������]���x
    void IPunObservable.OnPhotonSerializeView(PhotonStream stream, PhotonMessageInfo info)
    {
        if (stream.IsWriting) //�����̃I�u�W�F�N�g�̎�
        {
            stream.SendNext(transform.position);                        //�\�����W���M
            stream.SendNext(transform.localEulerAngles);                //��]�p�x���M
            stream.SendNext(GetComponent<Rigidbody>().velocity);        //�ړ����x���M
            stream.SendNext(GetComponent<Rigidbody>().angularVelocity); //��]���x���M
        }
        else   //���l�̃I�u�W�F�N�g�̎�
        {
            transform.position = (Vector3)stream.ReceiveNext();         //�\�����W��M
            transform.localEulerAngles = (Vector3)stream.ReceiveNext(); //��]�p�x��M
            velo = (Vector3)stream.ReceiveNext();                       //�ړ����x��M
            angul = (Vector3)stream.ReceiveNext();                      //��]���x��M
        }
    }

    //�������Vector3�ɕϊ�
    Vector3 Str2vec3(string str)
    {
        string[] xyz = str.Trim('(', ')').Split(',');   //�J�b�R���폜���ăJ���}�ŕ���
        return (new Vector3(float.Parse(xyz[0]), float.Parse(xyz[1]), float.Parse(xyz[2])));
    }

    void OnTriggerEnter(Collider col)
    {
        if (GameManeger.instance.ServerFlg)        //�T�[�o�[�������s��
        {
            bool b = false;
            //�v���C���[��Sphere�ɐڐG�����Ƃ� 
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
        ScoreEffect(g);
        string id = GetComponent<PhotonView>().ViewID.ToString();  //�[����ID���擾
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
        //RPC(���u�葱���Ăяo��)
        photonView.RPC(nameof(TargetHit), RpcTarget.All, pTest.sc[0], pTest.sc[1], pTest.sc[2], pTest.sc[3]);
        yield return new WaitForSeconds(0.5f);
        //�l�b�g���[�N�I�u�W�F�N�g�̍폜
        PhotonNetwork.Destroy(g.gameObject);
    }

    //���ׂĂ̒[���Ŏ��s�����
    [PunRPC]
    private void TargetHit(int sc1, int sc2, int sc3, int sc4)
    {
        text[0].text = sc1.ToString();        //�T�[�o�[�̓_���\��
        text[1].text = sc2.ToString();        //�N���C�A���g�P�̓_���\��
        text[2].text = sc3.ToString();        //�N���C�A���g�Q�̓_���\��
        text[3].text = sc4.ToString();        //�N���C�A���g�R�̓_���\��
    }
    [PunRPC]
    public void ScoreEffect(GameObject g)
    {
        AudioSource audioSource = g.GetComponent<AudioSource>();
        audioSource.Play();
        ParticleSystem particleSystem = g.GetComponentInChildren<ParticleSystem>();
        particleSystem.Play();
        SphereCollider sphere = g.GetComponent<SphereCollider>();
        sphere.enabled = false;
    }
    [PunRPC]
    private void TimeUP()
    {
        time.enabled = true;
        //���Ԃ̃J�E���g
        TimerCount += Time.deltaTime;
        //�^�C���A�b�v
        NowTime -= Time.deltaTime;
        NowTime = Mathf.Clamp(NowTime, 0, MAXTIME);
        time.text = NowTime.ToString();
        if (NowTime <= 0)
        {
            time.enabled = false;
            GameManeger.instance.GameEnd = false;
        }
    }
    [PunRPC]
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
                //�l�b�g���[�N�I�u�W�F�N�g��Sphere�������_���̈ʒu�ɔz�u����
                GameObject gos = PhotonNetwork.Instantiate("Sphere", v, Quaternion.identity);
                //�l�b�g���[�N�I�u�W�F�N�g��bomb�������_���̈ʒu�ɔz�u����
                GameObject gob = PhotonNetwork.Instantiate("bomb", v2, rot);
            }
        }
        else if (NowTime < 30 && NowTime >= 20)
        {
            if (TimerCount > 2.5f)
            {
                TimerCount = 0;
                //�l�b�g���[�N�I�u�W�F�N�g��Sphere�������_���̈ʒu�ɔz�u����
                GameObject gos = PhotonNetwork.Instantiate("Sphere", v, Quaternion.identity);
                //�l�b�g���[�N�I�u�W�F�N�g��bomb�������_���̈ʒu�ɔz�u����
                GameObject gob = PhotonNetwork.Instantiate("bomb", v2, rot);
            }
        }
        else if (NowTime < 20 && NowTime >= 10)
        {
            if (TimerCount > 1.5f)
            {
                TimerCount = 0;
                //�l�b�g���[�N�I�u�W�F�N�g��Sphere�������_���̈ʒu�ɔz�u����
                GameObject gos = PhotonNetwork.Instantiate("Sphere", v, Quaternion.identity);
                //�l�b�g���[�N�I�u�W�F�N�g��bomb�������_���̈ʒu�ɔz�u����
                GameObject gob = PhotonNetwork.Instantiate("bomb", v2, rot);
            }
        }
        else if (NowTime < 10 && NowTime >= 5)
        {
            if (TimerCount > 1)
            {
                TimerCount = 0;
                Debug.Log("�쐬");
                //�l�b�g���[�N�I�u�W�F�N�g��Sphere�������_���̈ʒu�ɔz�u����
                GameObject gos = PhotonNetwork.Instantiate("Sphere", v, Quaternion.identity);
                //�l�b�g���[�N�I�u�W�F�N�g��bomb�������_���̈ʒu�ɔz�u����
                GameObject gob = PhotonNetwork.Instantiate("bomb", v2, rot);
            }
        }
        else if (NowTime < 5)
        {
            if (TimerCount > 0.75f)
            {
                TimerCount = 0;
                //�l�b�g���[�N�I�u�W�F�N�g��Sphere�������_���̈ʒu�ɔz�u����
                GameObject gos = PhotonNetwork.Instantiate("Sphere", v, Quaternion.identity);
                //�l�b�g���[�N�I�u�W�F�N�g��bomb�������_���̈ʒu�ɔz�u����
                GameObject gob = PhotonNetwork.Instantiate("bomb", v2, rot);
            }
        }
    }

}