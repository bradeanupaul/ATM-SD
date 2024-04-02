
#include "tranzactie.h"
#include "Iterator.h"
#include <iostream>

using namespace std;

void Tranzactie::add(int id, TElem s, Collection c)
{
    this->idTranzactie = id;
    this->suma = s;
    this->collection = c;
}

int Tranzactie::getID()
{
    return this->idTranzactie;
}

int Tranzactie::getSuma()
{
    return this->suma;
}

void Tranzactie::orderCollection()
{
    int lungime = this->collection.size();
    for (int i = 0; i < lungime - 1; i++)
        for(int j = i + 1; j < lungime; j++)
        {
            if (this->collection.elements[i] < this->collection.elements[j])
            {
                swap(this->collection.elements[i], this->collection.elements[j]);
                swap(this->collection.occurrences[i], this->collection.occurrences[j]);
            }
        }
}

void Tranzactie::getCollection()
{
    Iterator it(this->collection);
    while(it.valid())
    {
        cout<< it.current() <<" "<< it.getCurrentOccurrences() << endl;
        it.next();
    }
}


