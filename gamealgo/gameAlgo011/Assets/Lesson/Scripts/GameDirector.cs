//--------------------------------------------------------------------
// 科目：ゲームアルゴリズム1年
// 内容：制限時間処理
// 日時：2023.10.27 Ken.D.Ohishi
//--------------------------------------------------------------------
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GameDirector : MonoBehaviour
{
    // ゲームフラグ
    public static bool isPlaying;  // ゲーム中かどうか

    // 結果表示
    public Text resultLabel;       // Textコンポーネントを保存

    // 残り時間
    public Text TimeLabel;         // Textコンポーネントを保存
    const float LASTTIME = 31;     // 残り時間
    float lastTime;                // 残り時間計算用変数
    Color timeTextColor;           // 残り時間の色

    // スコア
    public Text scoreLabel;         // TEXTコンポーネントを保存
    public static int score;        // スコアを保存

    // 体力ゲージ
    public Text hpLabel;            // HP数値表示用
    public Image moveGauge;         // 裏ゲージオブジェクト（UI-Image）
    public Image hpGauge;           // 表ゲージ（UI-Image）
    public const int MAX_HP = 1000; // 定数
    public static int moveHp;       // ダメージ、回復量を即反映させる変数
    public string sceneName;        // 次のシーン
    int nowHp;                      // HPアニメーション用変数

    void Start()
    {
        isPlaying = true;           // ゲームフラグ 
        resultLabel.enabled = false;// 結果のラベルははじめ非表示

        score = 0;                  // スコア
        lastTime = LASTTIME;        // 残り時間
        timeTextColor = Color.red;  // 残り時間の色

        moveHp = MAX_HP;            // moveHpをMAXに
        nowHp = MAX_HP;     		// nowHpをMAXに
    }

    void Update()
    {
        // エンターキーでシーン切り替え
        if (Input.GetKeyDown(KeyCode.Return))
        {
            // フェード時間を設定してシーン遷移
            FadeManager.Instance.LoadScene(sceneName, 0.5f);
        }

        // プレイフラグがOFFになったらこの先の命令は実行しない
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
            // 残り時間計算
            lastTime -= Time.deltaTime;
            lastTime = Mathf.Max(lastTime, 0);

            // 残り時間が５秒以下で赤色で点滅
            if (lastTime < 6 && Time.frameCount % 10 == 0)
            {
                timeTextColor.a = (timeTextColor.a == 1) ? 0 : 1;
                TimeLabel.color = timeTextColor;
            }
        }
        TimeLabel.text = "残り時間：" + lastTime.ToString("F2");

        // 変数の値を表示に反映
        scoreLabel.text = "Score:" + score.ToString("D6");

        if (nowHp != moveHp)
        {
            if (nowHp > moveHp)
            {
                // ダメージ
                nowHp -= 5;
                if (nowHp < moveHp) nowHp = moveHp;
                hpGauge.fillAmount = (float)moveHp / MAX_HP;
                moveGauge.color = Color.red;
                moveGauge.fillAmount = (float)nowHp / MAX_HP;

                // HPが０で終了判定
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
                // 回復
                nowHp += 5;
                if (nowHp > moveHp) nowHp = moveHp;
                moveGauge.color = Color.green;
                moveGauge.fillAmount = (float)moveHp / MAX_HP;
                hpGauge.fillAmount = (float)nowHp / MAX_HP;
            }
        }
        hpLabel.text = "HP\n" + nowHp.ToString("D4");

        // 左クリックでダメージ（デバッグ用）
        if (Input.GetMouseButtonDown(0))
        {
            moveHp -= Random.Range(20, 200);
            moveHp = Mathf.Max(moveHp, 0);
        }
        // 右クリックで回復（デバッグ用）
        if (Input.GetMouseButtonDown(1))
        {
            moveHp += Random.Range(20, 200);
            moveHp = Mathf.Min(moveHp, MAX_HP);
        }
    }
}
