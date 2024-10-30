#pragma once

/**
 * Holder of linked integer list
 */
struct LinkedIntNode {
    char value;
    LinkedIntNode* next;
};

/**
 * Helper struct for adding LinkedIntNode
 */
struct CharAddition {
    char value;
    bool isCarry;
};

/**
 * Adds two linkNode characters
 *
 * @param linkNodeA, linkNodeB values to be added
 * @param isCarry If true, adds one to the sum
 *
 * @return Struct of CharAddition containing the sum and the carry
 */
CharAddition addChar(const LinkedIntNode* linkNodeA, const LinkedIntNode* linkNodeB, bool isCarry);
