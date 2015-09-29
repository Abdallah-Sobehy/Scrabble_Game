/** @file board.h Header file to describe prototypes for functions related to the scrabble board.
* \author Fred and Abdallah 
*/ 
# if ! defined (BOARD_H)
# define BOARD_H

# include <stdio.h>
# include <stdlib.h>
# include "tile.h"
# include "bag.h"

/** length of any found word; each string will save the found word, then the number of DW, TW squares related to word
the word length  is 32 = 15 ( max word ) + \0 + DW + \0 + TW + \0 + 2 characters to store starting row + \0
 + 2 characters to store starting col + \0 + 2 characters to store ending row + \0 + 2 characters to store ending col + \0
*/
# define word_len 32 
/** the number of rows or columns in the scrabble game
*/
# define max_rc 15
/** maximum number of words that can be played in one turn
*/
# define max_words 8 

/** new_board function returns a 2D array of pointer 2 tiles
* Each tile pointer is pointing to an empty, DL, DW, TL, TW tiles.
* \author Frend and Abdallah
*/
void  new_board(tile * board [max_rc][max_rc]);

/** display_board function displays the scrabble board to the user.
\ author Abdallah
*/
void display_board(tile * board [max_rc] [max_rc]);

/** Checks board for the added word or words
* Checks the validity of the added tiles in terms of the position of the tiles, and existence in dictionary
* returns the added word/words if valid in the array of strings 
* \author Abdallah
*/
int check_board (tile * board [max_rc] [max_rc], tile * board_prev [max_rc] [max_rc] , char str [max_words] [word_len], int * temp_score);

/** used by check_board function to check the first play
* it is considered as a special case as: only one word is added, the word does not have to touch an already existing word
* @see check_board
* \author Abdallah
*/
int check_first_play (tile * board [max_rc] [max_rc], char str [word_len]);

/** used by check_first_play function, gets the letter in the tile to the right and amends it to the string 
* Recusrively continues until the string is amended with all letters aligned horizontally @see check_first_play
* \author Abdallah
*/
void amend_letter_right(tile * board [max_rc] [max_rc] ,int i ,int j ,char str [word_len] ,int * index);

/** Gets the letter in the tile to the right and amends it to the string for the nth play where n > 1
* Recusrively continues until the string is amended with all letters aligned horizontally
* used inside check_board function to help getting the added word @see check_board
* \author Abdallah
*/
void amend_letter_right_n(tile * board [max_rc] [max_rc] , tile * board_prev [max_rc] [max_rc]  ,int i ,int j ,char str [word_len] ,int * index , int * temp_temp, int * DW_flag , int * TW_flag, int *connection_flag);

/** Gets the letter in the tile to the bottom and amends it to the string for the nth play where n > 1
* Recusrively continues until the string is amended with all letters aligned horizontally
* used inside check_board function to help getting the added word @see check_board
* \author Abdallah
*/
void amend_letter_bottom_n (tile * board [max_rc] [max_rc] , tile * board_prev [max_rc] [max_rc]  ,int i ,int j ,char str [word_len] ,int * index , int * temp_temp, int * DW_flag , int * TW_flag,int *connection_flag);


/** used by check_first_play function, Gets the letter in the tile to the bottom and amends it to the string
* Recusrively continues until the string is amended with all letters aligned vertically @see check_first_play
* \author Abdallah
*/
void amend_letter_bottom(tile * board [max_rc] [max_rc] ,int i ,int j ,char str [word_len] ,int * index);

/**
 *  Asks player to place tile on the board and checks whether tile to be placed corresponds to any 
 * of the tiles in the player's hand. Also request player to enter index to place the tile. 
* \author Fred
 */
bag place_tile( bag in_hand, tile *board[max_rc][max_rc], int *temp_score, int *DW_flag, int *TW_flag);


/**
 * Request player for index to remove tile from the board. This tile should be in the same turn of play.
 * After successful removal of tile temp_score is decremented accordingly. 
* author Fred
 */
