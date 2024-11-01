#pragma once

#include <ostream>
#include <string>

#include "LinkedIntNode.hpp"

/**
 * Main class for LinkedIntNode Operations
 */
class LinkedInt {
public:
    /**
     * Constructor for building instant string integers
     */
    LinkedInt(const std::string& newValue);

    /**
     * Constructor for single characters
     */
    LinkedInt(char newValue);

    LinkedInt();
    LinkedInt(const LinkedInt& newLinkedInt);
    LinkedInt(LinkedInt&& moveLinkedInt);
    ~LinkedInt();
    LinkedInt& operator=(const LinkedInt& newLinkedInt);
    LinkedInt& operator=(LinkedInt&& moveLinkedInt);

    /**
     * Operator for std::cout or std::stringstream
     */
    friend std::ostream& operator<<(std::ostream& os, const LinkedInt& linkedInt);

    /**
     * Operator for adding and assigning LinkedInts
     */
    LinkedInt& operator+=(const LinkedInt& newLinkedInt);

    /**
     * Operator for adding LinkedInts
     */
    friend LinkedInt operator+(LinkedInt left, const LinkedInt& right)
    {
        left += right;
        return left;
    }

private:
    LinkedIntNode* linkedIntNode;
};
