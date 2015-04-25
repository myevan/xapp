#include "StdAfx.h"

#import "XFileManager.h"
#import "NSString+XString.h"

#import "../XFileStream.h"
#import "../XPool.h"

using namespace xf;

namespace xf { namespace ns {

XFileManager::XFileManager()
{
    m_mainBundle = [NSBundle mainBundle];
}

std::shared_ptr<XStream> XFileManager::OpenStream(const XString& uri)
{
    XString uriBody;
    XString uriScheme;
    if (TryParseURI(uri, uriScheme, uriBody))
    {
        if (uriScheme.Equals("data"))
        {
            XString xDirPath;
            XString xFileName;
            if (!uriBody.TrySplitBranchAndLeaf('/', xDirPath, xFileName))
                xFileName = uriBody;

            NSString* nDirPath = [NSString stringWithXString:xDirPath];
            NSString* nFileName = [NSString stringWithXString:xFileName];
            NSString* nFileAbsPath = [m_mainBundle pathForResource:nFileName ofType:nil inDirectory:nDirPath];
            if (nFileAbsPath != nil) 
            {
                const char* fileAbsPathChars = [nFileAbsPath UTF8String];
                const size_t fileAbsPathLen = [nFileAbsPath length];
                XPath fileAbsPath(fileAbsPathChars, fileAbsPathLen);
                std::shared_ptr<XFileStream> streamp = XPool<XFileStream>::NewObject();
                XFileStream& stream = *streamp;
                if (!stream.Open(fileAbsPath))
                    return std::shared_ptr<XFileStream>();

    return streamp;
            }
        }
    }
    return std::shared_ptr<XStream>();
}



} } // end_of_namespace:xf.ns
