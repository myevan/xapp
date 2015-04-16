#pragma once

#ifndef __X_FILE_BINARY__
#define __X_FILE_BINARY__

#include <x_foundation/XHeapBinary.h>

namespace xf {

class XFileBinary : public XHeapBinary
{
public:
    static XFileBinary* LoadFileBinary(const XString& xFileAbsPath)
    {
        FILE* fp = fopen(xFileAbsPath.GetPtr(), "rb");
        if (!fp)
            return NULL;

        fseek(fp, 0, SEEK_END);

        size_t newFileSize = ftell(fp);
        XFileBinary* newFileBinPtr = AllocBinary<XFileBinary>(newFileSize);
        if (newFileBinPtr != NULL)
        {
            fseek(fp, 0, SEEK_SET);
            newFileBinPtr->LoadFile(fp);
        }
        fclose(fp);

        return newFileBinPtr;
    }

public:
    inline XFileBinary(size_t binLen)
    : XHeapBinary(binLen)
    {
    }

    void LoadFile(FILE* fp)
    {
        fread(m_binPtr, m_binLen, 1, fp);
    }
};

} // end_of_namespace:xf

#endif

