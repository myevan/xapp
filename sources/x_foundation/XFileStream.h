#pragma once

#ifndef __X_FILE_STREAM__
#define __X_FILE_STREAM__

#include <x_foundation/XTypes.h>
#include <x_foundation/XStream.h>

namespace xf {

class XFileStream : public XStream
{
public:
    XFileStream()
    : m_filePtr(NULL)
    {
    }

    virtual ~XFileStream()
    {
        Close();
    }

    void Close()
    {
        if (m_filePtr != NULL)
        {
            fclose(m_filePtr);
            m_filePtr = NULL;
        }
    }

    bool Open(const XPath& fileAbsPath)
    {
        m_filePtr = fopen(fileAbsPath.GetChars(), "rb");
        if (!m_filePtr)
            return false;

        return true;
    }

    size_t GetSize() override
    {
        size_t curPos = ftell(m_filePtr);
        fseek(m_filePtr, 0, SEEK_END);
        size_t endPos = ftell(m_filePtr);
        fseek(m_filePtr, curPos, SEEK_SET);
        return endPos;
    }

    size_t ReadBytes(size_t byteCount, byte_t* outBytes) override
    {
        return fread(outBytes, 1, byteCount, m_filePtr);
    }

private:
    FILE* m_filePtr;
};

} // end_of_namespace:xf

#endif
