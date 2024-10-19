#include <iostream>
#include <string>

#include "LinkedInt.hpp"

int main()
{
    LinkedInt left("99");
    LinkedInt right("21");
    LinkedInt righter("50");
    LinkedInt righest("999");


    LinkedInt sum = left + right + righter + righest;

    std::cout << sum << std::endl;
}
