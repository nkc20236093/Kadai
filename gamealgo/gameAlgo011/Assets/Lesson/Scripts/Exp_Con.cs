using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Exp_Con : MonoBehaviour
{
    
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        float time =+ Time.deltaTime;
        if (time <= 1.1f)
        {
            Debug.Log("”j‰ó");
            Destroy(gameObject);
        }
    }
}
