using System.Collections.Generic;
using UnityEngine;
using Photon.Pun;

public class PlayerController : MonoBehaviourPunCallbacks
{
    public Transform viewPoint;//�J�����̈ʒu�I�u�W�F�N�g
    public float mouseSensitivity = 1f;//���_�ړ��̑��x
    private Vector2 mouseInput;//���[�U�[�̃}�E�X���͂��i�[
    private float verticalMouseInput;//y���̉�]���i�[�@��]�𐧌�����������
    private Camera cam;//�J����



    private Vector3 moveDir;//�v���C���[�̓��͂��i�[�i�ړ��j
    private Vector3 movement;//�i�ޕ������i�[����ϐ�
    private float activeMoveSpeed = 4;//���ۂ̈ړ����x



    public Vector3 jumpForce = new Vector3(0, 6, 0);//�W�����v�� 
    public Transform groundCheckPoint;//�n�ʂɌ����ă��C���΂��I�u�W�F�N�g 
    public LayerMask groundLayers;//�n�ʂ��ƔF�����郌�C���[ 
    Rigidbody rb;//


    public float walkSpeed = 4f, runSpeed = 8f;//�����̑��x�A����̑��x


    private bool cursorLock = true;//�J�[�\���̕\��/��\�� 


    public List<Gun> guns = new List<Gun>();//����̊i�[�z��
    private int selectedGun = 0;//�I�𒆂̕���Ǘ��p���l


    private float shotTimer;//�ˌ��Ԋu
    [Tooltip("�����e��")]
    public int[] ammunition;
    [Tooltip("�ō������e��")]
    public int[] maxAmmunition;
    [Tooltip("�}�K�W�����̒e��")]
    public int[] ammoClip;
    [Tooltip("�}�K�W���ɓ���ő�̐�")]
    public int[] maxAmmoClip;


    UIManager uIManager;//UI�Ǘ�


    SpawnManager spawnManager;//�X�|�[���}�l�[�W���[�Ǘ�


    public Animator animator;//�A�j���[�^�[


    public GameObject[] playerModel;//�v���C���[���f�����i�[
    public Gun[] gunsHolder, OtherGunsHolder;//�e�z���_�[


    public int maxHP = 100;//�ő�HP
    private int currentHp;//���݂�HP


    public GameObject hitEffect;//���̃G�t�F�N�g


    GameManager gameManager;//�Q�[���}�l�[�W���[


    private void Awake()
    {
        //�^�O����UIManager��T��
        uIManager = GameObject.FindGameObjectWithTag("UIManager").GetComponent<UIManager>();

        //�^�O����SpawnManager��T��
        spawnManager = GameObject.FindGameObjectWithTag("SpawnManager").GetComponent<SpawnManager>();

        //�^�O����GameManager��T��
        gameManager = GameObject.FindGameObjectWithTag("GameManager").GetComponent<GameManager>();
    }

    private void Start()
    {
        currentHp = maxHP;//���݂�HP��MAXHP�̐��l�ɐݒ�


        //�ϐ��Ƀ��C���J�������i�[
        cam = Camera.main;


        //Rigidbody���i�[
        rb = GetComponent<Rigidbody>();


        //�J�[�\����\��
        UpdateCursorLock();


        //�e��e�L�X�g�X�V
        uIManager.SettingBulletsText(ammoClip[selectedGun], ammunition[selectedGun]);


        //�����_���Ȉʒu�ŃX�|�[��������
        //transform.position = spawnManager.GetSpawnPoint().position;


        guns.Clear();//������

        if (photonView.IsMine)//������������
        {

            foreach (var model in playerModel)//���f���̃p�[�c�����[�v
            {
                model.SetActive(false);//��\��
            }


            foreach (Gun gun in gunsHolder)//�e�̐������[�v
            {
                guns.Add(gun);//���X�g�ɒǉ�
            }

            uIManager.UpdateHP(maxHP, currentHp);//HP���X���C�_�[�ɔ��f

        }
        else//���l��������OtherGunsHolder��\��������
        {
            foreach (Gun gun in OtherGunsHolder)//�e�̐������[�v
            {
                guns.Add(gun);//���X�g�ɒǉ�
            }
        }

        switchGun();//�e��\�������邽��
    }

    private void Update()
    {
        //�����ȊO��
        if (!photonView.IsMine)
        {
            //�߂��Ă���ȍ~�̏������s��Ȃ�
            return;
        }


        //���_�ړ��֐�
        PlayerRotate();

        //�ړ��֐�
        PlayerMove();

        //�n�ʂɂ��Ă���̂����������
        if (IsGround())
        {
            //����̊֐����Ă�
            Run();

            //�W�����v�֐����Ă�
            Jump();
        }

        //�e�̐؂�ւ�
        SwitchingGuns();

        //�`������
        Aim();

        //�ˌ��֐�
        Fire();

        //�����[�h�֐�
        Reload();

        //�J�[�\����\��
        UpdateCursorLock();

        //�A�j���[�^�[�J��
        AnimatorSet();
    }

