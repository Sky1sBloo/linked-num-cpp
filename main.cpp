#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>

#include "LinkedInt.hpp"

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Arguments too few" << std::endl;
    }

    std::vector<LinkedInt> values;

    for (int i = 1; i < argc; i++)
    {
        bool isAddition = strcmp(argv[i], "+") == 0;

        if (!isAddition)
        {
            values.emplace_back(argv[i]);
        }
    }
    
    LinkedInt sum = std::accumulate(values.begin(), values.end(), LinkedInt('0'));
    std::cout << sum << std::endl;
}
