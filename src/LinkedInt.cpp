#include "LinkedInt.hpp"
#include "LinkedIntNode.hpp"

LinkedInt::LinkedInt(const std::string &newValue)
{
    linkedIntNode = new LinkedIntNode({newValue[0], nullptr});
    LinkedIntNode *currentNode = linkedIntNode->next;

    for (int i = 1; i < newValue.size(); i++)
    {
        currentNode = new LinkedIntNode({newValue[i], nullptr});
        currentNode = currentNode->next;
    }
}

LinkedInt::LinkedInt(char newValue) 
{
    linkedIntNode = new LinkedIntNode({newValue, nullptr});
}

LinkedInt::~LinkedInt()
{
    LinkedIntNode *currentNode = linkedIntNode;
    while (currentNode != nullptr)
    {
        LinkedIntNode *nextNode = currentNode->next;
        delete currentNode;
        currentNode = nextNode;
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
