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
    LinkedInt *currentNode = this;
    while (currentNode != nullptr)
    {
        LinkedInt *next = currentNode;
        delete currentNode;
        currentNode = next;
    }
}


std::ostream &operator<<(std::ostream &os, const LinkedInt &linkedInt)
{
    os << linkedInt.value;
    return os;
}
