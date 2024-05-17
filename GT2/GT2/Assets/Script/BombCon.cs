using Photon.Pun;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BombCon : MonoBehaviourPunCallbacks
{
    const float MaxTime = 2.5f;
    float Timer;
    // Start is called before the first frame update
    void Start()
    {
        Timer = MaxTime;
    }
    // Update is called once per frame
    void Update()
    {
        Timer -= Time.deltaTime;
        if (Timer < 0)
        {
            StartCoroutine(nameof(Exp));
        }
    }
    IEnumerator Exp()
    {
        ParticleSystem particleSystem = GetComponentInChildren<ParticleSystem>();
        particleSystem.Play();
        AudioSource audioSource = GetComponentInChildren<AudioSource>();
        audioSource.Play();
        yield return new WaitForSeconds(0.5f);
        PhotonNetwork.Destroy(gameObject);
    }
}
