//
//  Defines.h
//  UnityNativePlugin
//
//  Created by Quan Nguyen on 2021/06/30.
//

#ifndef Defines_h
#define Defines_h

#if defined(WIN32) || defined(_WIN32)
// For Unity Windows, use
#define DllExport __declspec(dllexport)
#else
#define DllExport __attribute__((visibility("default")))
#endif

namespace UnityEngine {
    enum class LogType {
        Log = 0,
        Warning,
        Error
    };
}

#endif /* Defines_h */
