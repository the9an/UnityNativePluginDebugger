//
//  UnityNativePlugin.cpp
//  UnityNativePlugin
//
//  Created by Quan Nguyen on 2021/05/18.
//

#include "UnityNativePlugin.hpp"
#include "Debug.h"

extern "C"
{
    DllExport void TestLog()
    {
        UnityEngine::Debug::Log("TEST");
    }
}
