using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Photon.Pun;
using UnityEngine.SceneManagement;
using Photon.Realtime;
using ExitGames.Client.Photon;



//���A���^�C��API�̃C�x���g�R�[���o�b�N�B�T�[�o�[����̃C�x���g�ƁAOpRaiseEvent����ăN���C�A���g���瑗�M���ꂽ�C�x���g���J�o�[���܂��B
//�J�X�^���C�x���g����M���邱�Ƃ��ł���悤�ɂȂ�
public class GameManager : MonoBehaviourPunCallbacks, IOnEventCallback
{
    //�C�x���g�ɂ��ċL�ڂ�����h�L�������g
    //https://doc.photonengine.com/ja-jp/pun/current/gameplay/rpcsandraiseevent#_thy2n6w3gsafi04




    public List<PlayerInfo> playerList = new List<PlayerInfo>();//�v���C���[���������N���X�̃��X�g




    public enum EventCodes : byte//����C�x���g�Fbyte�͈����f�[�^(0 �` 255)
    {
        NewPlayer,//�V�����v���C���[�����}�X�^�[�ɑ���
        ListPlayers,//�S���Ƀv���C���[�������L
        UpdateStat,//�L���f�X���̍X�V
    }



    /// <summary>
    /// �Q�[���̏��
    /// </summary>
    public enum GameState
    {
        Playing,
        Ending
    }



    public GameState state;//��Ԃ��i�[



    UIManager uiManager;//UI
    private List<PlayerInformation> playerInfoList = new List<PlayerInformation>();//playerinfo�̃��X�g




    public int TargetNumber = 3;//�N���A����܂ł̃L����




    public float waitAfterEnding = 5f;//�I�����Ă���̑ҋ@����




    private void Awake()
    {
        uiManager = GameObject.FindGameObjectWithTag("UIManager").GetComponent<UIManager>();//56
    }




    private void Start()
    {
        //�l�b�g���[�N�ڑ�����Ă��Ȃ��ꍇ
        if (!PhotonNetwork.IsConnected)
        {
            //�^�C�g���ɖ߂�
            SceneManager.LoadScene(0);
        }
        else//�q�����Ă���ꍇ
        {
            //�}�X�^�[�Ƀ��[�U�[���𔭐M����
            NewPlayerGet(PhotonNetwork.NickName);



            //��Ԃ��Q�[�����ɐݒ肷��
            state = GameState.Playing;
        }
    }



    private void Update()
    {
        //�^�u�{�^���������ꂽ�Ƃ�
        if (Input.GetKeyDown(KeyCode.Tab))
        {
            //�X�V���J��
            ShowScoreboard();
        }
        else if (Input.GetKeyUp(KeyCode.Tab))//�^�u�{�^�����オ������
        {
            uiManager.ChangeScoreUI();
        }



    }



    //�C�x���g�������ɌĂяo�����
    public void OnEvent(EventData photonEvent)
    {



        if (photonEvent.Code < 200)//200�ȏ��photon���Ǝ��̃C�x���g���g���Ă��邽��200�ȉ��݂̂ɏ���������
        {
            EventCodes eventCode = (EventCodes)photonEvent.Code;//����̃C�x���g�R�[�h���i�[�i�^�ϊ��j
            object[] data = (object[])photonEvent.CustomData;//�C���f�N�T�[��CustomDataKey����āA�C�x���g�̃J�X�^���f�[�^�ɃA�N�Z�X���܂�



            switch (eventCode)
            {
                case EventCodes.NewPlayer://���������C�x���g��NewPlayer�Ȃ�
                    NewPlayerSet(data);//�}�X�^�[�ɐV�K���[�U�[��񏈗�������
                    break;



                case EventCodes.ListPlayers:
                    ListPlayersSet(data);//���[�U�[�������L
                    break;



                case EventCodes.UpdateStat:
                    ScoreSet(data);//
                    break;




            }
        }
    }



    public override void OnEnable()//�R���|�[�l���g���I���ɂȂ�ƌĂ΂��
    {
        //��������Ă���R�[���o�b�N�E�C���^�[�t�F�[�X�̃R�[���o�b�N�p�I�u�W�F�N�g��o�^���܂��B
        PhotonNetwork.AddCallbackTarget(this);//�ǉ�����
    }




    public override void OnDisable()//�R���|�[�l���g���I�t�ɂȂ�ƌĂ΂��
    {
        PhotonNetwork.RemoveCallbackTarget(this);//�폜����
    }






