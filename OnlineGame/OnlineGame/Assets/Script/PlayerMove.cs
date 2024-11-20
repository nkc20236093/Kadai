using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Photon.Pun;

public class PlayerMove : MonoBehaviourPunCallbacks
{
    void Update()
    {
        //�����̃I�u�W�F�N�g�����ړ�����
        if (photonView.IsMine)
        {
            float x = Input.GetAxis("Horizontal");
            float y = Input.GetAxis("Vertical");
            transform.Translate(new Vector3(x, y, 0) * Time.deltaTime * 10);
        }
    }
}
