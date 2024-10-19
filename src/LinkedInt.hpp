#pragma once

#include <memory>
#include <string>

class LinkedInt
{
  public:
    LinkedInt(const std::string &newValue);
    LinkedInt(char newValue);

  private:
    char value;
    LinkedInt *nextLinkedInt;
};
