using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class test3 : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        //l‘¥‰‰Z‚É‚Â‚¢‚Ä
        int x = 7, y = 3;
        int sum;

        //‰ÁZ
        sum = x + y;
        Debug.Log("x + y =" +sum);

        //Œ¸Z
        sum = x - y;
        Debug.Log("x - y =" + sum);

        //æZ
        sum = x * y;
        Debug.Log("x * y =" + sum);

        //œZ
        sum = x / y;
        Debug.Log("x / y =" + sum);

        //è—]Z
        sum = x % y;
        Debug.Log("x % y =" + sum);
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
