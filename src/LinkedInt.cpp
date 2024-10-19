#include "LinkedInt.hpp"
#include "LinkedIntNode.hpp"
#include <algorithm>

LinkedInt::LinkedInt(const std::string &newValue)
{
    LinkedIntNode *prevNode = nullptr;
    for (char valuePlace : newValue)
    {
        LinkedIntNode *newNode = new LinkedIntNode({valuePlace, prevNode});
        prevNode = newNode;
    }

    linkedIntNode = prevNode;
}

LinkedInt::LinkedInt(char newValue)
{
    linkedIntNode = new LinkedIntNode({newValue, nullptr});
}

LinkedInt::LinkedInt() :
    linkedIntNode(nullptr)
{
}

LinkedInt::LinkedInt(const LinkedInt& newLinkedInt) : linkedIntNode(nullptr)
{
    LinkedIntNode *copyNode = newLinkedInt.linkedIntNode;
    LinkedIntNode *outputNode = nullptr;
    while (copyNode != nullptr)
    {
        LinkedIntNode *newNode = new LinkedIntNode({copyNode->value, nullptr});
        newNode->next = outputNode;
        outputNode = newNode;
        
        copyNode = copyNode->next;
    }

    linkedIntNode = outputNode;
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
        linkedIntValue += currentNode->value;
        currentNode = currentNode->next;
    }
    std::reverse(linkedIntValue.begin(), linkedIntValue.end());

    os << linkedIntValue;
    return os;
}

