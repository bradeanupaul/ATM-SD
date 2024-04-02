#pragma once
#include "colectie.h"

class Tranzactie
{
private:
    int idTranzactie;
    int suma;
    Collection collection;
public:
    void add(int, int, Collection);
    int getID();
    int getSuma();
    void orderCollection();
};