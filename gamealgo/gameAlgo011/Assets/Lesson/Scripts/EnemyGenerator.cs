//--------------------------------------------------------------------
// �ȖځF�Q�[���A���S���Y��1�N
// ���e�F�G�̐���
// �����F2023.06.16 Ken.D.Ohishi
//--------------------------------------------------------------------
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyGenerator : MonoBehaviour
{
    public GameObject enemyPre; // �G�̃v���n�u��ۑ�
    int enemyType;              // �G�̃^�C�v
    Vector3 pos;                // �o���ʒu
    Quaternion rot;             // ��]�p�x�iY����]�j

    void Start()
    {
        // �G�l�~�[�^�C�v
        enemyType = 1;

        // �^�C�v�O�̐ݒ�
        //float x = Random.Range(-49f, 49f);
        //pos = new Vector3(x, 0.5f, 50f);
        //rot.eulerAngles = new Vector3(0f, 180f, 0f);

        // �^�C�v�P�̐ݒ�
        float rad = Random.Range(0, 360);
        float x = 50f * Mathf.Cos(rad * Mathf.Deg2Rad);
        float z = 50f * Mathf.Sin(rad * Mathf.Deg2Rad);
        pos = new Vector3(x, 0.5f, z);
        rot.eulerAngles = new Vector3(0f, -(rad + 90f), 0f);

        // �R���[�`���F�yEnemyCreate�z�����s����
        StartCoroutine("EnemyCreate");
    }

    void Update()
    {
        // �G�̍s���p�^�[���ω�
        if (Input.GetMouseButtonDown(1))
        {
            enemyType = (enemyType == 0) ? 1 : 0;
        }

        // �G�̍s���p�^�[���ω�
        if (enemyType == 0)
        {
            float x = Random.Range(-49f, 49f);           // X���W��-49�`49�Ń����_����
            pos = new Vector3(x, 0.5f, 50f);             // �o���ʒu���m��
            rot.eulerAngles = new Vector3(0f, 180f, 0f); // ��O�ɐi�ނ悤��180�x��]
        }
        else if (enemyType == 1)
        {
            // XZ���ʏ�̔��a50m�̉~����ɓG�������_���Ŕz�u
            float rad = Random.Range(0, 360);               // �p�x�������_���Ō���
            float x = 50f * Mathf.Cos(rad * Mathf.Deg2Rad); // �o������X���W�̈ʒu
            float z = 50f * Mathf.Sin(rad * Mathf.Deg2Rad); // �o������Z���W�̈ʒu
            pos = new Vector3(x, 0.5f, z);                  // �o���ʒu���m��

            // ���_�̕����������悤�ɉ�]������
            rot.eulerAngles = new Vector3(0f, -(rad + 90f), 0f);
        }
        else
        {

        }

        // �f�o�b�O�p�ɃN���b�N�ł��G�𐶐�
        if (Input.GetMouseButtonDown(0))
        {
            Instantiate(enemyPre, pos, rot);
        }

    }

    // �R�b���ɌJ��Ԃ����s�����R���[�`��
    IEnumerator EnemyCreate()
    {
        while (true)
        {
            // �I�u�W�F�N�g��������
            Instantiate(enemyPre, pos, rot);

            // ���\�b�h����莞�Ԓ��f
            yield return new WaitForSeconds(2f);
        }
    }
}
