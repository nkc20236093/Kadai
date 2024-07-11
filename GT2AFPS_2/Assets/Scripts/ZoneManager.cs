using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Photon.Pun;

public class ZoneManager : MonoBehaviourPunCallbacks
{
    GameObject Zone;
    // Start is called before the first frame update
    void Start()
    {
        Zone = gameObject;
    }

    // Update is called once per frame
    void Update()
    {
        
    }
    private void OnTriggerExit(Collider other)
    {
        if (other.gameObject.CompareTag("Player"))
        {
            //GetComponent<PlayerController>().Hit(0,"安置外ダメージ")
        }
    }
    [PunRPC]
    void ZoneDamage()
    {

    }
}
