#include <iostream>
#include "colectie.h"
#include "iterator.h"
#include "tranzactie.h"
#include "ATM.h"

using namespace std;
int x, id, suma, k;
int * nrocc = new int[20];
TElem * elem = new int[20];
Collection c;
Tranzactie t1;
ATM a;
void menu()
{
    cout<<endl<<"1. adaugare tanzactie.\n"
                "2. afisare tranzactie.\n"
                "x. inchidere program"<<endl;
}
void run_menu()
{
    char s;
    while(s!='x')
    {
        menu();
        cout<<"optiunea dorita: ";
        cin>>s;
        cout<<endl;
        switch(s)
        {
            case '1':
            {
                cout<<"introdu id tranzactiei: ";
                cin>>id;
                cout<<"introdu suma tranzactiei: ";
                cin>>suma;
                cout<<"introdu numarul de bancnote: ";
                cin>>k;
                while(k)
                {
                    cout<<"introdu valoarea bancnotei: ";
                    cin>>x;
                    c.add(x);
                    k--;
                }
                t1.add(id, suma, c);
                break;
            }
            case '2':
            {
                cout<<"id tranzactie: "<<t1.getID()<<endl;
                cout<<"suma tranzactie: "<<t1.getSuma()<<" "<<endl;
                t1.orderCollection();
                //t1.getCollection();
                cout<<"bancnotele introduse sunt: "<<endl;
                a.afisare(c.elements,c.occurrences,c.size());
                a.solution(c.elements,c.occurrences,c.size(),t1.getSuma());
                break;
            }
            case 'x':
            {
                return;
            }
            default:
            {
                cout<<"optiune gresita!"<<endl;
            }
        }
    }
}