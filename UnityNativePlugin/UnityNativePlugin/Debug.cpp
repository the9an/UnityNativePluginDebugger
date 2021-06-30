//
//  Debug.cpp
//
//  Created by Quan Nguyen on 2021/05/18.
//

#include "Debug.h"

extern "C"
{
    DllExport void RegisterDebugCallback(CallbackFunc callback) {
        registedCallback = callback;
    }
}

namespace UnityEngine
{
    const char* Debug::ConvertMessage(const char message) {
        std::stringstream ss;
        ss << message;
        const std::string tmp = ss.str();
        const char* tmsg = tmp.c_str();
        return tmsg;
    }
    const char* Debug::ConvertMessage(const std::string message) {
        const char* tmsg = message.c_str();
        return tmsg;
    }

    void  Debug::Log(const char* message) {
        if (registedCallback != nullptr)
            registedCallback(message, LogType::Log, (int)strlen(message));
    }
    void  Debug::Log(const char message) {
        Debug::Log(Debug::ConvertMessage(message));
    }
    void  Debug::Log(const std::string message) {
        Debug::Log(Debug::ConvertMessage(message));
    }

    void  Debug::LogWarning(const char* message) {
        if (registedCallback != nullptr)
            registedCallback(message, LogType::Warning, (int)strlen(message));
    }
    void  Debug::LogWarning(const char message) {
        Debug::LogWarning(Debug::ConvertMessage(message));
    }
    void  Debug::LogWarning(const std::string message) {
        Debug::LogWarning(Debug::ConvertMessage(message));
    }

    void  Debug::LogError(const char* message) {
        if (registedCallback != nullptr)
            registedCallback(message, LogType::Error, (int)strlen(message));
    }
    void  Debug::LogError(const char message) {
        Debug::LogError(Debug::ConvertMessage(message));
    }
    void  Debug::LogError(const std::string message) {
        Debug::LogError(Debug::ConvertMessage(message));
    }
}
