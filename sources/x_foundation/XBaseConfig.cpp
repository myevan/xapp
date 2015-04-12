#include <x_foundation/XInformation.h>
#include <x_foundation/XString.h>

namespace xf {

const XString& XInformation::GetTitle()
{
    static XString s_title("XApplication");
    return s_title;
}

} // end_of_namespace:xf
