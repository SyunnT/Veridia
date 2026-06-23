#include "AppTable.h"
#include "app/VeridiaApp.h"

using namespace VeridiaAPI;

AppTable& AppTable::singleton()
{
    static AppTable instance;
    return instance;
}

Handle AppTable::getNewHandle()
{
    uint32_t index = -1;
    if (!freeList.empty()) {
        index = freeList.top();
        
    }
    else {
        
    }
}

AppTable::AppTable() = default;

AppTable::~AppTable()
{
    for (Slot& elem : table) {
        delete elem.obj;
    }
}