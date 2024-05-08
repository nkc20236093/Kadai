using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Photon.Pun;
using Photon.Realtime;

public class PTest : MonoBehaviourPunCallbacks
{
    public int sc1 = 0;     //�T�[�o�[�̓_��
    public int sc2 = 0;     //�N���C�A���g�̓_��
    public bool ServerFlg;

    public void Login(string ip, bool sf)
    {
        //IP�A�h���X�̐ݒ�
        PhotonNetwork.PhotonServerSettings.AppSettings.Server = ip;
        //�|�[�g�ԍ��̐ݒ�
        PhotonNetwork.PhotonServerSettings.AppSettings.Port = 5055;
        //�l�b�g���[�N�ւ̐ڑ�
        PhotonNetwork.ConnectUsingSettings();
        ServerFlg = sf;
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
        // �����_���Ȉʒu�Ƀl�b�g���[�N�I�u�W�F�N�g�𐶐�����
        var v = new Vector3(Random.Range(-3f, 3f), Random.Range(-3f, 3f), 0);
        GameObject go = PhotonNetwork.Instantiate("Player", v, Quaternion.identity);
        //�T�[�o�[�Ȃ�ԁA�N���C�A���g�Ȃ�ɂ���
        if (ServerFlg)
        {
            go.GetComponent<Renderer>().material.color = Color.red;
        }
        else
        {
            go.GetComponent<Renderer>().material.color = Color.blue;
        }
    }

    float TimerCount = 0; //���Ԃ̃J�E���^
    private void Update()
    {
        //�T�[�o�[�̂Ƃ��̂�
        if (ServerFlg)
        {
            //���Ԃ̃J�E���g
            TimerCount += Time.deltaTime;
            //�T�b�o�߂�����Sohere���쐬����
            if (TimerCount > 5)
            {
                TimerCount = 0;
                //�l�b�g���[�N�I�u�W�F�N�g��Sphere�������_���̈ʒu�ɔz�u����
                var v = new Vector3(Random.Range(-3f, 3f), Random.Range(-3f, 3f), 0);
                GameObject go = PhotonNetwork.Instantiate("Sphere", v, Quaternion.identity);
            }
        }
    }
}