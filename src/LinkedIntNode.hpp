#pragma once

/**
 * Holder of linked integer list
 */
struct LinkedIntNode
{
    char value;
    LinkedIntNode *next;
};

/**
 * Helper struct for adding LinkedIntNode
 */
struct CharAddition
{
    char value;
    bool isCarry;
};

static CharAddition addChar(const LinkedIntNode *linkNodeA, const LinkedIntNode *linkNodeB, bool isCarry);
