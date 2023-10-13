using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;
using UnityEngine.AI;
using static Unity.Collections.Unicode;

public class test_20_sub : MonoBehaviour
{
    [Serialize] public int m = 1;

    // ‰Û‘è20
    // 1‚©‚ç12‚Ì’l‚ðŽ‚Â—ñ‹“Œ^AMonth‚ðì¬
    // 1...January, 2...February..‚Æ‚¢‚Á‚½‚æ‚¤‚ÈŒ^‚ðì‚é
    enum Month
    {
        none,
        January,
        February,
        March,
        April,
        May,
        June,
        July,
        August,
        September,
        October,
        November,
        December,
    };
    Month x = Month.May;

    // intŒ^‚Ì•Ï”x‚ðì¬‚µAŽ©•ª‚Ì’a¶ŒŽ‚ðMonthŒ^‚Ì—ñ‹“Žq‚Å
    // ƒLƒƒƒXƒg‚ð—p‚¢‚Ä‘ã“ü
    // Debug.log‚Åx‚ð•\Ž¦
    // •\Ž¦—áj’a¶ŒŽ‚Í10

    // ®”Œ^‚Ì•Ï”m‚ÉD‚«‚È®”‚ð“ü—Í‚µA
    // ‚»‚ÌŒŽ‚ðMonthŒ^‚Ì—ñ‹“Žq‚É•ÏŠ·‚µ‚Ä•\Ž¦‚·‚é
    // ‚È‚¨A‚O‚â‚X‚X‚Æ‚¢‚Á‚½’l‚ª“ü—Í‚³‚ê‚½ê‡A
    // –³Œø‚È’l‚Å‚·‚Æ•\Ž¦‚·‚é
    // •\Ž¦—áj
    // m‚ª0‚Ìê‡„–³Œø‚È’l‚Å‚·
    // m‚ª2‚Ìê‡„February
    string[] MonthTable =
    {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December",

    };
    // Start is called before the first frame update
    void Start()
    {
        Debug.Log($"’a¶“ú‚Í{(int)x}ŒŽ");


        if (m > 0 && m <= 12)
        {
            Month month = (Month)(int)m;
            Debug.Log(month);
        }
        else
        {
            Debug.Log($"{m}‚Í–³Œø‚È’l‚Å‚·");
        }
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
