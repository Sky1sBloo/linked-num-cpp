#include "LinkedIntNode.hpp"

static CharAddition addChar(const LinkedIntNode *linkNodeA, const LinkedIntNode *linkNodeB, bool isCarry)
{
    char valueA = linkNodeA ? linkNodeA->value : '0';
    char valueB = linkNodeB ? linkNodeB->value : '0';

    char answer = valueA + valueB - '0';

    if (isCarry)
    {
        answer += 1;
        isCarry = false;
    }

    if (answer > '9')
    {
        isCarry = true;
        answer = answer - 10;
    }

    return CharAddition({answer, isCarry});
}
