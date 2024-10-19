#include "LinkedInt.hpp"
#include "LinkedIntNode.hpp"
#include <algorithm>
#include <utility>

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

LinkedInt::LinkedInt() : linkedIntNode(nullptr)
{
}

LinkedInt::LinkedInt(const LinkedInt &newLinkedInt) : linkedIntNode(nullptr)
{
    LinkedIntNode *copyNode = newLinkedInt.linkedIntNode;
    LinkedIntNode *outputNode = nullptr;
    while (copyNode != nullptr)
    {
        LinkedIntNode *newNode = new LinkedIntNode({copyNode->value, nullptr});

        if (outputNode)
        {
            LinkedIntNode *currentOutputTraverse = outputNode;
            while (currentOutputTraverse->next != nullptr)
            {
                currentOutputTraverse = currentOutputTraverse->next;
            }
            currentOutputTraverse->next = newNode;
        }
        else
        {
            outputNode = newNode;
        }

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

LinkedInt &LinkedInt::operator=(const LinkedInt &newLinkedInt)
{
    LinkedInt copyLinkedInt(newLinkedInt);
    if (this != &newLinkedInt)
    {
        std::swap(*linkedIntNode, *copyLinkedInt.linkedIntNode);
    }

    return *this;
}

std::ostream &operator<<(std::ostream &os, const LinkedInt &linkedInt)
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

LinkedInt &LinkedInt::operator+=(const LinkedInt &newLinkedInt)
{
    LinkedIntNode *linkNodeA = linkedIntNode;
    const LinkedIntNode *linkNodeB = newLinkedInt.linkedIntNode;
    LinkedIntNode *storeCarry = nullptr; // Node for storing the last node to append a new carry

    bool carryOne = false;
    while (linkNodeB != nullptr || carryOne)
    {
        char valueA = linkNodeA ? linkNodeA->value : '0';
        char valueB = linkNodeB ? linkNodeB->value : '0';

        char answer = valueA + valueB - '0';

        if (carryOne)
        {
            answer += 1;
            carryOne = false;
        }

        if (answer > '9')
        {
            carryOne = true;
            answer = answer - 10;
        }

        if (linkNodeA)
        {
            linkNodeA->value = answer;

            if (!linkNodeA->next)
            {
                storeCarry = linkNodeA;
            }
            linkNodeA = linkNodeA->next;
        }
        else
        {
            storeCarry->next = new LinkedIntNode({answer, nullptr});
        }
        if (linkNodeB)
            linkNodeB = linkNodeB->next;
    }

    return *this;
}
