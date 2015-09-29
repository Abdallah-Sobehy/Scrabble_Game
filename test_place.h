/** \file test_place.h
 *  The file contains prototypes for test cases for the below functions.
 * @author : Fred
 * @date : 11 -02- 14  
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tile.h"
#include "bag.h"
#include "board.h"


/**
 * Test the place tile function for the board. 
 * Tiles are placed on the board in the correct sequence
 */

void place_tile_valid();


/**
 * Test the place tile function for the board. 
 * Tiles are placed in the wrong sequence
 */

void place_tile_invalid();


/**
 * Test the pick up tile function for the board. 
 * Tiles are pick up from indices with tiles place on them
 */

void pickup_tile_valid();

/**
 * Test the pick up tile function for the board. 
 * Attempt to pick up tiles from indices without tiles.
 */

void pickup_tile_invalid();

/**
 *  A test for assignment of character for a blank tile to be 
 *  place on the board.
 */

void place_blank_tile();

/**
 *  A test to pickup an assigned blank tile from the board 
 *  and making the tile blank again.
 */

void pickup_blank_tile();