    //Update�֐����Ă΂ꂽ��Ɏ��s�����
    private void LateUpdate()
    {
        //�����ȊO��
        if (!photonView.IsMine)
        {
            //�߂��Ă���ȍ~�̏������s��Ȃ�
            return;
        }

        //�J�������v���C���[�̎q�ɂ���̂ł͂Ȃ��A�X�N���v�g�ňʒu�����킹��
        cam.transform.position = viewPoint.position;
        cam.transform.rotation = viewPoint.rotation;
    }

    //�����ݒ�ł�0.02�b���ƂɌĂ΂��
    private void FixedUpdate()
    {
        //�����ȊO��
        if (!photonView.IsMine)
        {
            //�߂��Ă���ȍ~�̏������s��Ȃ�
            return;
        }

        //�e��e�L�X�g�X�V
        uIManager.SettingBulletsText(ammoClip[selectedGun], ammunition[selectedGun]);
    }

    /// <summary>
    /// Player�̉���]�Əc�̎��_�ړ����s��
    /// </summary>
    public void PlayerRotate()
    {
        //�ϐ��Ƀ��[�U�[�̃}�E�X�̓������i�[
        mouseInput = new Vector2(Input.GetAxisRaw("Mouse X") * mouseSensitivity,
            Input.GetAxisRaw("Mouse Y") * mouseSensitivity);

        //����]�𔽉f(transform.eulerAngles�̓I�C���[�p�Ƃ��Ă̊p�x���Ԃ����)
        transform.rotation = Quaternion.Euler
            (transform.eulerAngles.x,
            transform.eulerAngles.y + mouseInput.x, //�}�E�X��x���̓��͂𑫂�
            transform.eulerAngles.z);


        //�ϐ���y���̃}�E�X���͕��̐��l�𑫂�
        verticalMouseInput += mouseInput.y;

        //�ϐ��̐��l���ۂ߂�i�㉺�̎��_����j
        verticalMouseInput = Mathf.Clamp(verticalMouseInput, -60f, 60f);

        //�c�̎��_��]�𔽉f(-��t���Ȃ��Ə㉺���]���Ă��܂�)
        viewPoint.rotation = Quaternion.Euler
            (-verticalMouseInput,
            viewPoint.transform.rotation.eulerAngles.y,
            viewPoint.transform.rotation.eulerAngles.z);
    }



    /// <summary>
    /// Player�̈ړ�
    /// </summary>
    public void PlayerMove()
    {
        //�ϐ��̐����Ɛ����̓��͂��i�[����iwasd����̓��́j
        moveDir = new Vector3(Input.GetAxisRaw("Horizontal"),
            0, Input.GetAxisRaw("Vertical"));

        //Debug.Log(moveDir);�����p

        //�Q�[���I�u�W�F�N�g�̂�����x���ɓ��͂��ꂽ�l��������Ɛi�ޕ������o����
        movement = ((transform.forward * moveDir.z) + (transform.right * moveDir.x)).normalized;

        //���݈ʒu�ɐi�ޕ������ړ��X�s�[�h���t���[���ԕb���𑫂�
        transform.position += movement * activeMoveSpeed * Time.deltaTime;
    }


    /// <summary>
    /// �n�ʂɂ��Ă���Ȃ�true
    /// </summary>
    /// <returns></returns>
    public bool IsGround()
    {
        return Physics.Raycast(groundCheckPoint.position, Vector3.down, 0.25f, groundLayers);
    }


    public void Jump()
    {
        //�W�����v�ł���̂�����
        if (IsGround() && Input.GetKeyDown(KeyCode.Space))
        {
            //�u�ԓI�ɐ^��ɗ͂�������
            rb.AddForce(jumpForce, ForceMode.Impulse);
        }
    }


    public void Run()
    {
        //���V�t�g�������Ă���Ƃ��̓X�s�[�h��؂�ւ���
        if (Input.GetKey(KeyCode.LeftShift))
        {
            activeMoveSpeed = runSpeed;
        }
        else
        {
            activeMoveSpeed = walkSpeed;
        }
    }


