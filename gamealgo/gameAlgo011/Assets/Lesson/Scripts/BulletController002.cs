//--------------------------------------------------------------------
// �ȖځF�Q�[���A���S���Y��1�N
// ���e�F�����Ă�������ɒe���o��
// �����F2023.06.02 Ken.D.Ohishi
//--------------------------------------------------------------------
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BulletController002 : MonoBehaviour
{
    // public Transform player;
    float speed = 12;
    GameObject Exp;
    void Start()
    {
        Exp = (GameObject)Resources.Load("Exp");
        // �q�G�����L�[����Player�I�u�W�F�N�g���������ĕۑ�
        // player = GameObject.Find("Player").transform;

        // �e�̏����ʒu���v���[���[�̈ʒu�ɂ���
        // Vector3 offset = new Vector3(0, 0.5f, 0);
        // transform.position = player.position + offset;

        // �e�̌������v���[���[�̌����ɍ��킹��
        // transform.forward = player.forward;

    }

    void Update()
    {
        // �ړ�
        transform.position += Vector3.down * speed * Time.deltaTime;
        if (transform.position.y == 0)
        {
            Instantiate(Exp, transform.position, Quaternion.identity);
            Destroy(gameObject);
        }
    }
}
