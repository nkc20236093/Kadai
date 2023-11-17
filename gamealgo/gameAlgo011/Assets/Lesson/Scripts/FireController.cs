using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FireController : MonoBehaviour
{
    void Start()
    {
        // プレーヤーの姿勢情報を取得
        Transform player = GameObject.Find("Player").transform;

        // プレーヤーを親オブジェクトにする
        transform.parent = player;
    }

}
