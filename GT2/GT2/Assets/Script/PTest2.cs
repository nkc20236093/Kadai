using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Photon.Pun;
using Photon.Realtime;
using Unity.VisualScripting;

public class PTest2 : MonoBehaviourPunCallbacks
{
    public int sc1 = 0;     //�T�[�o�[�̓_��
    public int sc2 = 0;     //�N���C�A���g1�̓_��
    public int sc3 = 0;     //�N���C�A���g2�̓_��
    public int sc4 = 0;     //�N���C�A���g3�̓_��
    public bool ServerFlg;  //�T�[�o�[�t���O
    public void Login(string ip, bool sf)
    {
        //IP�A�h���X�̐ݒ�
        PhotonNetwork.PhotonServerSettings.AppSettings.Server = ip;
        //�|�[�g�ԍ��̐ݒ�
        PhotonNetwork.PhotonServerSettings.AppSettings.Port = 5055;
        //�l�b�g���[�N�ւ̐ڑ�
        PhotonNetwork.ConnectUsingSettings();
        ServerFlg = sf;
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
    GameObject go;
    public override void OnJoinedRoom()
    {
        // �����_���Ȉʒu�Ƀl�b�g���[�N�I�u�W�F�N�g�𐶐�����
        var v = new Vector3(Random.Range(-3f, 3f), Random.Range(-3f, 3f), 0);
        go = PhotonNetwork.Instantiate("Player", v, Quaternion.identity);
    }
    float TimerCount = 0; //���Ԃ̃J�E���^
    //�ڑ���Ԃ̕\��
    int status = 0;
    private void Update()
    {
        //�T�[�o�[�̂Ƃ��̂�
        if (ServerFlg)
        {
            Debug.Log(TimerCount);
            //���Ԃ̃J�E���g
            TimerCount += Time.deltaTime;
            //�T�b�o�߂�����Sohere���쐬����
            if (TimerCount > 5)
            {
                Debug.Log("�쐬");
                TimerCount = 0;
                //�l�b�g���[�N�I�u�W�F�N�g��Sphere�������_���̈ʒu�ɔz�u����
                var v = new Vector3(Random.Range(-3f, 3f), Random.Range(-3f, 3f), 0);
                GameObject go = PhotonNetwork.Instantiate("Sphere", v, Quaternion.identity);
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
