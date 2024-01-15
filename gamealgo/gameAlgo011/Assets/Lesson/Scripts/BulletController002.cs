//--------------------------------------------------------------------
// 科目：ゲームアルゴリズム1年
// 内容：向いている方向に弾を出す
// 日時：2023.06.02 Ken.D.Ohishi
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
        // ヒエラルキーからPlayerオブジェクトを検索して保存
        // player = GameObject.Find("Player").transform;

        // 弾の初期位置をプレーヤーの位置にする
        // Vector3 offset = new Vector3(0, 0.5f, 0);
        // transform.position = player.position + offset;

        // 弾の向きをプレーヤーの向きに合わせる
        // transform.forward = player.forward;

    }

    void Update()
    {
        // 移動
        transform.position += Vector3.down * speed * Time.deltaTime;
        if (transform.position.y == 0)
        {
            Instantiate(Exp, transform.position, Quaternion.identity);
            Destroy(gameObject);
        }
    }
}
