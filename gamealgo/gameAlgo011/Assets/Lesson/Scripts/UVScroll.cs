using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class UVScroll : MonoBehaviour
{
    Image image;
    float speed = 0.1f;
    Vector2 dir = Vector2.one;

    void Start()
    {
        image = GetComponent<Image>();
    }

    void Update()
    {
        image.material.mainTextureOffset += dir * speed * Time.deltaTime;
    }
}
