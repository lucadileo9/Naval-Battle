#ifndef DATI_H
#define DATI_H

const int MAX_LUN = 12; // The maximum length of the grid.
extern int quante1, quante2, quante3, quante4; // The quantity of ships of different sizes.
extern int num_turni; // The number of turns to be played.
extern int PUN; // The maximum score to be reached.

/**
 * @struct giocatore_t
 * @brief Represents a player in the battleship game.
 * 
 * This structure holds the necessary information for a player, including their name,
 * their own grid, the opponent's grid, and their score.
 * 
 * @var giocatore_t::nome
 * The name of the player. It is a character array with a maximum length defined by MAX_LUN.
 * 
 * @var giocatore_t::griglia_propria
 * The player's own grid. It is a 2D character array with dimensions defined by MAX_LUN.
 * 
 * @var giocatore_t::griglia_avversaria
 * The opponent's grid as seen by the player. It is a 2D character array with dimensions defined by MAX_LUN.
 * 
 * @var giocatore_t::punteggio
 * The score of the player. It is an integer value.
 */
struct giocatore_t {
    char nome[MAX_LUN];
    char griglia_propria[MAX_LUN][MAX_LUN];
    char griglia_avversaria[MAX_LUN][MAX_LUN];
    int punteggio;
};

#endif // DATI_H
