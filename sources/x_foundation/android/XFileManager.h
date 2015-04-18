#pragma once

#ifndef __ANDROID_X_FILE_MANAGER__
#define __ANDROID_X_FILE_MANAGER__

#include <x_foundation/XFileManager.h>
#include <x_foundation/XStream.h>

#include <android/asset_manager.h>

namespace xf { namespace android {

class XFileManager : public xf::XFileManager
{
public:
    static void BindAssetManager(AAssetManager* assetManager)
    {
        ms_assetManager = assetManager;
    }

public:
    virtual ~XFileManager() {}

public:
    XFileManager();

public:
    std::shared_ptr<XStream> OpenStream(const XString& uri) override;

private:
    static AAssetManager* ms_assetManager;

};

} } // end_of_namespace:xf.ns

#endif
