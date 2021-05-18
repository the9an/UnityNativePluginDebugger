//
//  UnityNativePlugin.cpp
//  UnityNativePlugin
//
//  Created by Quan Nguyen on 2021/05/18.
//

#include "UnityNativePlugin.hpp"
#include "Debug.hpp"

extern "C"
{
    DllExport void TestLog()
    {
        Debug::Log("TEST");
    }
}
