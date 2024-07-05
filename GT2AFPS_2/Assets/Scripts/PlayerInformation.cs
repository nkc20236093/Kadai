using UnityEngine;
using UnityEngine.UI;

public class PlayerInformation : MonoBehaviour
{
    public Text playerNameText, kilesText, deathText;//名前とキルデス数を表示するテキスト


    /// <summary>
    /// 表に名前やキルデス数を表示する
    /// </summary>
    /// <param name="name"></param>
    /// <param name="kill"></param>
    /// <param name="death"></param>
    public void SetPlayerDetailes(string name, int kill, int death)
    {
        playerNameText.text = name;
        kilesText.text = kill.ToString();
        deathText.text = death.ToString();
    }
}