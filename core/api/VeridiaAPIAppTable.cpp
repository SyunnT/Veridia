#include "VeridiaAPIAppTable.h"
#include "app/VeridiaApp.h"

using namespace VeridiaAPI;

AppTable::Slot::Slot()
    : obj(nullptr)
    , generation(1)
{}

AppTable::Slot::~Slot()
{
    delete obj;
}

std::vector<AppTable::Slot> AppTable::table {};

std::stack<uint32_t> AppTable::freeList {};

std::string AppTable::errorMsg(uint32_t index, uint32_t generation, int32_t error_code)
{
    try {
        if (table[index].generation != generation)
            throw std::exception();
    }
    catch (const std::exception& e) {
        throw e;
    }
    return table[index].obj->getErrorMsg(error_code);
}

uint32_t AppTable::getFreeIndex()
{
    if (freeList.empty()) {
        table.push_back(Slot());
        freeList.push(table.size() - 1);
    }
    return freeList.top();
}

uint32_t AppTable::getNewGeneration(uint32_t index)
{
    return table[index].generation;
}

void AppTable::initApp(uint32_t index, uint32_t generation)
{
    try {
        if (table[index].generation != generation)
            throw std::exception();
    }
    catch (const std::exception& e) {
        throw e;
    }
    table[index].obj = new Veridia::App;
}

void AppTable::releaseApp(uint32_t index, uint32_t generation)
{
    try {
        if (table[index].generation != generation)
            throw std::exception();
    }
    catch (const std::exception& e) {
        throw e;
    }
    delete table[index].obj;
    table[index].obj = nullptr;
    ++table[index].generation;
    freeList.push(index);
}

void AppTable::setAppLanguage(uint32_t index, uint32_t generation, int32_t lang_code)
{
    try {
        if (table[index].generation != generation)
            throw std::exception();
    }
    catch (const std::exception& e) {
        throw e;
    }
    table[index].obj->setLanguage(lang_code);
}