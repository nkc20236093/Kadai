using UnityEngine;
using UnityEngine.UI;

public class UIManager : MonoBehaviour
{
    //�e���̕\�����s���e�L�X�g
    public Text bulletText;

    public Slider hpSlider;//HP�X���C�_�[�i�[


    public GameObject deathPanel;//���S�p�l��
    public Text deathText;//�f�X�e�L�X�g


    public GameObject scoreboard;//�X�R�A�{�[�hUI
    public PlayerInformation info;//�v���C���[���Z�b�g�X�N���v�g


    public GameObject endPanel;//�I���p�l��


    /// <summary>
    /// �������̏e�̒e�����e�L�X�g�ɔ��f
    /// </summary>
    /// <param name="ammoClip"></param>
    /// <param name="ammunition"></param>
    public void SettingBulletsText(int ammoClip, int ammunition)
    {
        //�e�L�X�g�ɑ������̏e�́@�}�K�W�����e��/�����e���@��\��
        bulletText.text = ammoClip + "/" + ammunition;
    }


    //HP�̍X�V
    public void UpdateHP(int maxhp, float currentHp)
    {
        hpSlider.maxValue = maxhp;
        hpSlider.value = currentHp;

    }


    //�f�XUI�X�V
    public void UpdateDeathUI(string name)
    {
        deathPanel.SetActive(true);//�\��
        deathText.text = name + "�ɂ��ꂽ";//�e�L�X�g�X�V

        Invoke("CloseDeathUI", 5f);//5�b��ɕ���
    }

    //�f�XUI��\���֐�
    private void CloseDeathUI()
    {
        deathPanel.SetActive(false);
    }


    /// <summary>
    /// �L���f�X�\�̕\���ؑ�
    /// </summary>
    public void ChangeScoreUI()
    {
        //�\�����Ă������\���ɁA��\���Ȃ�\��������
        scoreboard.SetActive(!scoreboard.activeInHierarchy);
    }


    //�Q�[���I���p�l���\��
    public void OpenEndPanel()
    {
        endPanel.SetActive(true);
    }

}