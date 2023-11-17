//--------------------------------------------------------------------
// �ȖځF�Q�[���A���S���Y��1�N
// ���e�F�G�̐���
// �����F2023.06.29 Ken.D.Ohishi
//--------------------------------------------------------------------
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyController003 : MonoBehaviour
{
    public GameObject point;   // ���_�\���I�u�W�F�N�g    
    public GameObject expPre;  // �����̃v���n�u��ۑ�
    Renderer render;    // �����_���[�R���|�[�l���g�ۑ�
    Vector3 dir;        // �ړ�����
    float speed = 5;    // �ړ����x

    void Start()
    {
        // �o��ʒu
        //float x = Random.Range(-49, 49);
        //Vector3 pos = new Vector3(x, 0.5f, 50);
        //transform.position = pos;

        // �ړ��������Z�b�g
        // transform.Rotate(Vector3.up, 180);
        dir = transform.forward;

        // �F��ԐF�n�����_��
        render = GetComponent<Renderer>();
        render.material.color = new Color(Random.value, 0, 0);

        // ����
        Destroy(gameObject, 20);
    }

    void Update()
    {
        // �����Ă�������Ɉړ�
        transform.position += dir * speed * Time.deltaTime;
    }

    void OnTriggerEnter(Collider c)
    {
        // �������Ă����I�u�W�F�N�g��Tag���ubullet�v��������
        if (c.tag == "bullet")
        {
            // ���_�����Z
            GameDirector.score += 100;

            // ���_�\��
            Vector3 pos = transform.position + new Vector3(0f, 0.5f, 0f);
            Instantiate(point, pos, transform.rotation);

            // �̗̓Q�[�W����
            GameDirector.moveHp += Random.Range(20, 200);
            GameDirector.moveHp = Mathf.Min(GameDirector.moveHp, GameDirector.MAX_HP);

            // �����𐶐�
            Instantiate(expPre,transform.position, transform.rotation);

            Destroy(c.gameObject);  // �������Ă����I�u�W�F�N�g���폜
            Destroy(gameObject);    // �������g���폜
        }

        // �������Ă����I�u�W�F�N�g��Tag���uPlayer�v��������
        if (c.tag == "Player")
        {
            // �����𐶐�
            Instantiate(expPre, transform.position, transform.rotation);

            Destroy(gameObject);    // �������g���폜
        }

    }

}
