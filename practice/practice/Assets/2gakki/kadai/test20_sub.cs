using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;
using UnityEngine.AI;
using static Unity.Collections.Unicode;

public class test20_sub : MonoBehaviour
{
    [Serialize] public int m = 1;

    // �ۑ�20
    // 1����12�̒l�����񋓌^�AMonth���쐬
    // 1...January, 2...February..�Ƃ������悤�Ȍ^�����
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

    // int�^�̕ϐ�x���쐬���A�����̒a������Month�^�̗񋓎q��
    // �L���X�g��p���đ��
    // Debug.log��x��\��
    // �\����j�a������10

    // �����^�̕ϐ�m�ɍD���Ȑ�������͂��A
    // ���̌���Month�^�̗񋓎q�ɕϊ����ĕ\������
    // �Ȃ��A�O��X�X�Ƃ������l�����͂��ꂽ�ꍇ�A
    // �����Ȓl�ł��ƕ\������
    // �\����j
    // m��0�̏ꍇ�������Ȓl�ł�
    // m��2�̏ꍇ��February
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
        int x = (int)Month.May;
        Debug.Log($"�a������{x}��");


        if (m > 0 && m <= 12)
        {
            Month month = (Month)(int)m;
            Debug.Log(month);
        }
        else
        {
            Debug.Log($"{m}�͖����Ȓl�ł�");
        }
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}