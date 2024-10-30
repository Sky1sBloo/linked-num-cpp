#include <cctype>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>

#include "LinkedInt.hpp"

int main(int argc, char** argv)
{
    if (argc < 2) {
        std::cerr << "Arguments too few\n"
                  << "Usage: linked-int-cpp [equation]\n"
                  << "Example: linked-int-cpp 1+2" << std::endl;
        return 1;
    }

    // To support spaces
    std::string operation;
    for (int i = 1; i < argc; i++) {
        operation += argv[i];
    }

    std::vector<LinkedInt> addends;
    std::string numericals; // To support values more than 9
    bool prevIsOperation = false; // To check for trailing operations
    for (char value : operation) {
        if (std::isdigit(value)) {
            numericals.push_back(value);
            prevIsOperation = false;
        } else if (value == '+') {
            if (prevIsOperation) {
                std::cerr << "Trailing operation: " << value << std::endl;
                return 1;
            }
            addends.emplace_back(numericals);
            numericals.clear();
            prevIsOperation = true;
        } else if (value != ' ') {
            std::cerr << "Unknown value: " << value << std::endl;
            return 1;
        }
    }

    addends.emplace_back(numericals);

    const LinkedInt sum = std::accumulate(addends.begin(), addends.end(), LinkedInt('0'));
    std::cout << sum << std::endl;

    return 0;
}
