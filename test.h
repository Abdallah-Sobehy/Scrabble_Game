/** @file test.h tests the check_board function, to be able to extract a word from the added tiles if they were put in valid positions
* It also checks if they exist in the dictionary
* Tested functions : newboard , check_first_play , display_board , display_bag , get_letter , amend_letter_right, amend_letter_bottom
* \author Abdallah
*/
# include <stdio.h>
# include <stdlib.h>
# include "tile.h"
# include "bag.h"
#include "board.h"

/**
* gets string of a horizontally placed valid word; valid in terms of positioning
* Valid as it exists in the dictionary.
*/
void test_horizontal_valid ();

/**
* gets string of a vertically placed valid word in terms of position
* Valid as it exists in the dictionary
*/
void test_vertical_valid ();

/**
* gets string of a horizontally placed valid word; valid in terms of positioning
* invalid as it does not exist in the dictionary
*/
void test_horizontal_invalid ();

/**
* gets string of a vertically placed valid word in terms of position
* invalid as it does not exist in the dictionary
*/
void test_vertical_invalid ();

/**
* returns an empty string for a board with no placed words
*/
void test_empty ();

/**
* returns an empty string for placing tiles in invalid position
* a vertical word with a tile in an unconnected place
*/
void test_invalid1();

/**
* returns an empty string for placing tiles in invalid position
* a horizontal word with a tile in an unconnected place
*/
void test_invalid2();

/**
* returns an empty string for placing tiles in invalid position
* Tile connected but not aligning in one row or column
*/
void test_invalid3();

/**
* A word placed but not passing by the central square
*/
void test_invalid4();