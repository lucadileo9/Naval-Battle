#include "dati.h"
#include "inserimento.h"

#include <stdlib.h>
#include <ctime>

#include <iostream>
using namespace std;

/**
 * @brief Inserisce navi di una cella in una griglia di battaglia navale.
 *
 * Questa funzione posiziona un numero specificato di navi di una cella in una griglia di battaglia navale.
 * Le navi vengono posizionate in celle vuote (' ') della griglia, rappresentate dal carattere '0'.
 * Se una cella casuale è già occupata, la funzione riprova fino a trovare una cella vuota.
 *
 * @param griglia La griglia di battaglia navale rappresentata come un array bidimensionale di caratteri.
 *
 * @note La funzione utilizza la funzione srand(time(0)) per inizializzare il generatore di numeri casuali.
 *       Tuttavia, questa inizializzazione all'interno del ciclo for può causare problemi di casualità.
 *       È consigliabile spostare srand(time(0)) all'esterno della funzione o del ciclo.
 */
void inserisci_navi_1_cella(char griglia[][MAX_LUN] )
{
    //cout<<" fun navi 1 cella attivata\n";
    int casuale_1, casuale_2;
    for(int i = 0; i< quante1; i++)  //aggiunge le navi da 1 cella
    {
        srand(time(0));
        casuale_1 = (   (rand()%10)   +1);
        casuale_2 = (   (rand()%10)   +1);
        if (griglia[casuale_1][casuale_2] == ' ')
            {
                griglia[casuale_1][casuale_2]= '0';
               // cout<<i+1<<"° nave inserita\n";
            }
        else
            i--;
    }
}

/**
 * @brief Inserisce navi di due celle in una griglia di battaglia navale.
 *
 * Questa funzione posiziona casualmente un numero specificato di navi di due celle
 * in una griglia di battaglia navale. Le navi possono essere posizionate sia 
 * orizzontalmente che verticalmente. La funzione controlla che le posizioni scelte 
 * siano libere prima di posizionare una nave.
 *
 * @param griglia La griglia di battaglia navale rappresentata come un array bidimensionale di caratteri.
 */
void inserisci_navi_2_celle(char griglia[][MAX_LUN] )
{
//cout<<" fun navi 2 celle attivata\n";
    int casuale_1, casuale_2;
    for(int i = 0; i< quante2; i++)  //aggiunge le navi da 2 celle
    {
        srand(time(0));
        casuale_1 = (   (rand()%10)   +1);
        casuale_2 = (   (rand()%10)   +1);
        
        if ((casuale_1 %2) == 0) //orizzontale
        {
            if (griglia[casuale_1][casuale_2] == ' ' 
            &&  griglia[casuale_1 ][(casuale_2 +1 )] == ' ')
            {
                griglia[casuale_1][casuale_2]= '0';
                griglia[casuale_1 ][(casuale_2 +1) ] = '0';
                //cout<<i+1<<"° nave inserita orizz\n";
            }
            else
                i--;            
        }
        if ((casuale_1 %2) != 0) //veritcale
        {
            if (griglia[casuale_1][casuale_2] == ' ' 
            &&  griglia[(casuale_1 +1) ][casuale_2] == ' ')
            {
                griglia[casuale_1][casuale_2]= '0';
                griglia[(casuale_1 +1) ][casuale_2] = '0';
               // cout<<i+1<<"° nave inserita vert\n";
            }
            else 
                i--;
        }        
    }
}

/**
 * @brief Adds ships of 3 cells to the grid.
 * 
 * This function randomly places ships of 3 cells on the grid. The ships can be placed either 
 * horizontally or vertically. The function ensures that the ships do not overlap with each other 
 * or go out of the grid boundaries.
 * 
 * @param griglia The grid where the ships will be placed. It is a 2D array of characters.
 * 
 * @note The function uses the `rand()` function to generate random positions for the ships. 
 *       The `srand(time(0))` function is called inside the loop, which may result in the same 
 *       random numbers being generated if the function is called multiple times in quick succession.
 */
void inserisci_navi_3_celle(char griglia[][MAX_LUN]) //aggiunge le navi da 3 celle
{
   // cout<<" fun navi 3 celle attivata\n";
    int casuale_1, casuale_2;
    for(int i = 0; i< quante3; i++)  
    {
        srand(time(0));
        casuale_1 = (   (rand()%10)   +1);
        casuale_2 = (   (rand()%10)   +1);
        
        if ((casuale_1 %2) == 0) //orizzontale
        {
            if (griglia[casuale_1][casuale_2] == ' ' 
            &&  griglia[casuale_1 ][casuale_2 +1 ] == ' ' 
            &&  griglia[casuale_1 ][casuale_2 +2 ] == ' ' )
            {
                griglia[casuale_1][casuale_2]= '0';
                griglia[casuale_1 ][casuale_2 +1 ] = '0';
                griglia[casuale_1 ][casuale_2 +2 ] = '0';
                //cout<<i+1<<"° nave inserita orizz\n";
            }
            else
                i--;      
        }
        else if ((casuale_1 %2) != 0) //veritcale
        {
            if (griglia[casuale_1][casuale_2] == ' ' 
            &&  griglia[casuale_1 +1 ][casuale_2] == ' ' 
            &&  griglia[casuale_1 +2 ][casuale_2] == ' ' )
            {
                griglia[casuale_1][casuale_2]= '0';
                griglia[casuale_1 +1 ][casuale_2] = '0';
                griglia[casuale_1 +2 ][casuale_2] = '0';
                //cout<<i+1<<"° nave inserita vert\n";
            }
            else 
                i--;
        }        
    }
}

