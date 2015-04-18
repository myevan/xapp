#include "StdAfx.h"

#import "x_foundation/ns/XFileManager.h"
#import "x_foundation/ns/NSString+XString.h"

using namespace xf;

namespace xf { namespace ns {

XFileManager::XFileManager()
{
    m_mainBundle = [NSBundle mainBundle];
}

std::shared_ptr<XFileStream> XFileManager::OpenStream(const XString& uri)
{
    XString uriBody;
    XString uriScheme;
    if (TryParseURI(uri, uriScheme, uriBody))
    {
        if (uriScheme.Equals("app"))
        {
            XString xDirPath;
            XString xFileName;
            SplitPath(uriBody, xDirPath, xFileName);

            NSString* nDirPath = [NSString stringWithXString:xDirPath];
            NSString* nFileName = [NSString stringWithXString:xFileName];
            NSString* nFileAbsPath = [m_mainBundle pathForResource:nFileName ofType:nil inDirectory:nDirPath];
            if (nFileAbsPath != nil) 
            {
                XString xFileAbsPath([nFileAbsPath UTF8String], [nFileAbsPath length]);
                return xf::XFileManager::OpenStream(xFileAbsPath);
            }
        }
    }
    return std::shared_ptr<XFileStream>();
}



} } // end_of_namespace:xf.ns
