using UnityEngine;

public class Gun : MonoBehaviour
{
    [Tooltip("射撃間隔")]
    public float shootInterval = .1f;
    [Tooltip("威力")]
    public int shotDamage;
    [Tooltip("覗き込み時のズーム")]
    public float adsZoom;
    [Tooltip("覗き込み時の速度")]
    public float adsSpeed;

    public GameObject bulletImpact;//弾痕オブジェクト


    public AudioSource shoutSound;//サウンド

    //銃声を鳴らす
    public void SoundGunShot()
    {
        shoutSound.Play();//一度だけ鳴らす
    }

    //サブマシンガンのループON
    public void LoopON_SubmachineGun()
    {
        //なっていない時
        if (!shoutSound.isPlaying)
        {
            shoutSound.loop = true;//ループON
            shoutSound.Play();//音を鳴らし始める
        }

    }

    //サブマシンガンのループOFF
    public void LoopOFF_SubmachineGun()
    {
        shoutSound.loop = false;//ループOFF
        shoutSound.Stop();//音を止める
    }
}