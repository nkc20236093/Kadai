using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;

public class test3_sub : MonoBehaviour
{
    //—ûK–â‘è1
    //•Ï”x‚É10.5A•Ï”y‚É3.14
    //ŒvZŒ‹‰Ê‚ğ“ü‚ê‚é•Ï”sum‚ğì¬
    //x + y = ZZ(ŒvZ‚µ‚½sum‚Ì’l)
    //x - y = ZZ(ŒvZ‚µ‚½sum‚Ì’l)
    //x * y = ZZ(ŒvZ‚µ‚½sum‚Ì’l)
    //x / y = ZZ(ŒvZ‚µ‚½sum‚Ì’l)
    //x % y = ZZ(ŒvZ‚µ‚½sum‚Ì’l)
    //‚Æ‚È‚é‚æ‚¤ADebug.log‚ğg‚Á‚Ä•\¦‚·‚é

    //int + float‚ÌŒvZ‚ÍŸè‚Éfloat‚É‚È‚é
    //‚±‚Ì‚æ‚¤‚ÉŸè‚ÉŒ^‚ª•ÏX‚³‚ê‚é‚±‚Æ‚ğ
    //ˆÃ–Ù‚ÌŒ^•ÏŠ·‚Æ‚¢‚¤

    float x = 10.5f;
    float y = 3.14f;
    float sum;
    // Start is called before the first frame update
    void Start()
    {
        sum = x + y;
        Debug.Log("x + y ="  + sum);

        sum = x - y; 
        Debug.Log("x - y =" + sum);

        sum = x * y;
        Debug.Log("x * y =" + sum);
        sum = x / y;
        Debug.Log("x / y =" + sum);

        sum = x % y;
        Debug.Log("x % y =" + sum);
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
