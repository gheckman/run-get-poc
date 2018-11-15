#pragma once

// Must be included last, after all classes that implement the interface

struct list_of_types
{
    typedef TYPE_LIST type;
};

template <typename T, typename ...Types>
inline abstract_base* run_get_on_types(int i, TypeList<T, Types...>)
{
    auto* find_type = T::get(i);
    return find_type ? find_type : run_get_on_types(i, TypeList<Types...>());
}

template <typename T>
inline abstract_base* run_get_on_types(int i, TypeList<T>)
{
    return T::get(i);
}