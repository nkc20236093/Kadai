using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class test3 : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        //�l�����Z�ɂ���
        int x = 7, y = 3;
        int sum;

        //���Z
        sum = x + y;
        Debug.Log("x + y =" +sum);

        //���Z
        sum = x - y;
        Debug.Log("x - y =" + sum);

        //��Z
        sum = x * y;
        Debug.Log("x * y =" + sum);

        //���Z
        sum = x / y;
        Debug.Log("x / y =" + sum);

        //��]�Z
        sum = x % y;
        Debug.Log("x % y =" + sum);
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
