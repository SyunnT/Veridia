#pragma once

#include "VeridiaCoreAPI_Global.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void VeridiaCore;

/// @brief 创建 VeridiaCore 后端
/// @return 返回一个 VeridiaCore* 类型的实例，必须通过 destroyCore 销毁
VERIDIA_DLL_API VeridiaCore *createCore();

/// @brief 销毁一个 VeridiaCore 后端
VERIDIA_DLL_API void destroyCore(VeridiaCore*);

#ifdef __cplusplus
}
#endif