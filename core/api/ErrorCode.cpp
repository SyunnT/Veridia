#include "ErrorCode.h"
#include "ErrorCodeEnum.h"

std::unordered_map<int32_t, const char*> VeridiaAPI::errorMsgsMap
{
    {API_ERRORCODE_SUCCESS, "operation success"}
};