    /// <summary>
    ///  �V�K���[�U�[���l�b�g���[�N�o�R�Ń}�X�^�[�Ɏ����̏��𑗂�
    /// </summary>
    public void NewPlayerGet(string name)//�C�x���g�𔭐�������֐�
    {
        //object�͐F�X�Ȍ^�����邱�Ƃ��ł���F
        object[] info = new object[4];//�f�[�^�i�[�z����쐬
        info[0] = name;//���O
        info[1] = PhotonNetwork.LocalPlayer.ActorNumber;//���[�U�[�Ǘ��ԍ�
        info[2] = 0;//�L��
        info[3] = 0;//�f�X




        // RaiseEvent�ŃJ�X�^���C�x���g�𔭐��F�f�[�^�𑗂�
        PhotonNetwork.RaiseEvent((byte)EventCodes.NewPlayer,//����������C�x���g
            info,//������́i�v���C���[�f�[�^�j
            new RaiseEventOptions { Receivers = ReceiverGroup.MasterClient },//���[���}�X�^�[�����ɑ��M�����ݒ�
            new SendOptions { Reliability = true }//�M�����̐ݒ�F�M���ł���̂Ńv���C���[�ɑ��M�����
        );



    }




    /// <summary>
    ///�����Ă����V�v���C���[�̏������X�g�Ɋi�[����
    /// </summary>
    public void NewPlayerSet(object[] data)//�}�X�^�[���s�������@�C�x���g�������ɍs������
    {
        PlayerInfo player = new PlayerInfo((string)data[0], (int)data[1], (int)data[2], (int)data[3]);//�l�b�g���[�N����v���C���[�����擾



        playerList.Add(player);//���X�g�ɒǉ�



        ListPlayersGet();//�}�X�^�[���擾�����v���C���[���𑼂̃v���C���[�ɋ��L
    }





    /// <summary>
    /// �擾�����v���C���[�������[�����̑S�v���C���[�ɑ��M����
    /// </summary>
    public void ListPlayersGet()//�}�X�^�[���s�������@�C�x���g�𔭐�������֐�
    {
        object[] info = new object[playerList.Count + 1];//�Q�[���̏󋵁��v���C���[���i�[�z��쐬



        info[0] = state;//�ŏ��ɂ̓Q�[���̏󋵂�����



        for (int i = 0; i < playerList.Count; i++) //�Q�����[�U�[�̐������[�v
        {
            object[] temp = new object[4];//�ꎞ�I�i�[����z��



            temp[0] = playerList[i].name;
            temp[1] = playerList[i].actor;
            temp[2] = playerList[i].kills;
            temp[3] = playerList[i].deaths;




            info[i + 1] = temp;//�v���C���[�����i�[���Ă���z��Ɋi�[����B0�ɂ̓Q�[���̏�Ԃ������Ă��邽�߁{�P����B
        }




        //RaiseEvent�ŃJ�X�^���C�x���g�𔭐��F�f�[�^�𑗂�
        PhotonNetwork.RaiseEvent((byte)EventCodes.ListPlayers,////����������C�x���g
            info,//������́i�v���C���[�f�[�^�j
            new RaiseEventOptions { Receivers = ReceiverGroup.All },//�S���ɑ��M����C�x���g�ݒ�
            new SendOptions { Reliability = true }//�M�����̐ݒ�F�M���ł���̂Ńv���C���[�ɑ��M�����
        );
    }





    /// <summary>
    /// ListPlayersSend�ŐV�����v���C���[��񂪑����Ă����̂ŁA���X�g�Ɋi�[����
    /// </summary>
    public void ListPlayersSet(object[] data)//�C�x���g������������Ă΂��֐��@�S�v���C���[�ŌĂ΂��
    {
        playerList.Clear();//���Ɏ����Ă���v���C���[�̃��X�g��������



        state = (GameState)data[0];//�Q�[����Ԃ�ϐ��Ɋi�[




        for (int i = 1; i < data.Length; i++)//1�ɂ��� 0�̓Q�[����ԂȂ̂�1����n�߂�
        {
            object[] info = (object[])data[i];//



            PlayerInfo player = new PlayerInfo(
                (string)info[0],//���O
                (int)info[1],//�Ǘ��ԍ�
                (int)info[2],//�L��
                (int)info[3]);//�f�X




            playerList.Add(player);//���X�g�ɒǉ�





        }



        //�Q�[���̏�Ԕ���
        StateCheck();



    }





    /// <summary>
    /// �L������f�X�����擾����֐�(�v���C���[���ʐ��A�L�����f�X�𐔒l�Ŕ���A���Z���鐔�l)
    /// </summary>
    public void ScoreGet(int actor, int stat, int amount)
    {
        object[] package = new object[] { actor, stat, amount };




        //�f�[�^�𑗂�C�x���g
        PhotonNetwork.RaiseEvent((byte)EventCodes.UpdateStat,//����������C�x���g
            package,//������́i�v���C���[�̃L���f�X�f�[�^�j
            new RaiseEventOptions { Receivers = ReceiverGroup.All },//�S���ɑ��M����C�x���g�ݒ�
            new SendOptions { Reliability = true }//�M�����̐ݒ�F�M���ł���̂Ńv���C���[�ɑ��M�����
        );
    }



