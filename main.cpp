#include <iostream>
#include <string>

#include "LinkedInt.hpp"

int main()
{
    LinkedInt left("99");
    LinkedInt right("21");

    right = left;

    std::cout << right << " : " << left << std::endl;


}
