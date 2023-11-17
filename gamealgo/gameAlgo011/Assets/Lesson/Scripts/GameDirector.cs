//--------------------------------------------------------------------
// �ȖځF�Q�[���A���S���Y��1�N
// ���e�F�������ԏ���
// �����F2023.10.27 Ken.D.Ohishi
//--------------------------------------------------------------------
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GameDirector : MonoBehaviour
{
    // �Q�[���t���O
    public static bool isPlaying;  // �Q�[�������ǂ���

    // ���ʕ\��
    public Text resultLabel;       // Text�R���|�[�l���g��ۑ�

    // �c�莞��
    public Text TimeLabel;         // Text�R���|�[�l���g��ۑ�
    const float LASTTIME = 31;     // �c�莞��
    float lastTime;                // �c�莞�Ԍv�Z�p�ϐ�
    Color timeTextColor;           // �c�莞�Ԃ̐F

    // �X�R�A
    public Text scoreLabel;         // TEXT�R���|�[�l���g��ۑ�
    public static int score;        // �X�R�A��ۑ�

    // �̗̓Q�[�W
    public Text hpLabel;            // HP���l�\���p
    public Image moveGauge;         // ���Q�[�W�I�u�W�F�N�g�iUI-Image�j
    public Image hpGauge;           // �\�Q�[�W�iUI-Image�j
    public const int MAX_HP = 1000; // �萔
    public static int moveHp;       // �_���[�W�A�񕜗ʂ𑦔��f������ϐ�
    public string sceneName;        // ���̃V�[��
    int nowHp;                      // HP�A�j���[�V�����p�ϐ�

    void Start()
    {
        isPlaying = true;           // �Q�[���t���O 
        resultLabel.enabled = false;// ���ʂ̃��x���͂͂��ߔ�\��

        score = 0;                  // �X�R�A
        lastTime = LASTTIME;        // �c�莞��
        timeTextColor = Color.red;  // �c�莞�Ԃ̐F

        moveHp = MAX_HP;            // moveHp��MAX��
        nowHp = MAX_HP;     		// nowHp��MAX��
    }

    void Update()
    {
        // �G���^�[�L�[�ŃV�[���؂�ւ�
        if (Input.GetKeyDown(KeyCode.Return))
        {
            // �t�F�[�h���Ԃ�ݒ肵�ăV�[���J��
            FadeManager.Instance.LoadScene(sceneName, 0.5f);
        }

        // �v���C�t���O��OFF�ɂȂ����炱�̐�̖��߂͎��s���Ȃ�
        if (isPlaying == false) return;

        if (lastTime <= 0)
        {
            isPlaying = false;
            TimeLabel.color = Color.white;
            resultLabel.enabled = true;
            resultLabel.text = "TIME UP!!";
        }
        else
        {
            // �c�莞�Ԍv�Z
            lastTime -= Time.deltaTime;
            lastTime = Mathf.Max(lastTime, 0);

            // �c�莞�Ԃ��T�b�ȉ��ŐԐF�œ_��
            if (lastTime < 6 && Time.frameCount % 10 == 0)
            {
                timeTextColor.a = (timeTextColor.a == 1) ? 0 : 1;
                TimeLabel.color = timeTextColor;
            }
        }
        TimeLabel.text = "�c�莞�ԁF" + lastTime.ToString("F2");

        // �ϐ��̒l��\���ɔ��f
        scoreLabel.text = "Score:" + score.ToString("D6");

        if (nowHp != moveHp)
        {
            if (nowHp > moveHp)
            {
                // �_���[�W
                nowHp -= 5;
                if (nowHp < moveHp) nowHp = moveHp;
                hpGauge.fillAmount = (float)moveHp / MAX_HP;
                moveGauge.color = Color.red;
                moveGauge.fillAmount = (float)nowHp / MAX_HP;

                // HP���O�ŏI������
                if (nowHp <= 0)
                {
                    isPlaying = false;
                    TimeLabel.color = Color.white;
                    resultLabel.enabled = true;
                    resultLabel.text = "GAME OVER !!";
                }
            }
            else
            {
                // ��
                nowHp += 5;
                if (nowHp > moveHp) nowHp = moveHp;
                moveGauge.color = Color.green;
                moveGauge.fillAmount = (float)moveHp / MAX_HP;
                hpGauge.fillAmount = (float)nowHp / MAX_HP;
            }
        }
        hpLabel.text = "HP\n" + nowHp.ToString("D4");

        // ���N���b�N�Ń_���[�W�i�f�o�b�O�p�j
        if (Input.GetMouseButtonDown(0))
        {
            moveHp -= Random.Range(20, 200);
            moveHp = Mathf.Max(moveHp, 0);
        }
        // �E�N���b�N�ŉ񕜁i�f�o�b�O�p�j
        if (Input.GetMouseButtonDown(1))
        {
            moveHp += Random.Range(20, 200);
            moveHp = Mathf.Min(moveHp, MAX_HP);
        }
    }
}
