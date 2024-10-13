/**
 * @brief Inserts 1-cell ships into the grid,
 * the number of ships inserted is contained in the file dati.h
 * 
 */
void inserisci_navi_1_cella(char griglia[][MAX_LUN]);

/**
 * @brief Inserts 2-cell ships into the grid,
 * the number of ships inserted is contained in the file dati.h
 * 
 */
void inserisci_navi_2_celle(char griglia[][MAX_LUN]);

/**
 * @brief Inserts 3-cell ships into the grid,
 * the number of ships inserted is contained in the file dati.h
 * 
 */
void inserisci_navi_3_celle(char griglia[][MAX_LUN]);

/**
 * @brief Inserts 4-cell ships into the grid,
 * the number of ships inserted is contained in the file dati.h
 * 
 */
void inserisci_navi_4_celle(char griglia[][MAX_LUN]);

/**
 * @brief Inserts all ships into the grid,
 * the number of ships inserted is contained in the file dati.h
 * 
 */
void inserisci_navi(char gri[][MAX_LUN]);

/**
 * @brief initializes the grids, decorating the sides,
 * lower and upper rows, DOES NOT INSERT SHIPS
 * 
 * @param griglia 
 */
void inizializza_griglia(char griglia[][MAX_LUN]);

/**
 * @brief asks for the player's name and initializes the grids
 * 
 * @param g player
 */
void inizializza_giocatore(giocatore_t &g);