/**
 * @brief Adds ships of 4 cells to the grid.
 *
 * This function attempts to place a specified number of 4-cell ships on the grid.
 * The ships can be placed either horizontally or vertically, depending on the 
 * randomly generated coordinates. The function ensures that ships do not overlap 
 * and are placed within the bounds of the grid.
 *
 * @param griglia The game grid where the ships will be placed. It is a 2D array 
 *                of characters representing the grid cells.
 *
 * @note The function uses the `rand()` function to generate random coordinates 
 *       and `srand(time(0))` to seed the random number generator. This may result 
 *       in the same sequence of random numbers if called multiple times within 
 *       the same second.
 */
void inserisci_navi_4_celle(char griglia[][MAX_LUN] ) //aggiunge le navi da 4 celle
{
    //cout<<" fun navi 4 celle attivata\n";
    int casuale_1, casuale_2;
    for(int i = 0; i< quante4; i++)  
    {
        srand(time(0));
        casuale_1 = (   (rand()%10)   +1);
        casuale_2 = (   (rand()%10)   +1);
        
        if ((casuale_1 %2) == 0) //orizzontale
        {
            if (griglia[casuale_1][casuale_2] == ' ' 
            &&  griglia[casuale_1 ][casuale_2 +1 ] == ' ' 
            &&  griglia[casuale_1 ][casuale_2 +2 ] == ' ' 
            &&  griglia[casuale_1 ][casuale_2 +4 ] == ' ' )
            {
                griglia[casuale_1][casuale_2]= '0';
                griglia[casuale_1 ][casuale_2 +1 ] = '0';
                griglia[casuale_1 ][casuale_2 +2 ] = '0';
                griglia[casuale_1 ][casuale_2 +3 ] = '0';
               // cout<<i+1<<"° nave inserita or\n";
            }
            else
                i--;       
        }
        else if ((casuale_1 %2) != 0) //veritcale
        {
            if (griglia[casuale_1][casuale_2] == ' ' 
            &&  griglia[casuale_1 +1 ][casuale_2] == ' ' 
            &&  griglia[casuale_1 +2 ][casuale_2] == ' ' 
            && griglia[casuale_1 +3][casuale_2] == ' ')
            {
                griglia[casuale_1][casuale_2]= '0';
                griglia[casuale_1 +1 ][casuale_2] = '0';
                griglia[casuale_1 +2 ][casuale_2] = '0';
                griglia[casuale_1 +3 ][casuale_2 ] = '0';
                //cout<<i+1<<"° nave inserita vert\n";
            }
            else 
                i--;
        }      
    }
}

/**
 * @brief Inserisce le navi nella griglia di gioco.
 *
 * Questa funzione gestisce l'inserimento delle navi nella griglia di gioco.
 * Visualizza messaggi di stato e una barra di caricamento durante il processo.
 * Le navi vengono inserite in ordine crescente di dimensione, da 1 a 4 celle.
 *
 * @param gri La griglia di gioco in cui inserire le navi.
 */
void inserisci_navi(char gri[][MAX_LUN])
{
   /* cout<<"Sto modificando questa griglia: ";
    stampa_griglia(gri);*/
    cout<<"Sto inserendo le navi\n";
    cout<<"Barra di caricamento:\n";
    inserisci_navi_1_cella(gri);
    cout<<"****"<<flush;
    inserisci_navi_2_celle(gri);
    cout<<"****"<<flush;
    inserisci_navi_3_celle(gri);
    cout<<"****"<<flush;
    inserisci_navi_4_celle(gri);
    cout<<"****"<<endl;
}

/**
 * @brief Initializes the game grid for the battleship game.
 *
 * This function sets up the initial state of the game grid by:
 * - Placing letters at the beginning of each row.
 * - Placing numbers at the top of each column.
 * - Filling the last row with underscores ('_').
 * - Filling the last column with vertical bars ('|').
 * - Filling the interior of the grid with spaces (' ').
 * - Placing asterisks ('*') at the four corners of the grid.
 *
 * @param griglia The game grid to be initialized. It is a 2D array of characters.
 */
void inizializza_griglia(char griglia[][MAX_LUN])
{
    char lettera ='`';
    char lettera2 ='0';

    for(int i = 0; i<MAX_LUN; i++)  // mette le le lettere all'inizio di ogni riga
        griglia[i][0] = lettera++;

    for(int i = 0; i<MAX_LUN; i++) // mette i numeri alla prima riga
    {
        griglia[0][i] = lettera2++;
        if(lettera2 -1 == ':')
        {
            griglia[0][i] = '0';
            lettera2 = '*';
        }          
    }
    for(int i = 0; i<MAX_LUN; i++)     // mette le _ all'ultima riga
        griglia[MAX_LUN-1][i] ='_'; 

    for(int i = 0; i<MAX_LUN; i++)        // mette le | alla prima riga
        griglia[i][MAX_LUN-1] ='|'; 

    for(int i = 1; i < MAX_LUN-1; i++)
        for(int j=1; j<MAX_LUN-1; j++)
            griglia[i][j]=' ';
    
    griglia[MAX_LUN-1] [MAX_LUN -1] = '*';
    griglia[0] [MAX_LUN -1] = '*';
    griglia[MAX_LUN-1] [0] = '*';
    griglia[0] [0] = '*';
}

/**
 * @brief Initializes a player with a name and two grids.
 * 
 * This function prompts the user to input the player's name, initializes the player's own grid and the opponent's grid, 
 * and sets the player's score to zero.
 * 
 * @param g Reference to a giocatore_t structure that will be initialized.
 */
void inizializza_giocatore(giocatore_t &g)
{
    cout<<"Inserisci qui il nome del giocatore: ";
    cin>>g.nome;
    inizializza_griglia (g.griglia_avversaria);
    inizializza_griglia (g.griglia_propria);
    g.punteggio = 0;
}

