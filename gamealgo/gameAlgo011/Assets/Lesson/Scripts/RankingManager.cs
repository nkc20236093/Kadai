//------------------------------------------------------------------------------
// ゲームアルゴリズム１年
// RankingManager.cs
//------------------------------------------------------------------------------
using UnityEngine;
using UnityEngine.UI;
using System.Collections;
using UnityEngine.SceneManagement;

public class RankingManager : MonoBehaviour
{
    const string RANKING_PREF_KEY = "ranking";      // セーブキー
    const int RANKING_NUM = 5;                      // セーブデータ数
    int[] ranking = new int[RANKING_NUM];           // ランキングデータ保存

    // 使いまわしするベースのテキストオブジェクト
    public GameObject baseText;

    // ランキング表示用ゲームオブジェクト
    GameObject[] rankLabel = new GameObject[RANKING_NUM];

    // Textオブジェクトを配置するキャンバスを保存
    GameObject canvas;

    void Start()
    {
        loadRanking();                      // セーブデータをロード
        saveRanking(GameDirector.score);    // スコアをランキングに保存

        // 見出し
        // ベースTextをコピー
        GameObject Ranking = Instantiate(baseText);

        // Canvasの子オブジェクトにする
        canvas = GameObject.Find("Canvas");
        Ranking.transform.SetParent(canvas.transform);

        // ランキングの見出し文字「TOP 5」
        Text rankingTextComp = Ranking.GetComponent<Text>();
        rankingTextComp.text = "TOP 5";

        // 表示位置(アンカー（画面の中心）からの位置)
        RectTransform rankingRectTransComp = Ranking.GetComponent<RectTransform>();
        rankingRectTransComp.anchoredPosition = new Vector2(0f, 120f);

        // ランキング表示
        float offset   = 72.0f;     // Y座標基準値
        float Interval = -48.0f;    // 行間隔
        for (int i = 0; i < RANKING_NUM; i++)
        {
            // ベースのテキストオブジェクトを複製して生成
            rankLabel[i] = Instantiate(baseText);

            // 親オブジェクトをCanvasにする
            rankLabel[i].transform.SetParent(canvas.transform);

            // 表示位置(アンカー（画面の中心）からの位置)
            Vector2       pos  = new Vector2(0, offset + Interval * i);
            RectTransform rectTransComp = rankLabel[i].GetComponent<RectTransform>();
            rectTransComp.anchoredPosition = pos;

            // 表示テキスト
            Text textComp = rankLabel[i].GetComponent<Text>();
            textComp.text = string.Format("{0}.  {1:00000}", i + 1, ranking[i]);
        }
    }

    void Update()
    {
        // セーブデータ消去用
        if (Input.GetKey(KeyCode.Space))
        {
            PlayerPrefs.DeleteKey(RANKING_PREF_KEY);
        }
        if (Input.GetKey(KeyCode.Return))
        {
            SceneManager.LoadScene("TitleScene");
        }
    }

    //ランキングを PlayerPrefs から取得して ranking に格納
    void loadRanking()
    {
        // セーブデータをロードし、_rankingへ保存
        // セーブデータがない場合はdefaultValue = ""が_rankingへ保存される
        string _ranking = PlayerPrefs.GetString(RANKING_PREF_KEY);

        // 文字列を「,」で分割して、整数型にし、ranking配列に格納
        if (_ranking.Length > 0)
        {
            string[] _score = _ranking.Split(',');

            for (int i = 0; i < RANKING_NUM; i++)
            {
                ranking[i] = int.Parse(_score[i]);
                // Debug.Log(string.Format("{0}", ranking[i]));
            }
        }
        else
        {
            // セーブデータがない場合、すべてのスコアに０を代入
            for (int i = 0; i < RANKING_NUM; i++)
            {
                ranking[i] = 0;
            }
        }
    }

    // 新たにスコアを保存する
    void saveRanking(int new_score)
    {
        if (ranking[0] != 0)
        {
            // セーブデータがあるときは順次比較して、小さいほうを次の配列へ
            for (int i = 0; i < RANKING_NUM; i++)
            {
                if (ranking[i] < new_score)
                {
                    int _tmp   = ranking[i];
                    ranking[i] = new_score;
                    new_score  = _tmp;
                }
            }
        }
        else
        {
            // セーブデータがなかったときは、先頭に代入
            ranking[0] = new_score;
        }

        // 「整数(int)」を「文字列(string)」に変換
        string[] str = new string[RANKING_NUM];
        for (int i = 0; i < RANKING_NUM; i++)
        {
            str[i] = ranking[i].ToString();
        }

        // 変換した文字列をカンマ区切りで連結し、１つの文字列へ
        string ranking_string = string.Join(",", str);
        // Debug.Log(string.Format("savedata : {0}", ranking_string));

        // 一つにした文字列をセーブデーターとして保存
        PlayerPrefs.SetString(RANKING_PREF_KEY, ranking_string);
    }
}