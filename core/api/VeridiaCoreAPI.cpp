#include "VeridiaCoreAPI.h"
#include "AppTable.h"
#include "ErrorCode.h"

const char* errorMsg(int32_t code)
{
    return VeridiaAPI::errorMsgsMap[code];
}

int32_t createCore(Handle* h)
{}

int32_t destroyCore(Handle h)
{}

int32_t setLanguage(Handle h);