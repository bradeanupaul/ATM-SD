#include "colectie.h"

Collection::Collection()
{
    elements = new TElem[5];
    //elements[0] = 1;
    //elements[1] = 5;
    //elements[2] = 10;
    occurrences = new int[5];
    //occurrences[0] = 5;
    //occurrences[1] = 3;
    //occurrences[2] = 2;
    distinctelements = 0;
    capacity = 5;
}

void Collection::add(TElem elem)
{
    bool exist = false;
    int position;
    for(int i=0; i<distinctelements; i++)
        if(elem == elements[i])
        {
            exist = true;
            position = i;
        }
    if(exist)
        occurrences[position] = occurrences[position] + 1;
    else
    {
        if(distinctelements + 1 > capacity)
        {
            capacity *= 2;
            TElem *tmp = new TElem[capacity];
            for(int i=0; i<distinctelements; ++i)
                tmp[i] = elements[i];
            delete[] elements;
            elements = tmp;
            int *tmp2 = new int[capacity];
            for(int i=0; i<distinctelements; ++i)
                tmp2[i] = occurrences[i];
            delete[] occurrences;
            occurrences = tmp2;
        }
        elements[distinctelements] = elem;
        occurrences[distinctelements] = 1;
        distinctelements++;
    }
}

bool Collection::remove(TElem elem)
{
    bool exist = false;
    int position;
    for(int i=0; i<distinctelements; i++)
        if(elem == elements[i])
        {
            exist = true;
            position = i;
        }
    if(exist)
    {
        if(occurrences[position] > 1)
            occurrences[position]--;
        else
        {
            for(int i=position; i<distinctelements-1; i++)
            {
                elements[i] = elements[i+1];
                occurrences[i] = occurrences[i+1];
            }
            distinctelements--;
        }
        return true;
    }
    return false;
}

bool Collection::search(TElem elem)
{
    for(int i=0; i<distinctelements; i++)
        if(elements[i] == elem)
            return true;
    return false;
}

int Collection::size()
{
    return distinctelements;
}

int Collection::nroccurrences(TElem elem)
{
    for(int i=0; i<distinctelements; i++)
        if(elements[i] == elem)
            return occurrences[i];
    return 0;
}

void Collection::destroy()
{
    delete[] elements;
    delete[] occurrences;
    distinctelements = 0;
}

int Collection::getAt(int position)
{
    return elements[position];
}

