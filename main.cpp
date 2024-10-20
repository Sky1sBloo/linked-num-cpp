#include <cctype>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>

#include "LinkedInt.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Arguments too few\n"
                  << "Usage: linked-int-cpp [equation]\n"
                  << "Example: linked-int-cpp 1+2" << std::endl;
        return 1;
    }

    std::vector<LinkedInt> addends;

    // Used std::string for easier looping
    const std::string operation = argv[1];

    std::string numericals;
    for (char value : operation)
    {
        if (isdigit(value))
        {
            numericals.push_back(value);
        }
        else if (value == '+')
        {
            addends.emplace_back(numericals);
            numericals.clear();
        }
        else if (value != ' ')
        {
            std::cerr << "Unknown value: " << value << std::endl;
            return 1;
        }
    }

    addends.emplace_back(numericals);

    const LinkedInt sum = std::accumulate(addends.begin(), addends.end(), LinkedInt('0'));
    std::cout << sum << std::endl;

    return 0;
}
