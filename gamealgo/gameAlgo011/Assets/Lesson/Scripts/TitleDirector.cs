//---------------------------------------------------------------------------------------
// �t�@�C���FTitleDirector.cs
// ���e�@�@�FEnter�L�[��GameScene��
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

	public string nextSceneName; // ���̃V�[������o�^

	void Start()
	{
		startFlg = false;
		pushTime = 0f;
		changeTime = 2f;
	}

	void Update()
	{
		// �G���^�[�L�[�������ꂽ��X�^�[�g�X�C�b�`ON
		if(Input.GetKeyDown(KeyCode.Return))
        {
			startFlg = true;
			audioSource.clip = clip;
			audioSource.Play();
        }

		// �X�^�[�g�X�C�b�`��ON�ɂȂ��Ă���T�b��������V�[���؂�ւ�
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