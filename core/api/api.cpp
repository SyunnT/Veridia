#include "VeridiaCoreAPI.h"
#include "app/app.h"

VeridiaCore* createCore()
{
    Veridia::App* core = new Veridia::App;
    return core;
}

void destroyCore(VeridiaCore* core)
{
    delete static_cast<Veridia::App*>(core);
}