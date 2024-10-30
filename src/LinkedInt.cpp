#include "LinkedInt.hpp"
#include "LinkedIntNode.hpp"
#include <algorithm>
#include <utility>

LinkedInt::LinkedInt(const std::string& newValue)
{
    for (char valuePlace : newValue) {
        if (linkedIntNode) {
            LinkedIntNode* prev = linkedIntNode;
            linkedIntNode = linkedIntNode->next;
            linkedIntNode = new LinkedIntNode({ valuePlace, prev });
        } else {
            linkedIntNode = new LinkedIntNode({ valuePlace, nullptr });
        }
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

            // When the first value is too small
            if (owner->next == nullptr && (toAdd->next != nullptr || isCarry)) {
                owner->next = new LinkedIntNode({ '0', nullptr });
            }
            owner = owner->next;
        } else {
            owner = new LinkedIntNode({ answer.value, nullptr });
            owner = owner->next;
        }

        if (toAdd) {
            toAdd = toAdd->next;
        }
    }
    return *this;
}
