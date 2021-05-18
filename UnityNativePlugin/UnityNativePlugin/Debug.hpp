//
//  Debug.hpp
//
//  Created by Quan Nguyen on 2021/05/18.
//

#ifndef Debug_hpp
#define Debug_hpp

#include <stdio.h>
#include <string>
#include <stdio.h>
#include <sstream>

#define DllExport __attribute__((visibility("default")))

// For Unity Windows, use
//#define DllExport __declspec(dllexport)

extern "C"
{
    typedef void(*CallbackFunc)(const char* message, int logType, int size);
    static CallbackFunc registedCallback = nullptr;
    DllExport void RegisterDebugCallback(CallbackFunc callback);
}

enum class LogType { Log, Warning, Error };

class  Debug
{
public:
    static void Log(const char* message);
    static void Log(const char message);
    static void Log(const std::string message);
    
    static void LogWarning(const char* message);
    static void LogWarning(const char message);
    static void LogWarning(const std::string message);
    
    static void LogError(const char* message);
    static void LogError(const char message);
    static void LogError(const std::string message);
    
private:
    static const char* ConvertMessage(const char message);
    static const char* ConvertMessage(const std::string message);
};

#endif /* Debug_hpp */
