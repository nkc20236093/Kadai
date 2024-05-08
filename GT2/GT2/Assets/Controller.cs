using UnityEngine;
using Photon.Pun;
using UnityEngine.UI;

public class Controller : MonoBehaviourPunCallbacks
{
    public int Speed = 5;

    PTest ptest;     //PTest�X�N���v�g
    Text text1;      //�T�[�o�[�̓_���\��
    Text text2;      //�N���C�A���g�̓_���\��

    void Start()
    {
        ptest = GameObject.Find("GameObject").GetComponent<PTest>();
        text1 = GameObject.Find("Text1").GetComponent<Text>();
        text2 = GameObject.Find("Text2").GetComponent<Text>();
    }
    void Update()
    {
        if (photonView.IsMine)  //�����̃l�b�g���[�N�I�u�W�F�N�g�̂Ƃ�
        {
            float x = Input.GetAxis("Horizontal");
            float y = Input.GetAxis("Vertical");
            //�����x��������
            GetComponent<Rigidbody>().AddForce(new Vector3(x, y, 0) * Speed);
        }
    }

    //�v���C���[��Sphere�ɐڐG�����Ƃ� 
    void OnTriggerEnter(Collider col)
    {
        if (photonView.IsMine)
        {    //�����̃l�b�g���[�N�I�u�W�F�N�g���ڐG����
            if (ptest.ServerFlg)
                ptest.sc1++;        //�T�[�o�[�̓_�����Z
            else
                ptest.sc2++;        //�N���C�A���g�̓_�����Z
        }
        else
        {                    //����̃l�b�g���[�N�I�u�W�F�N�g���ڐG����
            if (ptest.ServerFlg)
                ptest.sc2++;        //�N���C�A���g�̓_�����Z
            else
                ptest.sc1++;        //�T�[�o�[�̓_�����Z
        }
        text1.text = ptest.sc1.ToString();        //�T�[�o�[�̓_���X�V
        text2.text = ptest.sc2.ToString();        //�N���C�A���g�̓_���X�V
        Destroy(col.gameObject);
    }
}