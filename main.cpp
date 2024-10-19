#include <iostream>

#include "LinkedInt.hpp"

int main()
{
    LinkedInt left("99");
    LinkedInt right("21");

    LinkedInt sum = left + right ;

    std::cout << sum << std::endl;
}
