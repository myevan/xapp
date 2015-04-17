#pragma once

#ifndef __X_SYSTEM__
#define __X_SYSTEM__

#include <x_foundation/XURI.h>
#include <x_foundation/XPool.h>
#include <x_foundation/XString.h>
#include <x_foundation/XFileBinary.h>

#include <string>
#include <memory>

namespace xf { 

class XSystem
{
public:
    static XSystem& GetSystem();

public:
    virtual ~XSystem() {}

public:
    virtual bool TryGetResourceAbsPath(const XString& dirRelPath, const XString& fileName, std::string& outAbsPath) { return false; }

    virtual XBinary* TryGetResourceBinary(const XString& dirRelPath, const XString& fileName) { return NULL; }

    std::shared_ptr<XBinary> LoadFileBinary(const XString& fileAbsPath)
    {
        std::shared_ptr<XFileStream> newStreamPtr = XPool<XFileStream>::NewObject();
        XFileStream& newStream = *newStreamPtr;
        if (!newStream.Open(fileAbsPath))
            return std::shared_ptr<XFileBinary>();

        size_t newStreamSize = newStream.GetSize();
        std::shared_ptr<XFileBinary> newBinPtr = XPool<XFileBinary>::NewObject(newStreamSize);
        
        XFileBinary& newBin = *newBinPtr;
        if (!newBin.TryLoadFile(newStream))
            return std::shared_ptr<XFileBinary>();

        newBin.SetFilePath(fileAbsPath);
        return newBinPtr;
    }

};

} // end_of_namespace:xf

#endif
