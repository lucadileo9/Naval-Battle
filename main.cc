#include <iostream>
using namespace std;

#include "dati.h"
#include "inserimento.h"
#include "servizio.h"
#include "gioco.h"


int main()
{
    const char menu [] =
    "Scegli a quale funzionalità attivare;\n"
    "1) Turni limitati\n"
    "2) Punteggio massimo raggiunto\n"
    "3) Classica\n"
    "4) Mostra quantità navi\n"
    "5) Modifica quanità navi\n"
    "6) Esci";

    cout<<"Benvenuto in uno dei giochi più famosi al mondo: BATTAGLIA NAVALE\n"
    <<"Per prima cosa vorrei sapere con chi sto giocando.\n";
    giocatore_t player_one;
    inizializza_giocatore(player_one);
   // tracing(player_one);

    giocatore_t player_two;
    inizializza_giocatore(player_two);
    //tracing(player_two);

    while (true)
    {
        cout<<menu<<endl;
        int scelta;
        cin>>scelta;
        switch (scelta)
        {
        case 1:
            {
                char risp [3];
                cout<<"Attualmente questo è il numero di turni per questa modalità:"
                <<num_turni<<" Vuoi modificarlo? ";
                cin>>risp;
                int scelta =converti_scelta(risp);
                switch (scelta)
                {
                    case 1:
                    {       
                        cout<<"Inserisci il nuovo valore dei turni: ";
                        cin>>num_turni;
                    }
                    case 2:
                        cout<<"Okay allora possiamo inizare\n";
                        break;
                    default:
                        cout<<"Valore non accettabile\n";
                        break;
                }
                turni_vari(player_one, player_two, num_turni);
                }
            break;
        case 2:
            max_punt(player_one, player_two);
            break;
        case 3:
            turni_vari(player_one, player_two, 1000);
            break;
        case 4:
            stampa_quantita();
            break;
        case 5:
            modifica_quantita();
            break;
        case 6:
            return 0;
        default:
            cout<<"Valore non accettabile\n";
            break;
        }
    }

}