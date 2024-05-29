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
    [SerializeField] Text time;
    const int MAXTIME = 45;
    public float NowTime;

    public int[] sc = new int[4];     //�T�[�o�[�̓_��
    // �T�[�o�[�ւ̐ڑ�������������
    public override void OnConnectedToMaster()
    {
        //���[����������΍쐬���Ă��烋�[���Q������
        PhotonNetwork.JoinOrCreateRoom("room", new RoomOptions(), TypedLobby.Default);
    }

    // ���[���ɓ�������
    public override void OnJoinedRoom()
    {
        // �����_���Ȉʒu�Ƀl�b�g���[�N�I�u�W�F�N�g�𐶐�����
        var v = new Vector3(Random.Range(-3f, 3f), Random.Range(-3f, 3f), 0);
        GameObject go = PhotonNetwork.Instantiate("Player", v, Quaternion.identity);
    }
    private void Start()
    {
        NowTime = MAXTIME;
    }
    //�ڑ���Ԃ̕\��
    private void Update()
    {
        time.text = NowTime.ToString("f");
        //�T�[�o�[�̂Ƃ��̂�
        if (GameManeger.instance.ServerFlg)
        {
            for (int i = 0; i < sc.Length; i++)
            {
                sc[i] = Mathf.Clamp(sc[i], -5, 15);
                if (sc[i] >= 15 || sc[i] <= -5)
                {
                    GameManeger.instance.GameEnd = false;
                }
            }
        }
    }
    //int status = 0;
    private void FixedUpdate()
    {
        //if (PhotonNetwork.NetworkClientState.ToString() == "ConnectingToMasterserver" && status == 0)
        //{
        //    status = 1;
        //    Debug.Log("�T�[�o�[�ɐڑ������");
        //}
        //if (PhotonNetwork.NetworkClientState.ToString() == "Authenticating" && status == 1)
        //{
        //    status = 2;
        //    Debug.Log("�F�ؒ����");
        //}
        //if (PhotonNetwork.NetworkClientState.ToString() == "Joining" && status == 2)
        //{
        //    status = 3;
        //    Debug.Log("���[���ɎQ����");
        //}
    }
}
