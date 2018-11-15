#pragma once

#include <iostream>

#include "interface.h"

struct vehicle : interface<vehicle>
{
    static vehicle* get(int i)
    {
        static vehicle me;
        bool match = i == 1;
        std::cout << (match ? "Found" : "No") << " match for vehicle with i=" << i << std::endl;
        return match ? &me : nullptr;
    }

    virtual void pass_flags(int i) override
    {
        std::cout << "vehicle got flag=" << i << std::endl;
    }
};

REGISTER_TO_TYPE_LIST(vehicle) TypeList_vehicle;
#undef TYPE_LIST
#define TYPE_LIST TypeList_vehicle