using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class test5 : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
     //if���ɂ���
     if(true)
        {
            Debug.Log("if����true�Ȃ̂Ŏ��s");
        }
     //if(false)
     //   {
     //       Debug.Log("if����false�Ȃ̂Ŏ��s���Ȃ�");
     //   }
     //else���ɂ���
     if(false)
        {
            Debug.Log("���s����Ȃ�");
        }
        else
        {
            Debug.Log("else�������s�����");
        }
        //��r���Z��p����if��
        int a = 10, b = 5;
        if (a > b)
        {
            Debug.Log("a��b���傫��");
        }
        else
        {
            Debug.Log("b��a���傫��");
        }
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
