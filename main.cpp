#include <iostream>

#include "LinkedInt.hpp"

int main()
{
    LinkedInt left("99");
    LinkedInt copyLeft = left;

    std::cout << copyLeft << std::endl;
}
