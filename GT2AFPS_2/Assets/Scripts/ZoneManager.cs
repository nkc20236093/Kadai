using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Photon.Pun;

public class ZoneManager : MonoBehaviourPunCallbacks
{
    public int ZoneSequence;
    public float[] ZoneDamage = new float[8]
    {
        1.0f,1.5f,2.0f,2.5f,3.0f,3.5f,4.0f,5.0f
    };
    GameObject Zone;
    float timer = 0;
    // Start is called before the first frame update
    void Start()
    {
        Zone = gameObject;
    }

    // Update is called once per frame
    void Update()
    {
        Sequence();
    }
    void Sequence()
    {
        ZoneSequence = Mathf.Clamp(ZoneSequence, 0, ZoneDamage.Length);
        timer += Time.deltaTime;
        if (timer > 8)
        {
            timer = 0;
            ZoneSequence++;
        }
    }
    private void OnTriggerExit(Collider other)
    {
        //if (other.gameObject.CompareTag("Player"))
        //{
        //    PlayerController controller = other.gameObject.GetComponent<PlayerController>();
        //    other.gameObject.GetPhotonView().RPC(controller.Hit,RpcTarget.All,);
        //}
    }
}
