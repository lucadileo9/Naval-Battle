#include <stdlib.h>
#include <cstring>

#include <iostream>
using namespace std;

#include "dati.h"
#include "gioco.h"
#include "servizio.h"
#include "inserimento.h"

/**
 * @brief Executes a shot in the battleship game and updates the game state.
 * 
 * @param x The x-coordinate of the shot.
 * @param y The y-coordinate of the shot.
 * @param verifica A matrix representing the verification grid.
 * @param mod A matrix representing the modification grid.
 * @param shot A reference to the shot counter, which will be updated if the shot is successful.
 * @return true If the shot hits a target.
 * @return false If the shot misses.
 */
bool tiro(int x, int y, const char verifica [][MAX_LUN], char mod [][MAX_LUN], int& shot)
{
    if (verifica[x][y] == '0')
    {
        shot = shot +25;
        mod[x][y] = 'X';
        return true;
    }
    else
        mod[x][y] = 'A';
    return false;
}

/**
 * @brief Converts a character coordinate to an integer.
 *
 * This function takes a character representing a coordinate (typically a letter)
 * and converts it to its corresponding integer value. The conversion is based on
 * the assumption that the input character is a lowercase letter from 'a' to 'j'.
 *
 * @param x The character coordinate to be converted.
 * @return The integer value corresponding to the character coordinate.
 *         Returns 0 if the character is not within the expected range.
 */
int converti_coo (char x)
{
    for(int i = 0; i < 11; i++)
    {
        if( i == static_cast<int>(x - ('a'- 1)))
            return i;
    }
    return 0;
}

/**
 * @brief Esegue il turno di un giocatore nel gioco della battaglia navale.
 * 
 * Questa funzione gestisce il turno di un giocatore, mostrando le griglie di gioco,
 * chiedendo le coordinate del tiro e aggiornando lo stato del gioco in base al risultato del tiro.
 * 
 * @param g1 Riferimento al giocatore che sta effettuando il turno.
 * @param g2 Riferimento al giocatore avversario.
 */
void turno (giocatore_t &g1, giocatore_t &g2)
{
    cout<<"TURNO GIOCATORE:"<<g1.nome<<endl;
    cout<<"Questa è la tua griglia:";
    stampa_griglia(g1.griglia_propria);
    system("sleep 3");
    cout<<"Questa è la griglia del tuo avversario:";
    stampa_griglia(g1.griglia_avversaria);
    system("sleep 3");
    int x,y;
    char c;
    cout<<"Inserisci qui le coordinate della zona che vuoi colpire: "; cin>>c; cin>>y;
    x = converti_coo(c);
    if (tiro(x,y, g2.griglia_propria, g1.griglia_avversaria, g1.punteggio) )
        cout<<"Hai colpito il bersaglio, complimenti"<<endl;
    else 
        cout<<"Acqua\n";  
}

/**
 * @brief Converts a user's response to an integer code.
 *
 * This function takes a user's response in the form of a string and converts it to an integer code.
 * The conversion is based on the following rules:
 * - If the response is "si", the function returns 1.
 * - If the response is "no", the function returns 2.
 * - For any other response, the function returns 3.
 *
 * @param risp A character array containing the user's response. It is expected to be a null-terminated string.
 * @return An integer code representing the user's response:
 *         - 1 if the response is "si"
 *         - 2 if the response is "no"
 *         - 3 for any other response
 */
int converti_scelta (char risp[3])
{
    if(strcmp (risp, "si") == 0)
        return 1;
    if (strcmp (risp, "no") == 0 )
        return 2;
    else 
        return 3;
}

/**
 * @brief Executes a series of turns for two players in a battleship game.
 * 
 * This function initializes the grids for both players, places their ships,
 * and then alternates turns between the two players for a specified number of turns.
 * If a player sinks all the opponent's ships, the game ends and declares the winner.
 * If the number of turns is exhausted, the player with the highest score is declared the winner.
 * 
 * @param g1 Reference to the first player.
 * @param g2 Reference to the second player.
 * @param quan The number of turns to be played.
 */
