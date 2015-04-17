#pragma once

#ifndef __X_POOL__
#define __X_POOL__

#include <memory>

template<typename T>
class XPool
{
public:
    static std::shared_ptr<T> NewObject()
    {
        return std::shared_ptr<T>(new T(), DeleteObject);
    }

    template<typename A>
    static std::shared_ptr<T> NewObject(A arg)
    {
        return std::shared_ptr<T>(new T(arg), DeleteObject);
    }

    template<typename A1, typename A2>
    static std::shared_ptr<T> NewObject(A1 arg1, A2 arg2)
    {
        return std::shared_ptr<T>(new T(arg1, arg2), DeleteObject);
    }

    static void DeleteObject(T* delBinPtr)
    {
        if (delBinPtr != NULL)
        {
            delete delBinPtr;
        }
    }
};

#endif 
