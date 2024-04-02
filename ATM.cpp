#include "ATM.h"
#include "Iterator.h"

void ATM::afisare(TElem* elem, int* nrocc, int size)
{
    for (int i=0; i<size; i++)
    {
        cout<<elem[i]<<' '<<nrocc[i]<<endl;
    }
}

void ATM::solution(TElem* elem, int* nrocc, int size , int suma)
{
    int suma1 = 0,k=0;
    int nrocc1[200] ={0};
    TElem elem1[200];
    for(int i=0;i<size;i++)
    {
        if(suma1+elem[i]<=suma)
        {
            while (nrocc[i] and suma1 + elem[i] <= suma) {
                suma1 += elem[i];
                nrocc[i]--;
                nrocc1[k]++;
            }
            elem1[k] = elem[i];
            k++;
        }
    }
    if (suma1 == suma)
    {
        cout<<"trebuie sa introduci aceasta suma: "<<endl;
        for (int i=0; i < k; i++)
        {
            cout<<elem1[i]<<' '<<nrocc1[i]<<endl;
        }
    }
    else
    {
        cout<<"nu se poate efectua o tranzactie.";
    }
}































/*
    GENERAM SI AFISAM BACKTRACKING CU TOATE MODALITATILE DE PLATA
    ALEGE METODA DE PLATA CARE II PLACE LA BAROSAN
    GENERAM DIN NOU METODELE DE PLATA SI NE OPRIM LA CEA CU INDICELE ALES DE BAROSAN
    AFISAM METODA ALEASA SI GATA DU-TE DRACU

    SOLUTIE DE DESTEPTI
    vvvvvvvvvvvvvvvvvvv

    #include <iostream>
    #include <string>
    #include <unordered_map>

    using namespace std;

    void permute(string str, unordered_map<string, bool>& solutions, int l = 0, int r = -1)
    {
        if (r == -1)
        {
            r = str.length() - 1;
        }

        if (l == r) //toate bancnotele alese adunate fac suma
        {
            solutions[str] = true;
        }
        else
        {
            for (int i = l; i <= r; i++) //ne trebe inca un for pentru epuizarea nr de bancnote
            {
                swap(str[l], str[i]);
                permute(str, solutions, l + 1, r);
                swap(str[l], str[i]);
            }
        }
    }

    int main()
    {
        string str = "abc";
        unordered_map<string, bool> solutions;

        permute(str, solutions);

        cout << "Permutations of " << str << ":" << endl;
        for (const auto& [key, value] : solutions)
        {
            cout << key << endl;
        }

        return 0;
    }
 */