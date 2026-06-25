#include "VeridiaApp.h"
#include "i18n/VeridiaLiterals.h"

using namespace Veridia;

void App::setLanguage(int32_t lang_code)
{
    m_language = lang_code;
}

std::string App::getErrorMsg(int32_t error_code)
{
    return Literal::getErrorMsg(error_code, m_language);
}