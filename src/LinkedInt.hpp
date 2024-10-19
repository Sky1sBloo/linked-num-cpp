#pragma once

#include <ostream>
#include <string>

#include "LinkedIntNode.hpp"


/**
 * Main class for LinkedIntNode Operations
 */
class LinkedInt
{
  public:
    /**
     * Constructor for building instant string integers
     */
    LinkedInt(const std::string &newValue);

    /**
     * Constructor for single characters
     */
    LinkedInt(char newValue);

    LinkedInt();
    LinkedInt(const LinkedInt &newLinkedInt);
    ~LinkedInt();

    LinkedInt &operator=(const LinkedInt &newLinkedInt);

    /**
     * Operator for std::cout or std::stringstream
     */
    friend std::ostream &operator<<(std::ostream &os, const LinkedInt &linkedInt);

    /**
     * Operator for appending
     */
    LinkedInt &operator+=(const LinkedInt &newLinkedInt);

    friend LinkedInt operator+(LinkedInt left, const LinkedInt &right)
    {
        left += right;
        return left;
    }

  private:
    LinkedIntNode *linkedIntNode;

    /**
     * Helper function that adds 2 characters of LinkedIntNodes
    */

};
