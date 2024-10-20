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
    while (copyNode)
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
    while (currentNode)
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
        CharAddition answer = addChar(linkNodeA, linkNodeB, carryOne);
        carryOne = answer.isCarry;

        if (linkNodeA)
        {
            linkNodeA->value = answer.value;

            if (!linkNodeA->next)
            {
                storeCarry = linkNodeA;
            }
            linkNodeA = linkNodeA->next;
        }
        else if (!storeCarry)
        {
            storeCarry->next = new LinkedIntNode({answer.value, nullptr});
        }

        if (linkNodeB)
        {
            linkNodeB = linkNodeB->next;
        }
    }

    return *this;
}