void turni_vari (giocatore_t & g1, giocatore_t & g2, const int quan)
{
    inizializza_griglia(g1.griglia_propria);
    inizializza_griglia(g2.griglia_propria);
    inserisci_navi(g1.griglia_propria);
    inserisci_navi(g2.griglia_propria);
    inizializza_griglia(g1.griglia_avversaria);
    inizializza_griglia(g2.griglia_avversaria);

    for(int i = 0; i < quan; i++)
    {
        turno(g1, g2);
        system("sleep 6");
        turno(g2, g1);
        system("sleep 6");
        if(g1.punteggio == (quante1 *25 + quante2 *25 + quante3 *25 +quante4 *25 ) )
        {
            cout<<"Il giocatore "<<g1.nome<<" ha vinto, affondando tutte le navi, complimenti\n";
            return;            
        }
        if(g2.punteggio == (quante1 *25 + quante2 *25 + quante3 *25 +quante4 *25 ) )
        {
            cout<<"Il giocatore "<<g2.nome<<" ha vinto, affondando tutte le navi, complimenti\n";
            return;            
        }
    }

    cout<<"Il numero di turni è finito, il giocatore ad aver eseguito un punteggio " 
    "più alto e quindi ad aver vinto è ";
    if(g1.punteggio > g2.punteggio)
        cout<<g1.nome<<" con la bellezza di "<<g1.punteggio<<" punti\n";
    if(g2.punteggio > g1.punteggio)
        cout<<g2.nome<<" con la bellezza di "<<g2.punteggio<<" punti\n";
    if(g1.punteggio == g2.punteggio)
        cout<<"Lo sport, poichè la partita è finita in pareggio\n";
}

/**
 * @brief Initializes the game grids for two players, allows modification of the winning score, 
 *        and manages the game turns until one player reaches the winning score.
 * 
 * @param g1 Reference to the first player.
 * @param g2 Reference to the second player.
 * 
 * This function performs the following steps:
 * 1. Initializes the grids for both players.
 * 2. Inserts ships into the players' grids.
 * 3. Prompts the user to modify the winning score if desired.
 * 4. Alternates turns between the two players until one of them reaches the winning score.
 * 5. Declares the winner based on the scores.
 */
void max_punt (giocatore_t & g1, giocatore_t & g2)
{
    inizializza_griglia(g1.griglia_propria);
    inizializza_griglia(g2.griglia_propria);
    inserisci_navi(g1.griglia_propria);
    inserisci_navi(g2.griglia_propria);
    inizializza_griglia(g1.griglia_avversaria);
    inizializza_griglia(g2.griglia_avversaria);
    
    char risp [3];
    cout<<"Attualmente questo è il numero di punti per questa vincere:"
    <<PUN<<" Vuoi modificarlo? ";
    cin>>risp;
    int scelta = converti_scelta(risp);
    switch (scelta)
    {
    case 1:
        {
            cout<<"Inserisci il nuovo valore dei turni: ";
            cin>>PUN;
        }
    case 2:
        cout<<"Okay allora possiamo inizare\n";
        break;
    default:
        cout<<"Valore non accettabile\n";
        break;
    }
    while (g1.punteggio < PUN && g2.punteggio < PUN )
    {
        turno(g1, g2);
        system("sleep 6");
        turno(g2, g1);
        system("sleep 6");
    }

    cout<<"Il punteggio massimo è stato raggiunto, il giocatore ad aver vinto è ";
    if(g1.punteggio >= PUN)
        cout<<g1.nome<<" con la bellezza di "<<g1.punteggio<<" punti\n";
    if(g2.punteggio >= PUN)
        cout<<g2.nome<<" con la bellezza di "<<g2.punteggio<<" punti\n";
}

/**
 * @brief Stampa la quantità di navi di diverse dimensioni.
 *
 * Questa funzione stampa sullo standard output la quantità di navi di 
 * dimensioni 1, 2, 3 e 4 presenti nel gioco.
 */
void stampa_quantita ()
{
    cout<<"Navi da 1: "<<quante1<<endl
    <<"Navi da 2: "<<quante2<<endl
    <<"Navi da 3: "<<quante3<<endl
    <<"Navi da 4: "<<quante4<<endl;
}

/**
 * @brief Modifies the quantity of ships of different sizes.
 * 
 * This function prompts the user to input new values for the quantities of ships
 * of sizes 1, 2, 3, and 4. The new values are stored in the variables `quante1`, 
 * `quante2`, `quante3`, and `quante4` respectively.
 * 
 * @note Ensure that the variables `quante1`, `quante2`, `quante3`, and `quante4` 
 * are declared and accessible in the scope where this function is called.
 */
void modifica_quantita ()
{
    cout<<"Nuovo valore navi da 1: "; cin>>quante1;
    cout<<"Nuovo valore navi da 2: "; cin>>quante2;
    cout<<"Nuovo valore navi da 3: "; cin>>quante3;
    cout<<"Nuovo valore navi da 4: "; cin>>quante4;
}