#include "LinkedInt.hpp"
#include "LinkedIntNode.hpp"

LinkedInt::LinkedInt(const std::string &newValue)
{
    LinkedIntNode *currentNode = linkedIntNode;
    for (char valuePlace: newValue)
    {
        currentNode->value = valuePlace;
        currentNode->next = new LinkedIntNode({valuePlace, nullptr});
        currentNode = currentNode->next;
    }
}

LinkedInt::LinkedInt(char newValue) : linkedIntNode(nullptr)
{
}


LinkedInt::~LinkedInt()
{
    LinkedIntNode *currentNode = linkedIntNode;
    while (currentNode != nullptr)
    {
        LinkedIntNode *next = currentNode->next;
        delete currentNode;
        currentNode = next;
    }
}


std::ostream &operator<<(std::ostream &os, LinkedInt &linkedInt)
{
    std::string linkedIntValue;
    LinkedIntNode *currentNode = linkedInt.linkedIntNode;
    while (currentNode != nullptr)
    {
        linkedIntValue.push_back(currentNode->value);
        currentNode = currentNode->next;
    }

    os << linkedIntValue;
    return os;
}
