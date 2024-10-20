#include <cctype>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>

#include "LinkedInt.hpp"

int main(int argc, char **argv)
{
    /*
    if (argc < 2)
    {
        std::cerr << "Arguments too few" << std::endl;
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
        if (value == '+')
        {
            addends.emplace_back(numericals);
            numericals.clear();
        }
    }
    
    addends.emplace_back(numericals);

    const LinkedInt sum = std::accumulate(addends.begin(), addends.end(), LinkedInt('0'));
    std::cout << sum << std::endl;
    */
    LinkedInt first("5");
    LinkedInt second("20009");

    LinkedInt sum(first + second);
    std::cout << sum << std::endl;
}
