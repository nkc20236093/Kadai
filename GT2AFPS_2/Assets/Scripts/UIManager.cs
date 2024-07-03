using UnityEngine;
using UnityEngine.UI;

public class UIManager : MonoBehaviour
{
    //弾数の表示を行うテキスト
    public Text bulletText;

    public Slider hpSlider;//HPスライダー格納


    public GameObject deathPanel;//死亡パネル
    public Text deathText;//デステキスト


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
    public void UpdateHP(int maxhp, int currentHp)
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

}