bag pickup_tile(bag in_hand, tile *board[max_rc][max_rc], int *temp_score, int *DW_flag, int *TW_flag);

/**
 * When the player chooses to play his turn, if the added word is valid in terms of position and existence in the dictionary
 * The score of the player is updated with the information of the temp_score and the DW and TW flags
 * used only in the first play @see check_first_play
 * \author Abdallah
 */
 int update_score( int score , int * tmp_score , int * DW_flag, int * TW_flag);

  /**Power function to  return x^n to be used by update_score function @see update_score
  * \author Abdallah
 */
int power ( int x,  int n);


/** returns the imaginary tile of the original (empty board)
* either returns an empty ( Normal tile on the board ), DL (Double Letter ), DW (Double Word ), 
* TL (Triple Letter), TW (Triple Word ) 
* \author Abdallah
*/
tile get_original (int i , int j);

/** copy the content of the first input board into the second input board
*  \author Abdallah
*/
void copy_board( tile *copy [max_rc][max_rc] , tile *paste [max_rc][max_rc] );

/** for the nth play where n > 1 the function returns the horizontal starting point of a word
* Used by the check_board function to know where to start amending to right
* returns the column number that the word starts at
* @param [in] board The current board
* @param [in] i the row number where the new tile was found
* @param [in] j the column number where the new tile was found
* @see check_board
* \author Abdallah
*/

int horizontal_start ( tile *board[max_rc][max_rc] , int i ,int j);


/** for the nth play where n > 1 the function returns the vertical starting point of a word
* Used by the check_board function to know where to start amending to bottom
* returns the rows number that the word starts at
* @param [in] board The current board
* @param [in] rows the rows number where the new tile was found
* @param [in] cols the column number where the new tile was found
* @see check_board
* \author Abdallah
*/
int vertical_start (tile *board[max_rc][max_rc] , int i , int j );

/** for the nth play where n > 1 the function returns whether the found tile is 
* not connected to any tile on the board -> returns 0
* connected to a tile in a horizontal way -> returns 1
* connected to a tile in a vertical way -> returns 2
* connected to tiles both horizontally and vertically returns 3
* @param [in] board The current board
* @param [in] rows row number
* @param [in] cols column number
* \author Abdallah 
*/
int is_connected ( tile *board[max_rc][max_rc] , int i  , int j );

/** returns true iF the tile is connected to a tile from the previous turn
* used by check_board to ake sure that at least one of the added tiles is connected to a tile from a previous turn
*\author Abdallah
*/
int is_connected_to_prev ( tile *board_prev[max_rc][max_rc] , int i  , int j );

/** prints all words stored in the array of strings
* mainly for testing uses
* \author Abdallah
*/
void print_words (char words [max_words] [word_len] , int words_count);

/** saves the starting and ending indices ( row and col number ) 
* in the position [20] for starting row number and [23] for starting col number
* in position [26] for ending row number and [29] for ending col number
* \author Abdallah
*/
void delimit_string (char word [word_len] , int start_i , int start_j , int end_i , int end_j );

/** gets the starting row number for a word stored in the mentioned position in the string 
* @see starting_row_index
* \author Abdallah
*/
int get_starting_rows (char word [word_len]);


/** gets the starting col number for a word stored in the mentioned position in the string 
*@see starting_col_index
* \author Abdallah
*/
int get_starting_col (char word [word_len]);

/** gets the ending row number for a word stored in the mentioned position in the string 
* @see ending_row_index
* \author Abdallah
*/
int get_ending_rows (char word [word_len]);


/** gets the ending col number for a word stored in the mentioned position in the string 
* @see ending_col_index
* \author Abdallah
*/
int get_ending_col (char word [word_len]);

/** returns true if the word already exist in the array of strings
* \author Abdallah
*/
int word_repeated ( char new_word [word_len] , char words [max_words] [ word_len ] , int words_count);

/** copies the second input string into the first one because the strcop will not be sufficient as the strings used here have more than one \0
* \author Abdallah
*/
void strcopy (char str1 [word_len] , char str2 [word_len] );

# endif