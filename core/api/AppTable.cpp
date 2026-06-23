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
        freeList.pop();
    }
    else {
        index = table.size();
        table.push_back({nullptr, 1});
    }
    table[index].obj = new Veridia::App;
    return {index, table[index].generation};
}

void AppTable::releaseHandle(Handle handle)
{
    // TODO: 检查handle

    delete table[handle.index].obj;
    table[handle.index].obj = nullptr;
    ++table[handle.index].generation;
    freeList.push(handle.index);
}

AppTable::AppTable() = default;

AppTable::~AppTable()
{
    for (Slot& elem : table) {
        delete elem.obj;
    }
}