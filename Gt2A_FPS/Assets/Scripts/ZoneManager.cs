using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Photon.Pun;

public class ZoneManager : MonoBehaviourPunCallbacks
{
    public int ZoneSequence;
    public int[] ZoneDamages = new int[8]
    {
        1,1,2,2,3,3,4,5
    };
    float timer = 0;
    [SerializeField] Vector3 TargetPos;
    [SerializeField] float TargetSize;
    [SerializeField] float Speed;
    [SerializeField] float MinX, MaxX;
    [SerializeField] float MinZ, MaxZ;
    [SerializeField] float MaxSize, MinSize;
    // Start is called before the first frame update
    void Start()
    {
        TargetPos = GetRandomPos();
        TargetSize = Random.Range(MinSize, MaxSize);
    }

    // Update is called once per frame
    void Update()
    {
        Sequence();
        SizeMove();
    }
    void SizeMove()
    {
        transform.position = Vector3.MoveTowards(transform.position, TargetPos, Speed * Time.deltaTime);
        transform.localScale = Vector3.Lerp(transform.localScale, new Vector3(TargetSize, 20, TargetSize), Speed * Time.deltaTime);
        if (transform.position == TargetPos && transform.localScale.x == TargetSize) 
        {
            TargetPos = GetRandomPos();
            TargetSize = Random.Range(MinSize, MaxSize);
        }
    }
    Vector3 GetRandomPos()
    {
        float randomX = Random.Range(MinX, MaxX);
        float randomZ = Random.Range(MinX, MaxX);
        return new Vector3(randomX, transform.position.y, randomZ);
    }
    void Sequence()
    {
        ZoneSequence = Mathf.Clamp(ZoneSequence, 0, ZoneDamages.Length - 1);
        timer += Time.deltaTime;
        if (timer > 8)
        {
            timer = 0;
            ZoneSequence++;
        }
    }
}
