#include "AppTable.h"
#include "app/VeridiaApp.h"

using namespace VeridiaAPI;

AppTable& AppTable::singleton()
{
    static AppTable instance;
    return instance;
}

uint32_t AppTable::getFreeIndex()
{
    uint32_t index = -1;
    if (!freeList.empty()) {
        index = freeList.top();
    }
    else {
        index = table.size();
    }
    return index;
}

// uint32_t AppTable::getGeneration(uint32_t index)
// {
    
// }

void AppTable::initApp(uint32_t index, uint32_t generation)
{}

AppTable::AppTable() = default;

AppTable::~AppTable()
{
    for (Slot& elem : table) {
        delete elem.obj;
    }
}