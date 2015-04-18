#pragma once

#ifndef __POSIX_X_SYSTEM__
#define __POSIX_X_SYSTEM__

#include <x_foundation/XSystem.h>

#include <limits.h>

namespace xf { namespace posix {

class XSystem : public xf::XSystem
{
public:
    virtual ~XSystem() {}

public:
    XSystem();

    void SetProgramArguments(int argCount, const char** args) override
    {
        assert(argCount > 0);
        const char* cProgramRelPath = args[0];
        char cProgramAbsPath[PATH_MAX];
        x_verifyn(realpath(cProgramRelPath, cProgramAbsPath), "CHECK_PROGRAM_REL_PATH");

        m_programAbsPath = cProgramAbsPath;
    }

private:
    std::string m_programAbsPath;
};

} } // end_of_namespace:xf.ns

#endif
