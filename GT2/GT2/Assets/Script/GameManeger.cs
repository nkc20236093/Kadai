using Photon.Pun;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class GameManeger : MonoBehaviour
{
    public static GameManeger instance;
    /// <summary>
    /// �Q�[�����I��������
    /// true = ������
    /// false = �����I��
    /// </summary>
    public bool GameEnd;
    public bool ServerFlg;  //�T�[�o�[�t���O
    public bool OnSV;       //�I�傪���݂��邩�ǂ���
    private bool SV;
    [SerializeField] Image check;
    [SerializeField] Sprite[] sprites;
    public AudioSource audioSource;
    private void Awake()
    {
        if (instance == null)
        {
            instance = this;
            DontDestroyOnLoad(gameObject);
        }
        else
        {
            Destroy(gameObject);
        }
    }
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        Change();
    }
    [PunRPC]
    void Change()
    {
        if (Input.GetKeyDown(KeyCode.Delete))
        {
            SV = !SV;
        }
        if (SV)
        {
            check.sprite = sprites[1];
            OnSV = true;
        }
        else
        {
            check.sprite = sprites[0];
            OnSV = false;
        }
    }

    public void Login(string ip, bool sf)
    {
        //IP�A�h���X�̐ݒ�
        PhotonNetwork.PhotonServerSettings.AppSettings.Server = ip;
        //�|�[�g�ԍ��̐ݒ�
        PhotonNetwork.PhotonServerSettings.AppSettings.Port = 5055;
        //�l�b�g���[�N�ւ̐ڑ�
        PhotonNetwork.ConnectUsingSettings();
        ServerFlg = sf;
        GameEnd = true;
        audioSource.Play();
        //���M�񐔂̐ݒ�
        PhotonNetwork.SerializationRate = 5;  //�P�b�ɂP�񂾂��ʐM����
    }
     public void Finish()
    {
#if UNITY_EDITOR
        UnityEditor.EditorApplication.isPlaying = false;//�Q�[���v���C�I��
#else
    Application.Quit();//�Q�[���v���C�I��
#endif
    }
    bool b;
    public void result()
    {
        if (!b)
        {
            b = true;
            audioSource.Play();
        }
    }
}
