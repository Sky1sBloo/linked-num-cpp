#pragma once

#include <memory>
class LinkedInt
{
private:
    char value;
    std::unique_ptr<LinkedInt> next;
};
