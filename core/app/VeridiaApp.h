#pragma once

#include <cstdint>
#include <string>

namespace Veridia
{
    class App
    {
    public:
        App();
        ~App();
        void setLanguage(int32_t lang_code);
        std::string getErrorMsg(int32_t error_code);
    private:
        int32_t m_language = 0;
    };
}