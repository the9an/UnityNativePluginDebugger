using System;
using System.Runtime.InteropServices;
using UnityEngine;

/// <summary>
/// Print Debug in Native Plugin into UnityEditor
/// </summary>
public static class NativePluginDebugListener
{
    enum CustomLogType { Log, Warning, Error }
    
    delegate void DebugCallback(IntPtr request, int logType, int size);
    
#if UNITY_EDITOR_OSX
    // TODO: Replace your plugin name
    public const string IMPORT_TARGET = "UnityNativePluginMac";
#elif UNITY_IOS
    public const string IMPORT_TARGET = "__Internal";
#else
    // TODO: Replace your plugin name
    public const string IMPORT_TARGET = "UnityNativePlugin"; // remove "lib" from name
#endif
    
    [DllImport(IMPORT_TARGET, CallingConvention = CallingConvention.Cdecl)]
    static extern void RegisterDebugCallback(DebugCallback callback);

    [RuntimeInitializeOnLoadMethod]
    static void OnRuntimeMethodLoad()
    {
        if (!Debug.unityLogger.logEnabled)
        {
            return;
        }
        RegisterDebugCallback(OnDebugCallback);
    }

    [AOT.MonoPInvokeCallback(typeof(DebugCallback))]
    static void OnDebugCallback(IntPtr request, int logType, int size)
    {
        string logMsg = Marshal.PtrToStringAnsi(request, size);
        logMsg = $"<color=green>NativeLog:</color> {logMsg}";

        switch ((CustomLogType)logType)
        {
            case CustomLogType.Warning:
                Debug.LogWarning(logMsg);
                break;
            case CustomLogType.Error:
                Debug.LogError(logMsg);
                break;
            default:
                Debug.Log(logMsg);
                break;
        }
    }
}
