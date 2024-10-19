#include "LinkedInt.hpp"

LinkedInt::LinkedInt(const std::string& newValue) 
{
    for (char place : newValue)
    {
        nextLinkedInt = std::make_unique<LinkedInt>(newValue);
    }
}

LinkedInt::LinkedInt(char newValue) :
    value(newValue)
{
}
