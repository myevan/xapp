#include "StdAfx.h"

#include <x_foundation/posix/XFileManager.h>

#include <x_foundation/XDebugMacros.h>

using namespace xf;

namespace xf { namespace posix {

XFileManager::XFileManager()
{
}

void XFileManager::SetProgramArguments(int argCount, const char** args) 
{
    assert(argCount > 0);
    const char* cProgramRelPath = args[0];
    char cProgramAbsPath[PATH_MAX];
    x_verify(realpath(cProgramRelPath, cProgramAbsPath), "CHECK_PROGRAM_REL_PATH");

    m_programAbsPath = cProgramAbsPath;
}

} } // end_of_namespace:xf.ns