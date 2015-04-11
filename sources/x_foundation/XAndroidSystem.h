#pragma once

#ifndef __X_ANDROID_SYSTEM__
#define __X_ANDROID_SYSTEM__

namespace xf { 

//! @brief [kr] 안드로이드 시스템
class XAndroidSystem
{
public:
    //! @brief  [kr] ABI(Application Binary Interface) 이름 얻기
    //! @return [kr] ABI 이름
    static const char* GetABIName();
};

} // end_of_namespace:xf

#endif
