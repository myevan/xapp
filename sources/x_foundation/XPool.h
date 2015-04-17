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

    static void DeleteObject(T* delBinPtr)
    {
        if (delBinPtr != NULL)
        {
            delete delBinPtr;
        }
    }
};

#endif 
