using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManeger : MonoBehaviour
{
    public static GameManeger instance;
    /// <summary>
    /// ƒQ[ƒ€‚ªI—¹‚µ‚½‚©
    /// true = ‡’†
    /// false = ‡I—¹
    /// </summary>
    public bool GameEnd; 
    private void Awake()
    {
        if (instance == null)
        {
            instance = this;
            DontDestroyOnLoad(gameObject);
        }
        else
        {
            Destroy(gameObject);
        }
    }
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if (GameEnd)
        {

        }
    }
}
