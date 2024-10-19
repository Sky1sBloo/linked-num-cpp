#include "LinkedInt.hpp"

LinkedInt::LinkedInt(const std::string &newValue)
{
    LinkedInt *currentNode = this;
    for (char valuePlace: newValue)
    {
        currentNode->value = valuePlace;
    }
}

LinkedInt::LinkedInt(char newValue) : value(newValue), nextLinkedInt(nullptr)
{
}
