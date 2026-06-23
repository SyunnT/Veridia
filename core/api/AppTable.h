#pragma once

#include <cstdint>
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
        static AppTable& singleton();
        uint32_t getFreeIndex();
        uint32_t getGeneration(uint32_t index);
        void initApp(uint32_t index, uint32_t generation);

    private:
        AppTable();
        ~AppTable();
        
    private:
        /// @brief Slot结构
        struct Slot
        {
            Veridia::App* obj;
            uint32_t generation;
        };

        /// @brief 动态Slot表
        std::vector<Slot> table;

        /// @brief 空闲id表
        std::stack<uint32_t> freeList;
    };
}