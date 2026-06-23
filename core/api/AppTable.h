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