using Photon.Pun;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Photon.Realtime;
using UnityEngine.UI;

public class Title : MonoBehaviourPunCallbacks
{
    private bool SV;
    [SerializeField] Image check;
    [SerializeField] Sprite[] sprites;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if (!GameManeger.instance.GameEnd)
        {
            Change();
        }
    }
    [PunRPC]
    void Change()
    {
        if (Input.GetKeyDown(KeyCode.Delete))
        {
            SV = !SV;
        }
        if (SV)
        {
            check.sprite = sprites[1];
            GameManeger.instance.OnSV = true;
        }
        else
        {
            check.sprite = sprites[0];
            GameManeger.instance.OnSV = false;
        }
    }
}