    public void UpdateCursorLock()
    {
        //���͂�������cursorLock��؂�ւ���
        if (Input.GetKeyDown(KeyCode.Escape))
        {
            cursorLock = false;
        }
        else if (Input.GetMouseButton(0))
        {
            cursorLock = true;
        }

        //cursorLock����ŃJ�[�\���̕\����؂�ւ���
        if (cursorLock)
        {
            //�J�[�\���𒆉��ɌŒ肵�A��\���@https://docs.unity3d.com/ScriptReference/CursorLockMode.html
            Cursor.lockState = CursorLockMode.Locked;
        }
        else
        {
            //�\��
            Cursor.lockState = CursorLockMode.None;
        }
    }


    /// <summary>
    /// �e�̐؂�ւ��L�[���͂����m����
    /// </summary>
    public void SwitchingGuns()
    {
        if (Input.GetAxisRaw("Mouse ScrollWheel") > 0f)
        {
            selectedGun++;//�����e���Ǘ����鐔�l�𑝂₷

            //���X�g���傫�����l�ɂȂ��Ă��Ȃ����m�F
            if (selectedGun >= guns.Count)
            {
                selectedGun = 0;//���X�g���傫�Ȑ��l�ɂȂ�΂O�ɖ߂�
            }

            //���ۂɕ����؂�ւ���֐�
            //switchGun();

            //�e�̐؂�ւ��i���[�����̃v���C���[�S���Ăяo���j
            photonView.RPC("SetGun", RpcTarget.All, selectedGun);

        }
        else if (Input.GetAxisRaw("Mouse ScrollWheel") < 0f)
        {
            selectedGun--;//�����e���Ǘ����鐔�l�����炷


            if (selectedGun < 0)
            {
                selectedGun = guns.Count - 1;//0��菬������΃��X�g�̍ő吔�|�P�̐��l�ɐݒ肷��
            }

            //���ۂɕ����؂�ւ���֐�
            //switchGun();

            //�e�̐؂�ւ��i���[�����̃v���C���[�S���Ăяo���j
            photonView.RPC("SetGun", RpcTarget.All, selectedGun);
        }

        //���l�L�[�̓��͌��m�ŕ����؂�ւ���
        for (int i = 0; i < guns.Count; i++)
        {
            if (Input.GetKeyDown((i + 1).ToString()))//���[�v�̐��l�{�P�����ĕ�����ɕϊ��B���̌�A�����ꂽ������
            {
                selectedGun = i;//�e���������l��ݒ�

                //���ۂɕ����؂�ւ���֐�
                //switchGun();

                //�e�̐؂�ւ��i���[�����̃v���C���[�S���Ăяo���j
                photonView.RPC("SetGun", RpcTarget.All, selectedGun);

            }
        }

    }

    /// <summary>
    /// �e�̐؂�ւ�
    /// </summary>
    void switchGun()
    {
        foreach (Gun gun in guns)//���X�g�����[�v����
        {
            gun.gameObject.SetActive(false);//�e���\��
        }

        guns[selectedGun].gameObject.SetActive(true);//�I�𒆂̏e�̂ݕ\��
    }



    /// <summary>
    /// �E�N���b�N�Ŕ`������
    /// </summary>
    public void Aim()
    {
        //  �}�E�X�E�{�^�������Ă���Ƃ�
        if (Input.GetMouseButton(1))
        {
            //fieldOfView�R���|�[�l���g�̒l��ύX(�J�n�n�_�A�ړI�n�_�A�⊮���l)�@�@�J�n�n�_����ړI�n�_�܂ŕ⊮���l�̊����ŏ��X�ɋ߂Â���
            cam.fieldOfView = Mathf.Lerp(cam.fieldOfView, guns[selectedGun].adsZoom, guns[selectedGun].adsSpeed * Time.deltaTime);
        }
        else
        {   //60�͏����ݒ萔�l
            cam.fieldOfView = Mathf.Lerp(cam.fieldOfView, 60f, guns[selectedGun].adsSpeed * Time.deltaTime);
        }
    }



    /// <summary>
    /// ���N���b�N�̌��m
    /// </summary>
    public void Fire()
    {

        if (Input.GetMouseButton(0) && ammoClip[selectedGun] > 0 && Time.time > shotTimer)
        {
            FiringBullet();
        }

    }

