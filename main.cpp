#include <iostream>

#include "LinkedInt.hpp"

int main()
{
    LinkedInt left("10");
    LinkedInt right("2");
    LinkedInt sum = left + right;
    std::cout << sum << std::endl;
}
