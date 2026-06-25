#pragma once

#include <cstdint>
#include <string>
#include <vector>
#include <stack>

namespace Veridia {
    class App;
}

namespace VeridiaAPI
{
    class AppTable
    {
    public:
        static std::string errorMsg(uint32_t index, uint32_t generation, int32_t error_code);
        static uint32_t getFreeIndex();
        static uint32_t getNewGeneration(uint32_t index);
        static void initApp(uint32_t index, uint32_t generation);
        static void releaseApp(uint32_t index, uint32_t generation);
        static void setAppLanguage(uint32_t index, uint32_t generation, int32_t lang_code);
        
    private:
        /// @brief Slot结构
        struct Slot
        {
            Veridia::App* obj;
            uint32_t generation;
            Slot();
            ~Slot();
        };

        /// @brief 动态Slot表
        static std::vector<Slot> table;

        /// @brief 空闲id表
        static std::stack<uint32_t> freeList;
    };
}