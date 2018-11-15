#include <iostream>
#include <string>
#include <typeinfo>

#include "train.h"
#include "vehicle.h"

// Must be included last!
#include "run_get_on_types.h"

int main()
{
    for (int i = 0; i < 3; ++i)
    {
        std::cout << std::string(10, '-') << std::endl;
        std::cout << "Running get with i=" << i << std::endl;
        auto* find_type = run_get_on_types(i, list_of_types::type());
        if (find_type)
            find_type->pass_flags(i);
        else
            std::cout << "FOUND NO MATCH!!" << std::endl;
    }
    std::cout << std::string(10, '-') << std::endl;

    std::string dummy;
    std::getline(std::cin, dummy);

    return 0;
}