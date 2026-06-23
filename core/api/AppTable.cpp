#include "AppTable.h"
#include "app/VeridiaApp.h"

using namespace VeridiaAPI;

AppTable& AppTable::singleton()
{
    static AppTable instance;
    return instance;
}

AppTable::AppTable() = default;

AppTable::~AppTable()
{
    for (Slot& elem : table) {
        delete elem.obj;
    }
}