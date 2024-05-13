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
    public int sc1 = 0;     //�T�[�o�[�̓_��
    public int sc2 = 0;     //�N���C�A���g1�̓_��
    public int sc3 = 0;     //�N���C�A���g2�̓_��
    public int sc4 = 0;     //�N���C�A���g3�̓_��
    public bool ServerFlg;  //�T�[�o�[�t���O
    public bool GameEnd;    //�Q�[�����I��������

    public Text time;
    const int MaxTime = 45;
    float NowTime;
    float ResultTime;
    float MatchTime;
    public void Login(string ip, bool sf, bool start)
    {
        //IP�A�h���X�̐ݒ�
        PhotonNetwork.PhotonServerSettings.AppSettings.Server = ip;
        //�|�[�g�ԍ��̐ݒ�
        PhotonNetwork.PhotonServerSettings.AppSettings.Port = 5055;
        //�l�b�g���[�N�ւ̐ڑ�
        PhotonNetwork.ConnectUsingSettings();
        ServerFlg = sf;
        GameEnd = start;
        //���M�񐔂̐ݒ�
        PhotonNetwork.SerializationRate = 1;  //�P�b�ɂP�񂾂��ʐM����
    }

    // �T�[�o�[�ւ̐ڑ�������������
    public override void OnConnectedToMaster()
    {
        //���[����������΍쐬���Ă��烋�[���Q������
        PhotonNetwork.JoinOrCreateRoom("room", new RoomOptions(), TypedLobby.Default);
    }

    // ���[���ɓ������Ƃ���
    public override void OnJoinedRoom()
    {
        //�r���Q���s��
        //�Q�[�����I������܂őҋ@
        if (GameEnd)
        {
            // �����_���Ȉʒu�Ƀl�b�g���[�N�I�u�W�F�N�g�𐶐�����
            var v = new Vector3(Random.Range(-3f, 3f), Random.Range(-3f, 3f), 0);
            GameObject go = PhotonNetwork.Instantiate("Player", v, Quaternion.identity);
        }
    }
    private void Start()
    {
        NowTime = MaxTime;
        time.enabled = false;
    }
    float TimerCount = 0; //���Ԃ̃J�E���^
    //�ڑ���Ԃ̕\��
    int status = 0;
    private void Update()
    {
        //�T�[�o�[�̂Ƃ��̂�
        if (ServerFlg)
        {
            //�Q�[�����J�n������
            if (GameEnd)
            {
                time.enabled = true;
                NowTime = Mathf.Clamp(NowTime, 0, MaxTime);
                ResultTime = 0;
                NowTime -= Time.deltaTime;
                time.text = NowTime.ToString();
                if (NowTime <= 0)
                {
                    GameEnd = false;
                }
                //���Ԃ̃J�E���g
                TimerCount += Time.deltaTime;
                //N�b�o�߂�����Sohere���쐬����
                TimeCreate();
            }
            else
            {
                NowTime = MaxTime;
                time.text = MaxTime.ToString();
                time.enabled = false;
                ResultTime = Mathf.Clamp(ResultTime, 0, 8);
                ResultTime += Time.deltaTime;
                if (ResultTime >= 8)
                {
                    GameEnd = true;
                }
            }
        }
    }
    void TimeCreate()
    {
        if (NowTime < 45 && NowTime >= 30)
        {
            if (TimerCount > 5)
            {
                TimerCount = 0;
                int r = Random.Range(0, 2);
                var v = new Vector3(Random.Range(-3f, 3f), Random.Range(-3f, 3f), 0);
                if (r == 0)
                {
                    Debug.Log("S�쐬");
                    //�l�b�g���[�N�I�u�W�F�N�g��Sphere�������_���̈ʒu�ɔz�u����
                    GameObject go = PhotonNetwork.Instantiate("Sphere", v, Quaternion.identity);
                }
                else
                {
                    Debug.Log("B�쐬");
                    Quaternion rot = Quaternion.Euler(-90, 0, 180);
                    //�l�b�g���[�N�I�u�W�F�N�g��bomb�������_���̈ʒu�ɔz�u����
                    GameObject go = PhotonNetwork.Instantiate("bomb", v, rot);
                }
            }
        }
        else if (NowTime < 30 && NowTime >= 20)
        {
            if (TimerCount > 4)
            {
                TimerCount = 0;
                int r = Random.Range(0, 2);
                var v = new Vector3(Random.Range(-3f, 3f), Random.Range(-3f, 3f), 0);
                if (r == 0)
                {
                    Debug.Log("S�쐬");
                    //�l�b�g���[�N�I�u�W�F�N�g��Sphere�������_���̈ʒu�ɔz�u����
                    GameObject go = PhotonNetwork.Instantiate("Sphere", v, Quaternion.identity);
                }
                else
                {
                    Debug.Log("B�쐬");
                    Quaternion rot = Quaternion.Euler(-90, 0, 180);
                    //�l�b�g���[�N�I�u�W�F�N�g��bomb�������_���̈ʒu�ɔz�u����
                    GameObject go = PhotonNetwork.Instantiate("bomb", v, rot);
                }
            }
        }
        else if (NowTime < 20 && NowTime >= 10)
        {
            if (TimerCount > 3)
            {
                TimerCount = 0;
                int r = Random.Range(0, 2);
                var v = new Vector3(Random.Range(-3f, 3f), Random.Range(-3f, 3f), 0);
                if (r == 0)
                {
                    Debug.Log("S�쐬");
                    //�l�b�g���[�N�I�u�W�F�N�g��Sphere�������_���̈ʒu�ɔz�u����
                    GameObject go = PhotonNetwork.Instantiate("Sphere", v, Quaternion.identity);
                }
                else
                {
                    Debug.Log("B�쐬");
                    Quaternion rot = Quaternion.Euler(-90, 0, 180);
                    //�l�b�g���[�N�I�u�W�F�N�g��bomb�������_���̈ʒu�ɔz�u����
                    GameObject go = PhotonNetwork.Instantiate("bomb", v, rot);
                }
            }
        }
        else if (NowTime < 10 && NowTime >= 5)
        {
            if (TimerCount > 2)
            {
                TimerCount = 0;
                int r = Random.Range(0, 2);
                var v = new Vector3(Random.Range(-3f, 3f), Random.Range(-3f, 3f), 0);
                if (r == 0)
                {
                    Debug.Log("S�쐬");
                    //�l�b�g���[�N�I�u�W�F�N�g��Sphere�������_���̈ʒu�ɔz�u����
                    GameObject go = PhotonNetwork.Instantiate("Sphere", v, Quaternion.identity);
                }
                else
                {
                    Debug.Log("B�쐬");
                    Quaternion rot = Quaternion.Euler(-90, 0, 180);
                    //�l�b�g���[�N�I�u�W�F�N�g��bomb�������_���̈ʒu�ɔz�u����
                    GameObject go = PhotonNetwork.Instantiate("bomb", v, rot);
                }
            }
        }
        else if (NowTime < 50)
        {
            if (TimerCount > 1)
            {
                TimerCount = 0;
                int r = Random.Range(0, 2);
                var v = new Vector3(Random.Range(-3f, 3f), Random.Range(-3f, 3f), 0);
                if (r == 0)
                {
                    Debug.Log("S�쐬");
                    //�l�b�g���[�N�I�u�W�F�N�g��Sphere�������_���̈ʒu�ɔz�u����
                    GameObject go = PhotonNetwork.Instantiate("Sphere", v, Quaternion.identity);
                }
                else
                {
                    Debug.Log("B�쐬");
                    Quaternion rot = Quaternion.Euler(-90, 0, 180);
                    //�l�b�g���[�N�I�u�W�F�N�g��bomb�������_���̈ʒu�ɔz�u����
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
            Debug.Log("�T�[�o�[�ɐڑ������");
        }
        if (PhotonNetwork.NetworkClientState.ToString() == "Authenticating" && status == 1)
        {
            status = 2;
            Debug.Log("�F�ؒ����");
        }
        if (PhotonNetwork.NetworkClientState.ToString() == "Joining" && status == 2)
        {
            status = 3;
            Debug.Log("���[���ɎQ����");
        }
    }
}
