#include "AppTable.h"

Handle createCore()
{
    return VeridiaAPI::AppTable::singleton().getNewHandle();
}

void destroyCore(Handle handle)
{
    VeridiaAPI::AppTable::singleton().releaseHandle(handle);
}