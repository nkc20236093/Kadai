//--------------------------------------------------------------------
// �ȖځF�Q�[���A���S���Y��1�N
// ���e�FTextMeshPro3D���g�����|�C���g�\��
// �����F2023.07.07 Ken.D.Ohishi
//--------------------------------------------------------------------
using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;

public class PointController : MonoBehaviour
{
    float speed;            // �㏸�X�s�[�h
    float alphaSpeed;       // �t�F�[�h�A�E�g���x

    TextMeshPro textMesh;   // 3DTextMeshPro�iUI��TextMeshProUGUI�j
    Color textColor;        // �F���

    void Start()
    {
        speed = 0.7f;
        alphaSpeed = speed * 0.02f;

        textMesh = GetComponent<TextMeshPro>();
        textColor = textMesh.color;

        Destroy(gameObject, 2f);
    }

    void Update()
    {
        // ��ɃJ�����̕�������
        Vector3 dir = transform.position - Camera.main.transform.position;
        dir.y = 0f;
        transform.forward = dir.normalized;

        // ��Ɉړ�
        transform.position += Vector3.up * speed * Time.deltaTime;

        // ���X�ɓ�����
        textColor.a -= alphaSpeed;
        textMesh.color = textColor;
    }
}
