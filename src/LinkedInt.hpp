#pragma once

#include <ostream>
#include <string>

class LinkedInt
{
  public:
    LinkedInt(const std::string &newValue);
    LinkedInt(char newValue);
    ~LinkedInt();

    friend std::ostream &operator<<(std::ostream &os, LinkedInt &linkedInt);


  private:
    char value;
    LinkedInt *nextLinkedInt;
};
