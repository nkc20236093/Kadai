using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Camera_Trigger : MonoBehaviour
{
    BoxCollider col;
    private new GameObject camera;
    Vector3 pos_up;
    Vector3 angle_up;
    Vector3 pos_back;
    Vector3 angle_back;
    float time = 1.5f;
    float Setting_time;
    // Start is called before the first frame update
    void Start()
    {
        col = GetComponent<BoxCollider>();
        camera = GameObject.Find("Main Camera");
        pos_up = new Vector3(camera.transform.position.x, camera.transform.position.y + 5, camera.transform.position.z);
        angle_up = new Vector3(75, 0, 0);
        pos_back = new Vector3(camera.transform.position.x, camera.transform.position.y + 1.5f, camera.transform.position.z - 5);
        angle_back = new Vector3(10, 0, 0);
        Camera_Back();
    }

    // Update is called once per frame
    void Update()
    {
        Setting_time = Mathf.PingPong(Time.time / time, 1);
        if (!col.gameObject)
        {
            Camera_Up();
        }
    }
    private void OnTriggerEnter(Collider other)
    {
        if (other.gameObject.layer == 3)
        {
            Camera_Back();
        }
    }
    void Camera_Up()
    {
        Debug.Log("ÉJÉÅÉâãÛíÜ");
        camera.transform.position = Vector3.Slerp(pos_up, pos_back, Setting_time);
        camera.transform.localEulerAngles = Vector3.Slerp(angle_up, angle_back, Setting_time);
    }
    void Camera_Back()
    {
        Debug.Log("ÉJÉÅÉâínñ ");
        camera.transform.position = Vector3.Slerp(pos_back, pos_up, Setting_time);
        camera.transform.localEulerAngles = Vector3.Slerp(angle_back, angle_up, Setting_time);
    }
}
