//--------------------------------------------------------------------
// �ȖځF�Q�[���A���S���Y��1�N
// ���e�F�����Ă�������ɒe���o��
// �����F2023.06.02 Ken.D.Ohishi
//--------------------------------------------------------------------
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class PlayerController006 : MonoBehaviour
{
    AudioSource audioSource;
    [SerializeField] AudioClip clip;

    [SerializeField] float Ray_distance;
    [SerializeField] float Jump_power;
    new Rigidbody rigidbody;
    bool Ground;
    public LayerMask lmask;
    public Text speedText;      // UI-TEXT�I�u�W�F�N�g��ۑ�����
    public Text shotLevelText;  // UI-TEXT�I�u�W�F�N�g��ۑ�����
    public Text hakiText;       // UI-TEXT�I�u�W�F�N�g��ۑ�����
    GameObject bulletPre;       // �e�̃v���n�u��ۑ�����
    GameObject firePre;         // �R���Ă�G�t�F�N�g�̃v���n�u��z��

    Vector3 dir;                // �ړ�������ۑ�����ϐ�
    float speed;                // �ړ��ʂ�ۑ�����ϐ�
    float axel;                 // �����x��ۑ�����ϐ�
    int bdash;                  // B�_�b�V���W����ۑ�����ϐ�
    float rad;                  // ��]�p�x��ۑ�����ϐ�
    float rotSpeed;             // ��]���x��ۑ�����ϐ�
    float timer;                // �e�̔��ˊԊu����p
    int   power;                // ����̋���
    SphereCollider spCollider;  // �e�C�p�X�t�B�A�R���C�_�[�ۑ��p
    bool hakiFlg;               // �e�C�t���O
    float hakiSpeed;            // �e�C�X�s�[�h
    float hakiAccel;            // �e�C�����x

    const float MAX_SPEED = 10;  // �X�s�[�h�̏���l���w�肷��萔

    void Start()
    {
        rigidbody = GetComponent<Rigidbody>();
        audioSource = GetComponent<AudioSource>();

        // �e�ϐ�������
        dir      = Vector3.zero;
        speed    = 0;
        axel     = 0.04f;
        bdash    = 1;
        rad      = 0;
        rotSpeed = 1.5f;
        timer    = 0;
        power    = 0;

        // Resources�t�H���_���ɂ���e�̃v���n�u���擾����
        bulletPre = (GameObject)Resources.Load("BulletPre");
        firePre = (GameObject)Resources.Load("MyFireMobile");

        // SphereCollider�R���|�[�l���g���擾
        spCollider = GetComponent<SphereCollider>();
        hakiFlg = false;
        hakiSpeed = 3;
        hakiAccel = 0.02f;

    }

    void Update()
    {
        // �v���C�t���O��OFF�ɂȂ����炱�̐�̖��߂͎��s���Ȃ�
        if (GameDirector.isPlaying == false) return;

        // ���E�L�[�ŉ�]
        rad = Input.GetAxisRaw("Horizontal") * rotSpeed;
        transform.Rotate(Vector3.up, rad);

        // ���L�[�őO�i�A���L�[�Ō��
        float z = Input.GetAxisRaw("Vertical");

        // �㉺�L�[��������Ă���Ƃ�
        if(z != 0)
        {
            // �����x�𑝂₷
            speed += axel;

            // �X�s�[�h�𑝂₷�i����ݒ肠��j
            speed = (speed <= MAX_SPEED)? speed : MAX_SPEED;

            // �i�s�������Z�b�g
            dir = transform.forward * z;  
        }
        else
        {
            // ��������
            speed *= 0.9f;
        }

        // �N���b�N�Ń��X�^�[�g
        //if(Input.GetMouseButtonDown(0))
        //{
        //    SceneManager.LoadScene(0); // �V�[�������X�^�[�g           
        //}

        // Bdash����
        bdash = (Input.GetKey(KeyCode.B)) ? 2 : 1;

        // �ړ��ʂ����ݒl�ɉ��Z
        transform.position += dir.normalized * speed * bdash * Time.deltaTime;

        // Z�L�[��������Ă���Ƃ��e�𔭎�
        timer += Time.deltaTime;
        if (timer >= 0.3f && Input.GetButton("Fire1"))
        {
            timer = 0;
            audioSource.Play();
            for (int i = -power; i < power + 1; i++)
            {
                // �e�̐����ʒu�̓v���[���[��0.5m��̈ʒu
                Vector3 pos = transform.position + new Vector3(0, 0.5f, 0);

                // �v���[���[�̉�]�p�x���擾���A15�x�����炵�������ɒe����]������
                Vector3 r = transform.rotation.eulerAngles + new Vector3(0, 15f * i, 0);
                Quaternion rot = Quaternion.Euler(r);

                // �ʒu�Ɖ�]�����Z�b�g���Đ���
                Instantiate(bulletPre, pos, rot);
            }
        }
        Jump();
        // �e�C�V�X�e��
        if (hakiFlg == false)
        {
            if (Input.GetKeyDown(KeyCode.X))
            {
                hakiFlg = true;
            }
        }
        else
        {
            spCollider.radius += hakiSpeed;
            hakiSpeed += hakiAccel;

            if (spCollider.radius > 50f)
            {
                hakiFlg = false;
                hakiSpeed = 3;
                spCollider.radius = 0.5f;
            }
        }

        // C�L�[��power�ύX
        if (Input.GetKeyDown(KeyCode.C))
        {
            power = (power + 1) % 13;
        }

        // ���x�\��
        float sokudo = speed * bdash;
        speedText.text = "���x " + sokudo.ToString("F2") + " m/s";
        // �V���b�g���x���\��
        shotLevelText.text = "�e���x���F" + power.ToString("D2");

        hakiText.text = "�e�C�t���O�F" + hakiFlg.ToString();
        
    }
    void Jump()
    {
        Ray ray = new Ray(transform.position, Vector3.down);
        Debug.DrawRay(ray.origin, ray.direction * Ray_distance, Color.red);
        if (Physics.Raycast(ray, Ray_distance, lmask))
        {
            Ground = true;
            Debug.Log("�n��");
        }
        else
        {
            Ground = false;
            Debug.Log("��");
        }
        Vector3 force = new Vector3(0, Jump_power, 0);
        if (Ground)
        {
            if (Input.GetButtonDown("Jump"))
            {
                Debug.Log("�W�����v");
                rigidbody.AddForce(force, ForceMode.Impulse);
            }
        }
    }
    void OnTriggerEnter(Collider c)
    {
        // �������Ă����I�u�W�F�N�g��Tag���uEnemy�v��������
        if (c.tag == "Enemy" && hakiFlg == false)
        {
            GameDirector.moveHp -= Random.Range(20, 200);
            GameDirector.moveHp = Mathf.Max(GameDirector.moveHp, 0);

            Vector3 pos = transform.position + new Vector3(0,1,0);
            Instantiate(firePre, pos, transform.rotation);
        }
    }
}
