//--------------------------------------------------------------------
// 科目：ゲームアルゴリズム1年
// 内容：敵の制御
// 日時：2023.06.29 Ken.D.Ohishi
//--------------------------------------------------------------------
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyController003 : MonoBehaviour
{
    public GameObject point;   // 得点表示オブジェクト    
    public GameObject expPre;  // 爆発のプレハブを保存
    Renderer render;    // レンダラーコンポーネント保存
    Vector3 dir;        // 移動方向
    float speed = 5;    // 移動速度

    void Start()
    {
        // 登場位置
        //float x = Random.Range(-49, 49);
        //Vector3 pos = new Vector3(x, 0.5f, 50);
        //transform.position = pos;

        // 移動方向をセット
        // transform.Rotate(Vector3.up, 180);
        dir = transform.forward;

        // 色を赤色系ランダム
        render = GetComponent<Renderer>();
        render.material.color = new Color(Random.value, 0, 0);

        // 寿命
        Destroy(gameObject, 20);
    }

    void Update()
    {
        // 向いている方向に移動
        transform.position += dir * speed * Time.deltaTime;
    }

    void OnTriggerEnter(Collider c)
    {
        // 当たってきたオブジェクトのTagが「bullet」だったら
        if (c.tag == "bullet")
        {
            // 得点を加算
            GameDirector.score += 100;

            // 得点表示
            Vector3 pos = transform.position + new Vector3(0f, 0.5f, 0f);
            Instantiate(point, pos, transform.rotation);

            // 体力ゲージを回復
            GameDirector.moveHp += Random.Range(20, 200);
            GameDirector.moveHp = Mathf.Min(GameDirector.moveHp, GameDirector.MAX_HP);

            // 爆発を生成
            Instantiate(expPre,transform.position, transform.rotation);

            Destroy(c.gameObject);  // 当たってきたオブジェクトを削除
            Destroy(gameObject);    // 自分自身を削除
        }

        // 当たってきたオブジェクトのTagが「Player」だったら
        if (c.tag == "Player")
        {
            // 爆発を生成
            Instantiate(expPre, transform.position, transform.rotation);

            Destroy(gameObject);    // 自分自身を削除
        }

    }

}
