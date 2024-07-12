using UnityEngine;
using UnityEngine.UI;

public class UIManager : MonoBehaviour
{
    //弾数の表示を行うテキスト
    public Text bulletText;

    public Slider hpSlider;//HPスライダー格納


    public GameObject deathPanel;//死亡パネル
    public Text deathText;//デステキスト


    public GameObject scoreboard;//スコアボードUI
    public PlayerInformation info;//プレイヤー情報セットスクリプト


    public GameObject endPanel;//終了パネル


    /// <summary>
    /// 装備中の銃の弾数をテキストに反映
    /// </summary>
    /// <param name="ammoClip"></param>
    /// <param name="ammunition"></param>
    public void SettingBulletsText(int ammoClip, int ammunition)
    {
        //テキストに装備中の銃の　マガジン内弾数/所持弾数　を表示
        bulletText.text = ammoClip + "/" + ammunition;
    }


    //HPの更新
    public void UpdateHP(int maxhp, float currentHp)
    {
        hpSlider.maxValue = maxhp;
        hpSlider.value = currentHp;

    }


    //デスUI更新
    public void UpdateDeathUI(string name)
    {
        deathPanel.SetActive(true);//表示
        deathText.text = name + "にやられた";//テキスト更新

        Invoke("CloseDeathUI", 5f);//5秒後に閉じる
    }

    //デスUI非表示関数
    private void CloseDeathUI()
    {
        deathPanel.SetActive(false);
    }


    /// <summary>
    /// キルデス表の表示切替
    /// </summary>
    public void ChangeScoreUI()
    {
        //表示していたら非表示に、非表示なら表示させる
        scoreboard.SetActive(!scoreboard.activeInHierarchy);
    }


    //ゲーム終了パネル表示
    public void OpenEndPanel()
    {
        endPanel.SetActive(true);
    }

}