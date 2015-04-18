#include "StdAfx.h"

#import "x_foundation/ns/XFileManager.h"
#import "x_foundation/ns/NSString+XString.h"

using namespace xf;

namespace xf { namespace ns {

XFileManager::XFileManager()
{
    m_mainBundle = [NSBundle mainBundle];
}

std::shared_ptr<XText> XFileManager::LoadText(const XString& uri)
{
    XString scheme;
    if (TryParseURIScheme(uri, scheme))
    {
        if (scheme.Equals("app"))
        {
            const char* uriChars = uri.GetChars();
            size_t uriSize = uri.GetSize();
            size_t schemeSize = scheme.GetSize() + 1;
            XString uriBody(uriChars + schemeSize, uriSize - schemeSize); 
            
            XString xDirPath;
            XString xFileName;
            SplitPath(uriBody, xDirPath, xFileName);

            NSString* nDirPath = [NSString stringWithXString:xDirPath];
            NSString* nFileName = [NSString stringWithXString:xFileName];
            NSString* nFileAbsPath = [m_mainBundle pathForResource:nFileName ofType:nil inDirectory:nDirPath];
            if (nFileAbsPath == nil) 
                return std::shared_ptr<XText>();

            XString xFileAbsPath([nFileAbsPath UTF8String], [nFileAbsPath length]);
            return xf::XFileManager::LoadText(xFileAbsPath);
        }
    }
    return std::shared_ptr<XText>();
}



} } // end_of_namespace:xf.ns
