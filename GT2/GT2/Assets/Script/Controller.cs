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
    Text text1;      //�T�[�o�[�̓_���\��
    Text text2;      //�N���C�A���g1�̓_���\��
    Text text3;      //�N���C�A���g2�̓_���\��
    Text text4;      //�N���C�A���g3�̓_���\��
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
        // �[��ID���擾
        string id = GetComponent<PhotonView>().ViewID.ToString();
        // �v���C���[�̐F��ύX
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
    }

    // �f�[�^�̑���M
    Vector3 velo;       //�ړ����x�̕ۑ�
    Vector3 angul;      //��]���x�̕ۑ�
    // �f�[�^�̑���M
    void IPunObservable.OnPhotonSerializeView(PhotonStream stream, PhotonMessageInfo info)
    {
        if (stream.IsWriting) //�����̃I�u�W�F�N�g�̎�
        {
            string msg = transform.position + ";"                   //�\�����W
                       + transform.localEulerAngles + ";"           //��]�p�x
                       + GetComponent<Rigidbody>().velocity + ";"   //�ړ����x
                       + GetComponent<Rigidbody>().angularVelocity; //��]���x
            stream.SendNext(msg);                                   //���b�Z�[�W�o��
        }
        else                //���l�̃I�u�W�F�N�g�̎�
        {
            string msg = stream.ReceiveNext().ToString();           //���b�Z�[�W����
            string[] p = msg.Split(';');                            //�u;�v�ŋ�؂�
            transform.position = Str2vec3(p[0]);                    //�\�����W�C��
            transform.localEulerAngles = Str2vec3(p[1]);            //��]�p�x�C��
            velo = Str2vec3(p[2]);                                  //�ړ����x�ۑ�
            angul = Str2vec3(p[3]);                                 //��]���x�ۑ�
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
        if (pTest.ServerFlg)        //�T�[�o�[�������s��
        {
            bool b = false;
            //�v���C���[��Sphere�ɐڐG�����Ƃ� 
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
        string id = GetComponent<PhotonView>().ViewID.ToString();  //�[����ID���擾
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
        //RPC(���u�葱���Ăяo��)
        photonView.RPC(nameof(TargetHit), RpcTarget.All, pTest.sc1, pTest.sc2, pTest.sc3, pTest.sc4);
        Destroy(GetComponent<SphereCollider>());
        yield return new WaitForSeconds(0.5f);
        //�l�b�g���[�N�I�u�W�F�N�g�̍폜
        PhotonNetwork.Destroy(g.gameObject);
    }

    //���ׂĂ̒[���Ŏ��s�����
    [PunRPC]
    private void TargetHit(int sc1, int sc2, int sc3, int sc4)
    {
        text1.text = sc1.ToString();        //�T�[�o�[�̓_���\��
        text2.text = sc2.ToString();        //�N���C�A���g�P�̓_���\��
        text3.text = sc3.ToString();        //�N���C�A���g�Q�̓_���\��
        text4.text = sc4.ToString();        //�N���C�A���g�R�̓_���\��
    }
}