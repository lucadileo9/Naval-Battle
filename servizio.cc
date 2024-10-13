#include "dati.h"
#include "servizio.h"

#include <iostream>
using namespace std;


void stampa_griglia(char griglia[][MAX_LUN])
{
    cout<<endl;
    for(int i=0;i<MAX_LUN;i++)
        {
            for(int j=0;j<MAX_LUN;j++)
                cout<<griglia[i][j];
            cout<<endl;
        }
}

void tracing (giocatore_t &g)
{
    cout<<"Questa è la griglia di "<<g.nome<<endl;
    stampa_griglia(g.griglia_propria);

    cout<<"Questa è la griglia avversaria che "<<g.nome<<" vede: "<<endl;
    stampa_griglia(g.griglia_avversaria);
}
