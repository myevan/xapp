#pragma once

#ifndef __ANDROID_X_ASSET_BINARY__
#define __ANDROID_X_ASSET_BINARY__

#include <x_foundation/XHeapBinary.h>
#include <x_foundation/XString.h>

#include <android/asset_manager.h>

#include <x_foundation/XLogMacros.h>

namespace xf { namespace android {

class XAssetBinary : public XHeapBinary
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
        XAssetBinary* newAssetBinPtr = AllocBinary<XAssetBinary>(newAssetSize);
        if (newAssetBinPtr != NULL)
        {
            newAssetBinPtr->LoadAsset(newAssetPtr);
        }
        AAsset_close(newAssetPtr);
        return newAssetBinPtr;
    }

private:
    void LoadAsset(AHeap* assetPtr)
    {
        AHeap_read(assetPtr, m_binPtr, m_binLen);
    }

private:
    static AAssetManager* ms_assetManager;

};

} } // end_of_namespace:xf.android

#endif

