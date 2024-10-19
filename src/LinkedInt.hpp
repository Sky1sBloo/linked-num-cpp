#pragma once

#include <algorithm>
#include <ostream>
#include <string>

#include "LinkedIntNode.hpp"

/**
 * Main class for LinkedIntNode Operations
 */
class LinkedInt
{
  public:
    LinkedInt(const std::string &newValue);
    LinkedInt(char newValue);
    LinkedInt();

    LinkedInt(const LinkedInt& newLinkedInt);
    ~LinkedInt();

    friend std::ostream &operator<<(std::ostream &os, LinkedInt &linkedInt);

    friend LinkedInt operator+(const LinkedInt& left, const LinkedInt &right)
    {
        const LinkedIntNode *linkNodeA = left.linkedIntNode;
        const LinkedIntNode *linkNodeB = right.linkedIntNode;

        bool carryOne = false;
        std::string sumContainer;

        while (linkNodeA != nullptr || linkNodeB != nullptr || carryOne)
        {
            char valueA = linkNodeA ? linkNodeA->value : '0';
            char valueB = linkNodeB ? linkNodeB->value : '0';

            char answer = valueA + valueB - '0';

            if (carryOne)
            {
                answer += 1;
                carryOne = false;
            }

            if (answer > '9')
            {
                carryOne = true;
                answer = answer - 10;
            }

            sumContainer.push_back(answer);

            if (linkNodeA) linkNodeA = linkNodeA->next;
            if (linkNodeB) linkNodeB = linkNodeB->next;
        }

        std::reverse(sumContainer.begin(), sumContainer.end());
        return LinkedInt(sumContainer);
    }

  private:
    LinkedIntNode *linkedIntNode;
};