    /// <summary>
    /// �e�ۂ̔���
    /// </summary>
    private void FiringBullet()
    {
        //�I�𒆂̏e�̒e�򌸂炷
        ammoClip[selectedGun]--;

        //Ray(����)���J�����̒�������ɐݒ�
        Ray ray = cam.ViewportPointToRay(new Vector2(.5f, .5f));//�J�����̒��S�����̐��l


        //���C���΂��i�J�n�n�_�ƕ����A���������R���C�_�[�̏��i�[�j
        if (Physics.Raycast(ray, out RaycastHit hit))
        {
            //Debug.Log("���������I�u�W�F�N�g��" + hit.collider.gameObject.name);

            if (hit.collider.gameObject.tag == "Player")//�v���C���[�ɂԂ������ꍇ
            {
                //���̃G�t�F�N�g���l�b�g���[�N��ɐ���
                PhotonNetwork.Instantiate(hitEffect.name, hit.point, Quaternion.identity);

                // �q�b�g�֐���S�v���C���[�ŌĂяo���Č����ꂽ�v���C���[��HP�𓯊�����
                hit.collider.gameObject.GetPhotonView().RPC("Hit", RpcTarget.All, guns[selectedGun].shotDamage, photonView.Owner.NickName, PhotonNetwork.LocalPlayer.ActorNumber);

            }
            else
            {
                //�e���G�t�F�N�g (hit.point�̓R���C�_�[�Ƀq�b�g�����ʒu)�Fhit.point + (hit.normal * .002f)�͂�����Ȃ��悤�ɏ�����ɂ��Ă���
                //hit normal�͓��������I�u�W�F�N�g�ɑ΂��Ē��p�̕������Ԃ����
                //LookRotation�͎w�肵�������ɉ�
                GameObject bulletImpactObject = Instantiate(guns[selectedGun].bulletImpact, hit.point + (hit.normal * .002f), Quaternion.LookRotation(hit.normal, Vector3.up));

                //���Ԍo�߂ŏ�����悤�ɂ���
                Destroy(bulletImpactObject, 10f);
            }



        }

        //�ˌ��Ԋu��ݒ�
        shotTimer = Time.time + guns[selectedGun].shootInterval;


    }


    /// <summary>
    /// �����[�h
    /// </summary>
    private void Reload()
    {
        if (Input.GetKeyDown(KeyCode.R))
        {
            //�����[�h�ŕ�[����e�����擾����
            int amountNeed = maxAmmoClip[selectedGun] - ammoClip[selectedGun];

            //�K�v�Ȓe��ʂƏ����e��ʂ��r
            int ammoAvailable = amountNeed < ammunition[selectedGun] ? amountNeed : ammunition[selectedGun];

            //�e�򂪖��^���̎��̓����[�h�ł��Ȃ�&�e����������Ă���Ƃ�
            if (amountNeed != 0 && ammunition[selectedGun] != 0)
            {
                //�����e�򂩂烊���[�h����e�򕪂�����
                ammunition[selectedGun] -= ammoAvailable;
                //�e�ɑ��U����
                ammoClip[selectedGun] += ammoAvailable;
            }
        }
    }


    private void AnimatorSet()
    {
        //walk����
        if (moveDir != Vector3.zero)
        {
            animator.SetBool("walk", true);

        }
        else
        {
            animator.SetBool("walk", false);
        }

        //run����
        if (Input.GetKey(KeyCode.LeftShift))
        {
            animator.SetBool("run", true);
        }
        else
        {
            animator.SetBool("run", false);
        }

    }


    [PunRPC]//�i�������[���ɂ���j�����[�g�N���C�A���g�ɑ΂��Ẵ��\�b�h�̌Ăяo�����\��
    public void SetGun(int gunNo)
    {
        //�e�̐؂�ւ�
        if (gunNo < guns.Count)
        {
            selectedGun = gunNo;

            switchGun();
        }

    }


    /// <summary>
    /// �G�̒e�ɓ���������Ă΂��֐��i�S�v���C���[�ŋ��L���邽��PunRPC�j
    /// </summary>
    [PunRPC]
    public void Hit(int damage, string name, int actor)//�_���[�W�A�������z�̖��O�A�������z�̔ԍ�
    {
        ReceiveDamage(name, damage, actor);//�_���[�W�֐��Ăяo��

    }


    /// <summary>
    /// �_���[�W���󂯂�֐�
    /// </summary>
    public void ReceiveDamage(string name, int damage, int actor)
    {
        if (photonView.IsMine)//�����Ȃ�
        {
            currentHp -= damage;//�_���[�W


            if (currentHp <= 0)//���݂�HP��0�ȉ��̏ꍇ
            {
                Death(name, actor);//���S�֐����Ă�
            }

            uIManager.UpdateHP(maxHP, currentHp);//HP���X���C�_�[�ɔ��f

        }

    }

    //���S����
    public void Death(string name, int actor)
    {
        currentHp = 0;

        //���S�֐����Ă�
        spawnManager.Die();
        uIManager.UpdateDeathUI(name);


        //�����̃f�X�����㏸������(�����̎��ʔԍ��A�f�X�A���Z���l)
        gameManager.ScoreGet(PhotonNetwork.LocalPlayer.ActorNumber, 1, 1);

        //�����Ă�������̃L�������㏸����(�����Ă����G�̎��ʔԍ��A�L���A���Z���l)
        gameManager.ScoreGet(actor, 0, 1);

    }
}