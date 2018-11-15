#pragma once

#include <iostream>

#include "interface.h"

struct train : interface<train>
{
    static train* get(int i)
    {
        static train me;
        bool match = i == 0;
        std::cout << (match ? "Found" : "No") << " match for train with i=" << i << std::endl;
        return match ? &me : nullptr;
    }

    virtual void pass_flags(int i) override
    {
        std::cout << "train got flag=" << i << std::endl;
    }
};

REGISTER_TO_TYPE_LIST(train) TypeList_train;
#undef TYPE_LIST
#define TYPE_LIST TypeList_train