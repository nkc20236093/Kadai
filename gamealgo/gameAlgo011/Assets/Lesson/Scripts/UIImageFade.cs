//---------------------------------------------------------------------------------------
// ファイル：UIImageFade.cs
// 内容　　：UI-Image オブジェクトをフェードさせる（速度調節可）
//---------------------------------------------------------------------------------------
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class UIImageFade : MonoBehaviour
{
	const float START_SPEED = 2f;   // 通常速度
	const float SPEEDUP_TIME = 5f;  // スピードアップ時間

	Image img;                      // オブジェクト保存用
	float speed;					// フェード速度
	float time;                     // 時間計測用変数
	bool speedUpFlg;                // スピードアップフラグ

	void Start()
	{
		img = gameObject.GetComponent<Image>(); //　Imageコンポーネントを取得
		speed = START_SPEED;                    // スピードの初期値設定
		speedUpFlg = false;						// スピードアップフラグOFF
	}

	void Update()
	{
		//オブジェクトのAlpha値を更新
		img.color = GetAlphaColor(img.color);

		// エンターキーが押された後は点滅速度を早くする
		if(Input.GetKeyDown(KeyCode.Return))
        {
			speedUpFlg = true;
			speed *= 10f;
			time = 0f;
		}

		// エンターキーが押されてからSPEEDUP_TIME秒たったら点滅速度を戻す
		if (speedUpFlg && (time / speed) >= SPEEDUP_TIME )
        {
			speedUpFlg = false;
			speed = 5f;
			time = 0f;
		}
	}

	//Alpha値を更新してColorを返す
	Color GetAlphaColor(Color color)
	{
		time += Time.deltaTime * speed;
		// アルファ値を 0.0～1.0の範囲で循環させる
		color.a = Mathf.Sin(time) * 0.5f + 0.75f;
		return color;
	}

}