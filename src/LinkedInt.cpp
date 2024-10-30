#include "LinkedInt.hpp"
#include "LinkedIntNode.hpp"
#include <algorithm>
#include <utility>

LinkedInt::LinkedInt(const std::string& newValue)
{
    LinkedIntNode* currentNode = nullptr;
    linkedIntNode = currentNode;
    for (char valuePlace : newValue) {
        currentNode = new LinkedIntNode({valuePlace, nullptr});
        currentNode = currentNode->next;
    }
}

LinkedInt::LinkedInt(char newValue)
{
    linkedIntNode = new LinkedIntNode({ newValue, nullptr });
}

LinkedInt::LinkedInt()
    : linkedIntNode(nullptr)
{
}

LinkedInt::LinkedInt(const LinkedInt& newLinkedInt)
    : linkedIntNode(nullptr)
{
    LinkedIntNode* copyNode = newLinkedInt.linkedIntNode;
    LinkedIntNode* outputNode = nullptr;
    while (copyNode) {
        LinkedIntNode* newNode = new LinkedIntNode({ copyNode->value, nullptr });

        if (outputNode) {
            LinkedIntNode* currentOutputTraverse = outputNode;
            while (currentOutputTraverse->next != nullptr) {
                currentOutputTraverse = currentOutputTraverse->next;
            }
            currentOutputTraverse->next = newNode;
        } else {
            outputNode = newNode;
        }

        copyNode = copyNode->next;
    }

    linkedIntNode = outputNode;
}

LinkedInt::LinkedInt(LinkedInt&& moveLinkedInt)
    : linkedIntNode(std::exchange(moveLinkedInt.linkedIntNode, nullptr))
{
}

LinkedInt::~LinkedInt()
{
    LinkedIntNode* currentNode = linkedIntNode;
    while (currentNode) {
        LinkedIntNode* nextNode = currentNode->next;
        delete currentNode;
        currentNode = nextNode;
    }
}

LinkedInt& LinkedInt::operator=(const LinkedInt& newLinkedInt)
{
    LinkedInt copyLinkedInt(newLinkedInt);
    if (this != &newLinkedInt) {
        std::swap(*linkedIntNode, *copyLinkedInt.linkedIntNode);
    }

    return *this;
}

LinkedInt& LinkedInt::operator=(LinkedInt&& moveLinkedInt)
{
    LinkedInt temp(std::move(moveLinkedInt));
    std::swap(linkedIntNode, temp.linkedIntNode);
    return *this;
}

std::ostream& operator<<(std::ostream& os, const LinkedInt& linkedInt)
{
    std::string linkedIntValue;
    LinkedIntNode* currentNode = linkedInt.linkedIntNode;
    while (currentNode) {
        linkedIntValue += currentNode->value;
        currentNode = currentNode->next;
    }
    std::reverse(linkedIntValue.begin(), linkedIntValue.end());

    os << linkedIntValue;
    return os;
}

LinkedInt& LinkedInt::operator+=(const LinkedInt& newLinkedInt)
{
    LinkedIntNode* owner = linkedIntNode;
    const LinkedIntNode* toAdd = newLinkedInt.linkedIntNode;

    bool isCarry = false;

    while (toAdd != nullptr || isCarry) {
        CharAddition answer = addChar(owner, toAdd, isCarry);
        isCarry = answer.isCarry;

        if (owner) {
            owner->value = answer.value;
            linkedIntNode = owner;
            owner = owner->next;
        } else {
            owner = new LinkedIntNode({answer.value, owner});
            owner = owner->next;
        }
        if (toAdd)
            toAdd = toAdd->next;
    }
    /*
    LinkedIntNode* linkNodeA = linkedIntNode;
    const LinkedIntNode* linkNodeB = newLinkedInt.linkedIntNode;
    LinkedIntNode* storeCarry = nullptr; // Node for storing the last node to append a new carry
    LinkedIntNode* storeCarryCurrent = storeCarry;

    bool carryOne = false;
    while (linkNodeB != nullptr || carryOne) {
        CharAddition answer = addChar(linkNodeA, linkNodeB, carryOne);
        carryOne = answer.isCarry;

        if (linkNodeA) {
            linkNodeA->value = answer.value;

            if (!linkNodeA->next) {
                storeCarry = linkNodeA;
            }
            linkNodeA = linkNodeA->next;
        } else {
            if (storeCarryCurrent) {
                storeCarryCurrent->next = new LinkedIntNode({ answer.value, nullptr });
            } else {
                storeCarryCurrent = new LinkedIntNode({ answer.value, nullptr });
            }
            storeCarryCurrent = storeCarryCurrent->next;
        }

        linkNodeB = linkNodeB->next;
    }

    while (storeCarry) {
        linkNodeA = storeCarry;
        linkNodeA = storeCarry->next;
        storeCarry = storeCarry->next;
    } */

    return *this;
}
