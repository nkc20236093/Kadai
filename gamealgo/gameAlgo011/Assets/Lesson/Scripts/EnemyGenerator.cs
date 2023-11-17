//--------------------------------------------------------------------
// 科目：ゲームアルゴリズム1年
// 内容：敵の生成
// 日時：2023.06.16 Ken.D.Ohishi
//--------------------------------------------------------------------
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyGenerator : MonoBehaviour
{
    public GameObject enemyPre; // 敵のプレハブを保存
    int enemyType;              // 敵のタイプ
    Vector3 pos;                // 出現位置
    Quaternion rot;             // 回転角度（Y軸回転）

    void Start()
    {
        // エネミータイプ
        enemyType = 1;

        // タイプ０の設定
        //float x = Random.Range(-49f, 49f);
        //pos = new Vector3(x, 0.5f, 50f);
        //rot.eulerAngles = new Vector3(0f, 180f, 0f);

        // タイプ１の設定
        float rad = Random.Range(0, 360);
        float x = 50f * Mathf.Cos(rad * Mathf.Deg2Rad);
        float z = 50f * Mathf.Sin(rad * Mathf.Deg2Rad);
        pos = new Vector3(x, 0.5f, z);
        rot.eulerAngles = new Vector3(0f, -(rad + 90f), 0f);

        // コルーチン：【EnemyCreate】を実行する
        StartCoroutine("EnemyCreate");
    }

    void Update()
    {
        // 敵の行動パターン変化
        if (Input.GetMouseButtonDown(1))
        {
            enemyType = (enemyType == 0) ? 1 : 0;
        }

        // 敵の行動パターン変化
        if (enemyType == 0)
        {
            float x = Random.Range(-49f, 49f);           // X座標を-49～49でランダムに
            pos = new Vector3(x, 0.5f, 50f);             // 出現位置を確定
            rot.eulerAngles = new Vector3(0f, 180f, 0f); // 手前に進むように180度回転
        }
        else if (enemyType == 1)
        {
            // XZ平面上の半径50mの円周上に敵をランダムで配置
            float rad = Random.Range(0, 360);               // 角度をランダムで決定
            float x = 50f * Mathf.Cos(rad * Mathf.Deg2Rad); // 出現するX座標の位置
            float z = 50f * Mathf.Sin(rad * Mathf.Deg2Rad); // 出現するZ座標の位置
            pos = new Vector3(x, 0.5f, z);                  // 出現位置を確定

            // 原点の方向を向くように回転させる
            rot.eulerAngles = new Vector3(0f, -(rad + 90f), 0f);
        }
        else
        {

        }

        // デバッグ用にクリックでも敵を生成
        if (Input.GetMouseButtonDown(0))
        {
            Instantiate(enemyPre, pos, rot);
        }

    }

    // ３秒毎に繰り返し実行されるコルーチン
    IEnumerator EnemyCreate()
    {
        while (true)
        {
            // オブジェクト生成処理
            Instantiate(enemyPre, pos, rot);

            // メソッドを一定時間中断
            yield return new WaitForSeconds(2f);
        }
    }
}
