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
    LinkedInt(const std::string &newValue);
    LinkedInt(char newValue);
    LinkedInt();
    ~LinkedInt();

    friend std::ostream &operator<<(std::ostream &os, LinkedInt &linkedInt);


  private:
    LinkedIntNode *linkedIntNode;
};
