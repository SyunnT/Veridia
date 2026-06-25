#include "VeridiaLiterals.h"
#include "ErrorCodeEnum.h"
#include "LanguagesEnum.h"

using namespace Veridia;

std::unordered_map<int32_t, std::string> Literal::errorCodeLabelMap {
    {API_ERRORCODE_SUCCESS, "API_ERRORCODE_SUCCESS"}
};

std::unordered_map<int32_t, std::string> Literal::languageSuffixMap {
    {VERIDIA_CORE_ENGLISH, "_en"},
    {VERIDIA_CORE_SIMPLE_CHINESE, "_zh_CN"}
};

std::unordered_map<RuntimeLiteral, std::string> Literal::literalCodeLabelMap {

};

std::string Literal::filenamePath{"veridia_core"};

std::string Literal::getErrorMsg(int32_t error_code, int32_t lang_code)
{
    return "";
}

std::string Literal::getRuntimeLiteral(RuntimeLiteral code, int32_t lang_code)
{
    return "";
}