#include <iostream>
#include <string>

#include "LinkedInt.hpp"

int main()
{
    LinkedInt valueA("99");
    LinkedInt valueB("21");
    LinkedInt valueC("33");

    LinkedInt sum = valueA + valueB + valueC;

    {
        // Scope to test destructor test from copy
        LinkedInt valueD(valueA);
        LinkedInt valueE('2');
        valueE = valueC;

        std::cout << "ValueD = " << valueD << " ValueE = "<< valueE << '\n';
    }

    std::cout << "ValueA = " << valueA << " ValueC = " << valueC << " Sum = " << sum << std::endl;
}
