using UnityEngine;

public class Gun : MonoBehaviour
{
    [Tooltip("�ˌ��Ԋu")]
    public float shootInterval = .1f;
    [Tooltip("�З�")]
    public int shotDamage;
    [Tooltip("�`�����ݎ��̃Y�[��")]
    public float adsZoom;
    [Tooltip("�`�����ݎ��̑��x")]
    public float adsSpeed;

    public GameObject bulletImpact;//�e���I�u�W�F�N�g


    public AudioSource shoutSound;//�T�E���h

    //�e����炷
    public void SoundGunShot()
    {
        shoutSound.Play();//��x�����炷
    }

    //�T�u�}�V���K���̃��[�vON
    public void LoopON_SubmachineGun()
    {
        //�Ȃ��Ă��Ȃ���
        if (!shoutSound.isPlaying)
        {
            shoutSound.loop = true;//���[�vON
            shoutSound.Play();//����炵�n�߂�
        }

    }

    //�T�u�}�V���K���̃��[�vOFF
    public void LoopOFF_SubmachineGun()
    {
        shoutSound.loop = false;//���[�vOFF
        shoutSound.Stop();//�����~�߂�
    }
}