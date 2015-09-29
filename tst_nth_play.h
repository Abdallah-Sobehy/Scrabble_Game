/** @file tst_nth_play.h tests the nth play after the first play 
* the board can be at any state of valid words then some tiles are added to the already existing tiles
* \author Abdallah 
*/
# if ! defined (NTH_H)
# define NTH_H
# include <stdio.h>
# include <stdlib.h>
# include "tile.h"
# include "bag.h"
#include "board.h"
# include "ui.h"

/**
* second play is tested over a valid first play word
* the second play adds one word to the board by amending tiles to the existing word to form a new word
*/
void test_second_valid ();

/**
* second play is tested over a valid first play word
* the second play adds two words to the board by amending tiles to the existing word to form 2 new words
*/
void test_second_valid2 ();

/**
* second play is tested over first play
* the second play adds 3 words to the board by amending tiles to the existing word to form 3 new words
*\author Abdallah
*/
void test_second_valid3();

/**
* second play is tested over first play
* the second play adds 4 words to the board by amending tiles to the existing word to form 4 new words
*\author Abdallah
*/
void test_second_valid4();


/**
* second play is tested over first play
* the second play adds a word that does not exist in the dictionary
*\author Abdallah
*/
void test_second_invalid();

/**
* second play is tested over first play
* the second play adds a word that exists in the dictionary but is nor properly connected
* This test discovered a bug in the code as the code handeled the case of one tile not connected at all, but this case shows a new word not connected to any tile of the previous turn
*\author Abdallah
*/
void test_second_invalid2();

/**
* nth play where the board is in a valid state that can occur after more than one play and a tile is added to add 2 words one horizontal and one vertical
* \author Abdallah
*/
void test_nth_valid(); 

/**
* nth play where the board is in a valid state that can occur after more than one play and a tile is added to add 2 words one horizontal and one vertical but does not exist in the dictionary
* \author Abdallah
*/
void test_nth_invalid();

#endif