#pragma once

// Not used here, but convenient for implementors
#include "type_list.h"

// README
//
// Implementors of this class must include the following lines below their
// class declaration, replacing foo with their class name and TypeList_foo with
// TypeList_ClassName (or anything unique, it won't compile otherwise)
//
// REGISTER_TO_TYPE_LIST(foo) TypeList_foo;
// #undef TYPE_LIST
// #define TYPE_LIST TypeList_foo

struct abstract_base
{
    virtual void* static_get(int i) = 0;
    virtual void pass_flags(int i) = 0;
};

template <class T>
struct interface : abstract_base
{
    virtual void* static_get(int i) override { return T::get(i); }
};