    /// <summary>
    /// �󂯎�����f�[�^���烊�X�g�ɃL���f�X����ǉ�
    /// </summary>
    public void ScoreSet(object[] data)
    {
        int actor = (int)data[0];//���ʐ�
        int stat = (int)data[1];//�L���Ȃ̂��f�X�Ȃ̂�
        int amount = (int)data[2];//���Z���鐔�l




        for (int i = 0; i < playerList.Count; i++)//�v���C���[�̐������[�v
        {
            if (playerList[i].actor == actor)//�����擾�����v���C���[�Ɛ��l�����v�����Ƃ�
            {
                switch (stat)
                {
                    case 0://�L��
                        playerList[i].kills += amount;



                        break;



                    case 1://�f�X
                        playerList[i].deaths += amount;



                        break;
                }




                break;//�����͂ł����̂ł���ȍ~for�����񂳂Ȃ����߂Ƀu���C�N����
            }
        }
        TargetScoreCheck();//�X�R�A�m�F
    }





    /// <summary>
    /// �X�R�A�{�[�h��\������֐�
    /// </summary>
    void ShowScoreboard()
    {
        uiManager.ChangeScoreUI();//�X�R�AUI���J��



        foreach (PlayerInformation info in playerInfoList)//���X�g�̐������[�v
        {
            Destroy(info.gameObject);//�X�R�A�{�[�h�ɕ\������Ă����l��l�̐��ѕ\��UI���폜
        }



        playerInfoList.Clear();//���X�g����폜





        foreach (PlayerInfo player in playerList)//�Q�[���ɎQ�����Ă���v���C���[�̐������[�v
        {
            PlayerInformation newPlayerDisplay = Instantiate(uiManager.info, uiManager.info.transform.parent);//�v���C���[����\������I�u�W�F�N�g�𐶐�



            newPlayerDisplay.SetPlayerDetailes(player.name, player.kills, player.deaths);//���������I�u�W�F�N�g�ɐ��т𔽉f



            newPlayerDisplay.gameObject.SetActive(true);//�\��



            playerInfoList.Add(newPlayerDisplay);//���X�g�ɒǉ�
        }




    }




    /// <summary>
    /// �Q�[���N���A������B���������m�F����
    /// </summary>
    void TargetScoreCheck()
    {
        bool clear = false;



        foreach (PlayerInfo player in playerList)//�l�������[�v
        {
            if (player.kills >= TargetNumber && TargetNumber > 0)//��������
            {
                clear = true;//�N���A����
                break;//���[�v������
            }
        }




        if (clear)//�N���A����
        {
            if (PhotonNetwork.IsMasterClient && state != GameState.Ending)
            {
                state = GameState.Ending;//��ԕύX
                ListPlayersGet();//�ŏI�I�ȃv���C���[�����X�V
            }
        }




    }





    public override void OnLeftRoom()//58
    {
        base.OnLeftRoom();//58



        SceneManager.LoadScene(0);//58
    }



    /// <summary>
    /// �Q�[���̏�Ԏ���ŃQ�[���I��
    /// </summary>
    void StateCheck()
    {
        if (state == GameState.Ending)//��Ԃ̔���
        {
            EndGame();//�I���֐����Ă�
        }
    }



    /// <summary>
    /// �Q�[���I���֐�
    /// </summary>
    void EndGame()
    {



        if (PhotonNetwork.IsMasterClient)//�}�X�^�[�Ȃ�
        {
            PhotonNetwork.DestroyAll();//�l�b�g���[�N�ォ��폜
        }



        //�Q�[���I���p�l���\��
        uiManager.OpenEndPanel();



        //�X�R�A�\��
        ShowScoreboard();



        //�J�[�\���\��        
        Cursor.lockState = CursorLockMode.None;




        Invoke(nameof(ProcessingAfterCompletion), waitAfterEnding);
    }




    //�I����̏���
    private void ProcessingAfterCompletion()
    {



        PhotonNetwork.AutomaticallySyncScene = false;//�V�[���̓����ݒ��؂�
        PhotonNetwork.LeaveRoom();//�����𔲂���




    }




    /// <summary>
    ///  �v���C���[�����Ǘ����Ă��郊�X�g����A�v���C���[��������
    /// </summary>
    public void OutPlayerGet(int actor)
    {



        //
        for (int i = 0; i < playerList.Count; i++)
        {
            if (playerList[i].actor == actor)//�����擾�������[�U�[�Ɛ��l�����v�����Ƃ�
            {



                playerList.RemoveAt(i);//���������[�U�[�̏�񂾂��폜



                break;//�����͂ł����̂ł���ȍ~for�����񂳂Ȃ����߂Ƀu���C�N����
            }
        }




        ListPlayersGet();//�v���C���[�����X�V



    }



}






[System.Serializable]
public class PlayerInfo//�v���C���[�����Ǘ�����N���X
{
    public string name;//���O
    public int actor, kills, deaths;//�ԍ��A�L���A�f�X



    //�����i�[
    public PlayerInfo(string _name, int _actor, int _kills, int _death)
    {
        name = _name;
        actor = _actor;
        kills = _kills;
        deaths = _death;
    }
}