/**
 * @brief allows performing the shot
 * 
 * @param x first coordinate
 * @param y second coordinate
 * @param verifica first grid
 * @param mod second grid
 * @param shot allows determining how many ships have been hit
 * @return true if the ship is hit
 * @return false if the ship is not hit
 */
bool tiro(int x, int y, const char verifica[][MAX_LUN], char mod[][MAX_LUN], int& shot);

/**
 * @brief converts coordinates from
 * characters to numbers
 * 
 * @param x 
 * @return int 
 */
int converti_coo(char x);

/**
 * @brief turn of the individual player
 * 
 * @param g1 player
 * @param g2 opponent
 */
void turno(giocatore_t &g1, giocatore_t &g2);

/**
 * @brief converts yes/no to an integer
 * 
 * @param risp 
 * @return int 
 */
int converti_scelta(char risp[3]);

/**
 * @brief typical game mode, stops only when
 * one player sinks all the ships
 * 
 * @param g1 player 1
 * @param g2 player 2
 * @param quan number of turns (initially 1000)
 */
void turni_vari(giocatore_t &g1, giocatore_t &g2, const int quan);

/**
 * @brief the game continues until a score is reached
 * this is provided in the variable PUN
 * 
 * @param g1 
 * @param g2 
 */
void max_punt(giocatore_t &g1, giocatore_t &g2);

/**
 * @brief prints the quantity of ships
 * 
 */
void stampa_quantita();

/**
 * @brief allows modifying the quantity of ships
 * 
 */
void modifica_quantita();
