#include "StdAfx.h"
#include "XFileManager.h"

#include <x_foundation/XDebugMacros.h>
#include <x_foundation/XBufferStream.h>
#include <x_foundation/XPool.h>

using namespace xf;

namespace xf { namespace android {

AAssetManager* XFileManager::ms_assetManager = NULL;

XFileManager::XFileManager()
{
}

std::shared_ptr<XStream> XFileManager::OpenStream(const XString& uri)
{
    XString uriBody;
    XString uriScheme;
    if (TryParseURI(uri, uriScheme, uriBody))
    {
        if (uriScheme.Equals("app"))
        {
            const char* assetPath = uriBody.GetChars();
            AAsset* assetp = AAssetManager_open(ms_assetManager, assetPath, AASSET_MODE_UNKNOWN);
            if (assetp) 
            {
                size_t assetSize = AAsset_getLength(assetp);
                std::shared_ptr<XBuffer> bufp = XPool<XBuffer>::NewObject(assetSize, assetSize);
                if (bufp)
                {
                    XBuffer& buf = *bufp;
                    byte_t* bufBytes = buf.GetBytes();
                    size_t bufSize = buf.GetSize();
                    AAsset_read(assetp, bufBytes, bufSize);
                    AAsset_close(assetp);
                    return XPool<XBufferStream>::NewObject(bufp);
                }
                AAsset_close(assetp);
            }
        }
    }

    return std::shared_ptr<XStream>();
}

} } // end_of_namespace:xf.ns
