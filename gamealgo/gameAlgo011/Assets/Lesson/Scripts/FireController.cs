using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FireController : MonoBehaviour
{
    void Start()
    {
        // �v���[���[�̎p�������擾
        Transform player = GameObject.Find("Player").transform;

        // �v���[���[��e�I�u�W�F�N�g�ɂ���
        transform.parent = player;
    }

}
