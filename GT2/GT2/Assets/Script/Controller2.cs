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
    Text text1;      //�T�[�o�[�̓_���\��
    Text text2;      //�N���C�A���g1�̓_���\��
    Text text3;      //�N���C�A���g2�̓_���\��
    Text text4;      //�N���C�A���g3�̓_���\��
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
        if (photonView.IsMine)
        {     //�����̃I�u�W�F�N�g�̎�
            //�J�[�\���L�[�̏��󂪉����ꂽ�Ƃ�(Idole�̃A�j���[�V����)
            if (Input.GetKey(KeyCode.UpArrow))
            {
                animator.SetInteger("Action", 0);
            }
            //�J�[�\���L�[�̍���󂪉����ꂽ�Ƃ�(Walk�̃A�j���[�V����)
            if (Input.GetKey(KeyCode.LeftArrow))
            {
                animator.SetInteger("Action", 1);
            }
            //�J�[�\���L�[�̍���󂪉����ꂽ�Ƃ�(Run�̃A�j���[�V����)
            if (Input.GetKey(KeyCode.RightArrow))
            {
                animator.SetInteger("Action", 2);
            }
            //�l�b�g���[�N�I�u�W�F�N�g�̈ړ�����
            float x = Input.GetAxis("Horizontal");
            float y = Input.GetAxis("Vertical");
            transform.Translate(new Vector3(x, y, 0) * Time.deltaTime * Speed);
        }
    }

    // �f�[�^�̑���M
    Vector3 velo;    //��M�����ړ����x
    Vector3 angul;   //��M������]���x
    //�f�[�^�̑���M
    void IPunObservable.OnPhotonSerializeView(PhotonStream stream, PhotonMessageInfo info)
    {
        if (stream.IsWriting)   //�����̃I�u�W�F�N�g�̎�
        {
            //�A�j���[�V�����p�����[�^�[���M
            stream.SendNext(animator.GetInteger("Action"));
        }
        else                    //���l�̃I�u�W�F�N�g�̎�
        {
            //�A�j���[�V�����p�����[�^�[��M
            animator.SetInteger("Action", int.Parse(stream.ReceiveNext().ToString()));
        }
    }

    //�������Vector3�ɕϊ�
    Vector3 Str2vec3(string str)
    {
        string[] xyz = str.Trim('(', ')').Split(',');   //�J�b�R���폜���ăJ���}�ŕ���
        return (new Vector3(float.Parse(xyz[0]), float.Parse(xyz[1]), float.Parse(xyz[2])));
    }

    //�v���C���[��Sphere�ɐڐG�����Ƃ� 
    void OnTriggerEnter(Collider col)
    {
        if (pTest.ServerFlg)        //�T�[�o�[�������s��
        {
            string id = GetComponent<PhotonView>().ViewID.ToString();  //�[����ID���擾
            if (id == "1001") pTest.sc1++;
            if (id == "2001") pTest.sc2++;
            if (id == "3001") pTest.sc3++;
            if (id == "4001") pTest.sc4++;            //RPC(���u�葱���Ăяo��)
            photonView.RPC("TargetHit", RpcTarget.All, pTest.sc1, pTest.sc2, pTest.sc3, pTest.sc4);
            //�l�b�g���[�N�I�u�W�F�N�g�̍폜
            PhotonNetwork.Destroy(col.gameObject);
        }
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