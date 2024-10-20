#include <iostream>

#include "LinkedInt.hpp"

int main()
{
    LinkedInt valueA("99");
    LinkedInt valueB("21");
    LinkedInt valueC("33");

    LinkedInt sum = valueA + valueB + valueC;

    std::cout << "Sum = " << sum << std::endl;
}
