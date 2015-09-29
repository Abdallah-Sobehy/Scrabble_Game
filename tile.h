/** \file tile.h
 * This header file contains the prototypes of the tiles and functions.
 * @author: Abdallah & Fred
 * @date: 05-01-15
 */

/**
 * Definition of the tile using a structure
 */

# if ! defined (TILE_H)
# define TILE_H

typedef struct {
  
    char letter; /** < Character printed on the scrabble tile */
    int point_value; /** < Point value on the scrabble tile */
}tile;

// typedef struct element * character_tile;



/**
 * Initializes the tile with the input character and the corresponding point value */
tile new_tile(char);


/**
 * Function to assign a character to the blank tile. */
tile assign_char(tile);

/**
 * The get score function returns the point value of the input tile 
 */
int get_score(tile);


/**
 * Returns the letter of the input tile */
char get_letter(tile);

/**
* Returns true if the input tiles have the same letters.
* Only the letters are compared not the point value so that we can take an input from user to choose a tile just by letter
*/
int is_equal(tile t1, tile t2);

/**
* Checks if the tile picked is blank
*/
int blank_tile ( tile );

# endif