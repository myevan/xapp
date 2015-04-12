#pragma once

#ifndef __ANDROID_X_SYSTEM__
#define __ANDROID_X_SYSTEM__

namespace xf { namespace android {

//! @brief [kr] 안드로이드 시스템
class XSystem
{
public:
    //! @brief  [kr] ABI(Application Binary Interface) 이름 얻기
    //! @return [kr] ABI 이름
    static const char* GetABIName();
};

} } // end_of_namespace:xf.android

#endif
