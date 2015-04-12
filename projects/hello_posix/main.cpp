#include <x_foundation/XLogMacros.h>
#include <x_foundation/XInformation.h>

using namespace xf;

int main(int argc, const char** argv)
{
    const XString& title = XInformation::GetTitle();
    x_debugn(title.GetPtr());
    return 0;
}
