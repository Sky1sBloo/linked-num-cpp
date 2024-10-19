#include "LinkedInt.hpp"

LinkedInt::LinkedInt(const std::string &newValue)
{
    LinkedInt *currentNode = this;
    for (char valuePlace: newValue)
    {
        currentNode->value = valuePlace;
        currentNode->nextLinkedInt = new LinkedInt(valuePlace);
        currentNode = currentNode->nextLinkedInt;
    }
}

LinkedInt::LinkedInt(char newValue) : value(newValue), nextLinkedInt(nullptr)
{
}


LinkedInt::~LinkedInt()
{
    if (nextLinkedInt != nullptr)
    {
        delete nextLinkedInt;
    }
}


std::ostream &operator<<(std::ostream &os, LinkedInt &linkedInt)
{
    std::string linkedIntValue;
    LinkedInt *currentNode = &linkedInt;
    while (currentNode != nullptr)
    {
        linkedIntValue.push_back(currentNode->value);
        currentNode = currentNode->nextLinkedInt;
    }

    os << linkedIntValue;
    return os;
}
