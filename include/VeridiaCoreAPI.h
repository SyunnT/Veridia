#pragma once

#include "VeridiaCoreAPI_Global.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
    uint32_t index;
    uint32_t generation;
} Handle;

/// @brief 创建 VeridiaCore 后端
/// @return 返回的对象的句柄
VERIDIA_DLL_API Handle createCore();

/// @brief 销毁一个 VeridiaCore 后端
/// @param 被销毁对象的句柄
VERIDIA_DLL_API void destroyCore(Handle);

#ifdef __cplusplus
}
#endif
