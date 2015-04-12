#pragma once

#ifndef __ANDROID_X_ASSET_BINARY__
#define __ANDROID_X_ASSET_BINARY__

#include <x_foundation/XBinary.h>
#include <x_foundation/XString.h>

#include <android/asset_manager.h>

#include <x_foundation/XLogMacros.h>

namespace xf { namespace android {

class XAssetBinary : public XBinary
{
public:
    static void BindAssetManager(AAssetManager* assetManager)
    {
        ms_assetManager = assetManager;
    }

    static XAssetBinary* LoadAssetBinary(const XString& assetPath)
    {
        // assert(ms_assetManager != NULL);

        const char* cAssetPath = assetPath.GetPtr();
        AAsset* newAssetPtr = AAssetManager_open(ms_assetManager, cAssetPath, AASSET_MODE_UNKNOWN);
        if (NULL == newAssetPtr) 
        {
            return NULL;
        }

        size_t newAssetSize = AAsset_getLength(newAssetPtr);
        XAssetBinary* newAssetBinPtr = AllocAssetBinary(newAssetSize);
        if (newAssetBinPtr != NULL)
        {
            newAssetBinPtr->LoadAsset(newAssetPtr);
        }
        AAsset_close(newAssetPtr);
        return newAssetBinPtr;
    }

private:
    static XAssetBinary* AllocAssetBinary(size_t binLen)
    {
        if (binLen == 0)
        {
            static XAssetBinary s_emptyBin;
            return &s_emptyBin;
        }
        else
        {
            return new XAssetBinary(binLen);
        }
    }

    static void FreeAssetBinary(XAssetBinary* delBinPtr)
    {
        if (delBinPtr != NULL)
        {
            delete delBinPtr;
        }
    }

private:
    static AAssetManager* ms_assetManager;

public:
    virtual ~XAssetBinary()
    {
        if (m_binPtr != NULL)
        {
            x_debugn("free");
            free(m_binPtr);
        }
    }

private:
    inline XAssetBinary()
    : XBinary()
    {
    }

    inline XAssetBinary(size_t binLen)
    : m_binLen(binLen)
    , m_binPtr((unsigned char*)malloc(m_binLen))
    {
        x_debugn("alloc");
    }

    void LoadAsset(AAsset* assetPtr)
    {
        AAsset_read(assetPtr, m_binPtr, m_binLen);
    }

    void DeleteThis()
    {
        FreeAssetBinary(this);
    }

public:
    inline const unsigned char* GetPtr() const { return m_binPtr; }
    inline size_t GetLen() const { return m_binLen; }

private:
    unsigned char* m_binPtr;
    size_t m_binLen;
};

} } // end_of_namespace:xf.android

#endif

