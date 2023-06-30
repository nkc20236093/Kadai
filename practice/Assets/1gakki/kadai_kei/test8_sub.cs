using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class test8_sub : MonoBehaviour
{
    Text textConpornent;
    // Start is called before the first frame update
    void Start()
    {
        textConpornent = GetComponent<Text>();
        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < (i + 1); ++j)
            {
                textConpornent.text += "Å°";
            }
            textConpornent.text += "\n";
        }

        textConpornent.text += "\n";

        for (int i = 0; i < 5; i++)
        {
            for (int j = 5; j > i; j--)
            {
                textConpornent.text += "Å°";
            }
            textConpornent.text += "\n";
        }

        textConpornent.text += "\n";

        for (int i = 0; i < 5; ++i)
        {
            for (int j = 5; j > i; j--)
            {
                textConpornent.text += "  ";
            }
            for (int j = 0; j < (i + 1); ++j)
            {
                textConpornent.text += "Å°";
            }
            textConpornent.text += "\n";
        }

        textConpornent.text += "\n";
    }
}
