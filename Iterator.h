#pragma once
#include "colectie.h"

class Iterator
{
private:
    Collection collection;
    int position;
public:
    Iterator(Collection c);
    bool valid();
    void first();
    void next();
    int current();
    int getCurrentOccurrences();
};