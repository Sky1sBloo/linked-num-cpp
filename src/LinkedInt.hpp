#pragma once

#include <ostream>
#include <string>

class LinkedInt
{
  public:
    LinkedInt(const std::string &newValue);
    LinkedInt(char newValue);

    friend std::ostream &operator<<(std::ostream &os, const LinkedInt &linkedInt);

    ~LinkedInt();

  private:
    char value;
    LinkedInt *nextLinkedInt;
};
