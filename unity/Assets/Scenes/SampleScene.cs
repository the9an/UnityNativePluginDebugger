using System.Runtime.InteropServices;
using UnityEngine;

public class SampleScene : MonoBehaviour
{
    [DllImport(NativePluginDebugListener.IMPORT_TARGET)]
    static extern void TestLog();
    
    void Start()
    {
        TestLog();
    }
}
