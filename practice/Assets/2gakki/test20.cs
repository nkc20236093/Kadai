using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class test20 : MonoBehaviour
{
    //�萔�i�ύX�ł��Ȃ��j
    //�萔���ƕ�����悤�ɖ��O��ύX����Ɨǂ�
    const int MaxHP = 10;

    //�ϐ��i�ύX�ł���j
    int nowHP = 0;

    //�񋓌^
    //enum + �^��{�񋓎q};
    enum Season
    {
        Spring = 100, //0
        Summer,     //��+1
        Autumn,     //��+1     
        Winter,     //��+1
    };

    Season s = Season.Winter;

    //����̗񋓌^
    enum Weapon
    {
        Sword, Lance, Axe, Hammer, Gun, Bow,
    };
    //�񋓌^�ɑΉ������z��
    string[] nameTable = {    //���O
    "��","��","��","�n���}�[","�e","�|"
    };                        //�U����
    int[] attackPowerTable =
    {
        10,6,20,15,500,2,
    };
    Weapon w = Weapon.Gun;



    void Start()
    {
        //maxHP = 20;
        nowHP = MaxHP;
        //�񋓎q�̕\��
        Debug.Log(s);
        //�񋓎q�̐��l�̊m�F(int�ɃL���X�g)
        Debug.Log((int)s);

        Debug.Log("�I�񂾕���");
        int wNo = (int)w;      //���l�ɕϊ�
        Debug.Log("���햼" + nameTable[wNo]);
        Debug.Log("�U����" + attackPowerTable[wNo]);
    }

    void Update()
    {

    }
}
