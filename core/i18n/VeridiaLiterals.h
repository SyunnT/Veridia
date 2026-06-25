#pragma once

#include <cstdint>
#include <string>
#include <unordered_map>

namespace Veridia
{
    enum class RuntimeLiteral
    {

    };
    
    class Literal
    {
    public:
        static std::string getErrorMsg(int32_t error_code, int32_t lang_code);
        static std::string getRuntimeLiteral(RuntimeLiteral code, int32_t lang_code);

    private:
        static std::unordered_map<int32_t, std::string> errorCodeLabelMap;
        static std::unordered_map<int32_t, std::string> languageSuffixMap;
        static std::unordered_map<RuntimeLiteral, std::string> literalCodeLabelMap;
        static std::string filenamePath;
    };
}