#pragma once

#ifndef __X_FILE_BINARY__
#define __X_FILE_BINARY__

#include <x_foundation/XHeapBinary.h>


namespace xf {

class XFileBinary : public XHeapBinary
{
public:
    static std::shared_ptr<XFileBinary> LoadFileBinary(const XString& fileAbsPath)
    {
        FILE* fp = fopen(fileAbsPath.GetPtr(), "rb");
        if (!fp)
            return std::shared_ptr<XFileBinary>();

        fseek(fp, 0, SEEK_END);

        size_t newFileSize = ftell(fp);
        std::shared_ptr<XFileBinary> newFileBinPtr = AllocBinary<XFileBinary>(newFileSize);
        fseek(fp, 0, SEEK_SET);

        XFileBinary& newFileBin = *newFileBinPtr;
        newFileBin.SetFilePath(fileAbsPath);
        newFileBin.LoadFile(fp);
        fclose(fp);

        return newFileBinPtr;
    }

public:
    inline XFileBinary(size_t binLen)
    : XHeapBinary(binLen)
    {
    }

private:
    void SetFilePath(const XString& filePath)
    {
        filePath.GetString(m_filePath);
    }

    void LoadFile(FILE* fp)
    {
        fread(m_binPtr, m_binLen, 1, fp);
    }

private:
    std::string m_filePath;
};

} // end_of_namespace:xf

#endif

