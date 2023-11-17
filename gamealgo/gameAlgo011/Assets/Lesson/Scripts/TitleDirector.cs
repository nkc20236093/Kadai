//---------------------------------------------------------------------------------------
// ファイル：TitleDirector.cs
// 内容　　：EnterキーでGameSceneへ
//---------------------------------------------------------------------------------------
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class TitleDirector : MonoBehaviour
{
	[SerializeField] AudioSource audioSource;
	[SerializeField] AudioClip clip;
	float pushTime;
	float changeTime;
	bool startFlg;

	public string nextSceneName; // 次のシーン名を登録

	void Start()
	{
		startFlg = false;
		pushTime = 0f;
		changeTime = 2f;
	}

	void Update()
	{
		// エンターキーが押されたらスタートスイッチON
		if(Input.GetKeyDown(KeyCode.Return))
        {
			startFlg = true;
			audioSource.clip = clip;
			audioSource.Play();
        }

		// スタートスイッチがONになってから５秒立ったらシーン切り替え
		if(startFlg)
        {
			pushTime += Time.deltaTime;
			if(pushTime > changeTime)
            {
				FadeManager.Instance.LoadScene(nextSceneName, 1f);
			}
        }
	}

}