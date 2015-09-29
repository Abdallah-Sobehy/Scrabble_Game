/** \file test_place.c
 *  The file contains implementation for test cases for the below functions.
 * @author : Fred
 * @date : 11 -02- 14  
 */

# include <stdio.h>
# include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tile.h"
#include "bag.h"
#include "board.h"
#include "test.h"

/** the number of rows or columns in the scrabble game
*/
# define max_rc 15

void place_tile_valid()
  {
    
     
      tile * board[max_rc][max_rc];
      int *temp_score, *DW_flag, *TW_flag;
      int DW, TW, tempscore;
      temp_score = &tempscore;
      DW_flag = &DW;
      TW_flag = &TW;
    
    
    new_board(board);
    bag in_hand;
    
    tile t1,t2, t3, t4, t5, t6, t7;
   
    
    t1 = new_tile('J');
    t2 = new_tile('U');
    t3 = new_tile('S');
    t4 = new_tile('L');
    t5 = new_tile('Y');
    t6 = new_tile('O');
    t7 = new_tile('A');
   
    in_hand = new_bag();
    in_hand = insert(in_hand, t1);
    in_hand = insert(in_hand, t2);
    in_hand = insert(in_hand, t3);
    in_hand = insert(in_hand, t4);
    in_hand = insert(in_hand, t5);
    in_hand = insert(in_hand, t6);
    in_hand = insert(in_hand, t7);
    printf("\n");
    printf("Please pick a letter from the bag and place \
 on your preferred index on the board\n" ); 
    display_bag(in_hand); 
    display_board(board);
    place_tile(in_hand, board, temp_score, DW_flag, TW_flag);
    display_board(board);
    display_bag(in_hand); 
    place_tile(in_hand, board, temp_score, DW_flag, TW_flag);
    display_board(board);
    display_bag(in_hand); 
    place_tile(in_hand, board, temp_score, DW_flag, TW_flag);
    display_board(board);
    display_bag(in_hand);
    
}


/**
 * Test the place tile function for the board. 
 * Tiles are placed in the wrong sequence
 */

// void place_tile_invalid();

/**
 * Test the pick up tile function for the board. 
 * Tiles are pick up from indices with tiles place on them
 */

void pickup_tile_valid(){
     
    printf("\n");
     tile * board[max_rc][max_rc];
    int *temp_score, *DW_flag, *TW_flag;
    int DW, TW, tempscore;
    temp_score = &tempscore;
    DW_flag = &DW;
    TW_flag = &TW;
    
    
    new_board(board);
    bag in_hand;
    in_hand = new_bag();
    tile t1,t2, t3, t4, t5, t6, t7;
   
    t1 = new_tile('J');
    t2 = new_tile('U');
    t3 = new_tile('S');
    t4 = new_tile('T');
    t5 = new_tile('Y');
    t6 = new_tile('O');
    t7 = new_tile('A');
    
    board[7][7] = &t1;
    board[7][8] = &t2;
    board[7][9] = &t3;
    board[7][10] = &t4;
    
    printf("Please pickup a letter from the board \n" ); 
    // display_bag(in_hand); 
    display_board(board);
   in_hand =  pickup_tile(in_hand, board, temp_score, DW_flag, TW_flag);
    display_board(board);
    display_bag(in_hand); 
    in_hand = pickup_tile(in_hand, board, temp_score, DW_flag, TW_flag);
    display_board(board);
    display_bag(in_hand); 
    in_hand = pickup_tile(in_hand, board, temp_score, DW_flag, TW_flag);
    display_board(board);
    display_bag(in_hand);
    printf("\n");
}

/**
 * Test the pick up tile function for the board. 
 * Attempt to pick up tiles from indices without tiles.
 */

void pickup_tile_invalid()
{
     tile * board[max_rc][max_rc];
    int *temp_score, *DW_flag, *TW_flag;
    int DW, TW, tempscore;
    temp_score = &tempscore;
    DW_flag = &DW;
    TW_flag = &TW;
  
    
    new_board(board);
    bag in_hand;
    in_hand = new_bag();
   
    printf("Please attempt to pickup a non-existing letter from the board \n" ); 
    // display_bag(in_hand); 
    display_board(board);
    pickup_tile(in_hand, board, temp_score, DW_flag, TW_flag);
    display_board(board);
    pickup_tile(in_hand, board, temp_score, DW_flag, TW_flag);
    printf("\n");
  
}

/**
 *  A test for assignment of character for a blank tile to be 
 *  place on the board.
 */

void place_blank_tile()
{
    
    tile * board[max_rc][max_rc];
    int *temp_score, *DW_flag, *TW_flag;
    int DW, TW, tempscore;
    temp_score = &tempscore;
    DW_flag = &DW;
    TW_flag = &TW;
   
    new_board(board);
    bag in_hand;
    in_hand = new_bag();
    tile t1,t2,t3;
   
    t1 = new_tile('_');
    t2 = new_tile('_');
    t3 = new_tile('s');
   
    in_hand = insert(in_hand, t1);
    in_hand = insert(in_hand, t2);
    in_hand = insert(in_hand, t3);
    
    printf("Please place a blank tile on the board \n" ); 
    display_bag(in_hand); 
    display_board(board);
    place_tile(in_hand, board, temp_score, DW_flag, TW_flag);
    display_board(board);
    display_bag(in_hand); 
    place_tile(in_hand, board, temp_score, DW_flag, TW_flag);
    display_board(board);
    display_bag(in_hand);
    printf("\n");
}

/**
 *  A test to pickup an assigned blank tile from the board 
 *  and making the tile blank again.
 */

void pickup_blank_tile()
{
    tile * board[max_rc][max_rc];
    int *temp_score, *DW_flag, *TW_flag;
    int DW, TW, tempscore;
    temp_score = &tempscore;
    DW_flag = &DW;
    TW_flag = &TW;
 
    
    new_board(board);
    bag in_hand;
    in_hand = new_bag();
    tile t1, t2, t3;
    
    t1 = new_tile('A');
    t2 = new_tile('T');
    t3 = new_tile('E');
    
    t1.point_value = 0;
    t2.point_value = 0;
    
    board[7][7] = &t1;
    board[7][8] = &t2;
    
    in_hand = insert( in_hand, t3 );
    
    printf("Please pickup the 2 letters which were initially blank from the board\n" ); 
    display_board(board);
    display_bag(in_hand); 
    in_hand = pickup_tile(in_hand, board, temp_score, DW_flag, TW_flag);
    display_board(board);
    display_bag(in_hand); 
    in_hand =  pickup_tile(in_hand, board, temp_score, DW_flag, TW_flag);
    display_board(board);
    display_bag(in_hand); 
    
}

/**
 * Test the place tile function for the board. 
 * Tiles are placed on the board in the correct sequence
 */
int main ( int argc, char argv[] )
{
    place_tile_valid();  
    pickup_tile_valid();
    place_blank_tile();
    pickup_blank_tile();
    
     
     return 0;
}

