using UnityEngine;

public class GameInitial : MonoBehaviour
{
    [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.BeforeSceneLoad)]
    static void main()
    {
        // Screen.SetResolution(1280, 800, FullScreenMode.Windowed, 60);
        Screen.SetResolution(1280, 720, FullScreenMode.Windowed);

        //Resolution res = Screen.currentResolution;
        //Screen.SetResolution((int)(res.width*0.8f), (int)(res.height*0.8f), false, 60);
        //Debug.Log("main");
    }

    //[RuntimeInitializeOnLoadMethod]
    //static void OnRuntimeMethodLoad()
    //{
    //    Screen.SetResolution(1366, 768, false, 60);
    //    Debug.Log("OnRuntimeMethodLoad");
    //}
}