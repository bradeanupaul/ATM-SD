#pragma once
typedef int TElem;
class Collection
{
private:
    int distinctelements;
    int capacity;
public:
    TElem* elements;
    int* occurrences;
    Collection();
    void add(TElem elem);
    bool remove(TElem elem);
    bool search(TElem elem);
    int size();
    int nroccurrences(TElem elem);
    void destroy();
    int getAt(int position);
};

