//--------------------------------------------------------------------
// 科目：ゲームアルゴリズム1年
// 内容：TextMeshPro3Dを使ったポイント表示
// 日時：2023.07.07 Ken.D.Ohishi
//--------------------------------------------------------------------
using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;

public class PointController : MonoBehaviour
{
    float speed;            // 上昇スピード
    float alphaSpeed;       // フェードアウト速度

    TextMeshPro textMesh;   // 3DTextMeshPro（UIはTextMeshProUGUI）
    Color textColor;        // 色情報

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
        // 常にカメラの方を向く
        Vector3 dir = transform.position - Camera.main.transform.position;
        dir.y = 0f;
        transform.forward = dir.normalized;

        // 上に移動
        transform.position += Vector3.up * speed * Time.deltaTime;

        // 徐々に透明に
        textColor.a -= alphaSpeed;
        textMesh.color = textColor;
    }
}
