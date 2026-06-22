#pragma once

#ifdef _WIN32
#ifdef VERIDIA_EXPORT
#define VERIDIA_DLL_API __declspec(dllexport)
#else
#define VERIDIA_DLL_API __declspec(dllimport)
#endif
#else
#define VERIDIA_DLL_API
#endif