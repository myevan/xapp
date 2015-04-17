#pragma once

#ifndef __X_FILE_BINARY__
#define __X_FILE_BINARY__

#include <x_foundation/XHeapBinary.h>
#include <x_foundation/XFileStream.h>

namespace xf {

class XFileBinary : public XHeapBinary
{
public:
    inline XFileBinary(size_t binLen)
    : XHeapBinary(binLen)
    {
    }

    bool TryLoadFile(XFileStream& stream)
    {
        return (stream.ReadBytes(m_binLen, m_binPtr) == m_binLen);
    }

    void SetFilePath(const XString& filePath)
    {
        filePath.GetString(m_filePath);
    }

    const std::string& GetFilePath()
    {
        return m_filePath;
    }

private:
    std::string m_filePath;
};

} // end_of_namespace:xf

#endif

