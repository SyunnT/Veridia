#pragma once

#include "VeridiaCoreAPI_Global.h"
#include "ErrorCodeEnum.h"
#include "LanguagesEnum.h"

#ifdef __cplusplus
#include <cstdint>
extern "C" {
#else
#include <stdint.h>
#endif

typedef struct
{
    uint32_t index;
    uint32_t generation;
} Handle;

/// @brief 获取错误代码对应的描述
/// @return C 字符串
/// @param code 错误代码，为其他函数的返回值，可以从 ErrorCodeEnum 看到它们的语义
VERIDIA_DLL_API const char* errorMsg(Handle h, int32_t code);

/// @brief 创建 VeridiaCore 后端
/// @param h 句柄
VERIDIA_DLL_API int32_t createCore(Handle* h);

/// @brief 销毁一个 VeridiaCore 后端
/// @param h 被销毁的对象
VERIDIA_DLL_API int32_t destroyCore(Handle h);

/// @brief 设置 Core 程序字符串字面值的语言
/// @param h 被设置的对象
VERIDIA_DLL_API int32_t setLanguage(Handle h, int32_t lang);

#ifdef __cplusplus
}
#endif
