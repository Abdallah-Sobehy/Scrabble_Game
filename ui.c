/** @file ui.c user interface functions that is in a form of a menu. 
\author Abdallah
*/
# include <stdio.h>
# include <stdlib.h>
# include "tile.h"
# include "bag.h"
#include "board.h"
#include "ui.h"
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

/* menu displays the first menu for the user when the game opens.
* Provides a brief about scrabble game.
* offers the choice to a 1-new game, 2-language choice, 3-reading the rules, 4-exiting the game
* returns the choice of the user.
*/
int menu() 
{
	int choice;
	printf("Welcome to Scrabble V1\n");
//	printf("Scrabble is one of the most popular word games. In scrabble V1 the game is to be played by one player. With a total of 100 tiles (7 tiles in hand at a time) each having a single letter the player should try to get the maximum possible score by placing the tiles to form words on a 15x15 grid.\n");
	printf("Options :\n");
	printf("1- New Game.\n2- Choose Language.\n3- Read the rules.\n4- Exit.\n");
	scanf("%d", &choice);
	return choice;
}

/*
* new_game() function is the core function of scrabble where the board, bag are initialized and displayed.
* The scrabble game is started interactively with the user
*/
void new_game()
{
	tile * board_curr [max_rc] [max_rc];
	tile * board_prev [max_rc] [max_rc];
	new_board(board_curr);
	copy_board (board_curr , board_prev);
	bag real_bag, inhand_bag;
	real_bag = new_real_bag();//initializing the real bag
	inhand_bag = new_inhand_bag(&real_bag);// initializing the 7 tiles in posession of the player from the real bag
    int DW_flag, TW_flag, temp_score;
    DW_flag = 0;
    TW_flag = 0;
    temp_score = 0;
    char words [max_words] [word_len];// array of 8 strings to save the found words on the board in one play
    // each string will save the found word, then the number of DW, TW squares related to words is amended afterwards
    // the string length is 20 = 15 ( max word ) + \0 + DW + \0 + TW + \0
	int choice;
	int score = 0;
	int valid_flag;// to store the outcome of check_board to know if it valid or not
	//int words_count = 0; // number of found words in one play
	while(1)
	{
	    display_board(board_curr);
		display_bag (inhand_bag);
		printf("Current score = %d\n",score);
		choice = menu_1();
		switch (choice)
		{
			case 1:
			    inhand_bag = place_tile( inhand_bag, board_curr , &temp_score, &DW_flag, &TW_flag);
				break;

			case 2:
			        inhand_bag = pickup_tile(inhand_bag, board_curr , &temp_score, &DW_flag, &TW_flag);
				break;

			case 3:

				exchange( &inhand_bag , &real_bag );
				break;

			case 4:
				printf("Call pass function.\n");//call new_game() function
				break;

			case 5:// play is chosen
				
				valid_flag = check_board(board_curr, board_prev , words , &temp_score);
				if( valid_flag && ! isalpha (get_letter( *board_prev [7] [7] ) ) )//to indicate that it is the first turn
				{
					score = update_score (score, &temp_score , &DW_flag, &TW_flag );
					refill_inhand_bag(&inhand_bag , &real_bag);
					copy_board (board_curr , board_prev);
				}
				else if( valid_flag )// if the play was valid for nth play where n > 1
				{
					copy_board (board_curr , board_prev); // to update the board_prev for  nth play where n > 1
					refill_inhand_bag(&inhand_bag , &real_bag);
					score += temp_score ;
					temp_score = 0;
				}
			case 6:
				break;
			default: 
				printf("Please enter a valid choice.\n");//call new_game() function
				break;
			
		}
		if(choice == 6)// the user wants to quit the game
			break;
	
	}
	
}

/*
* menu_1 is the first option in the main menu: menu() which is new game
* offers the choice to 1-place/pick up a tile, 2- exchange tiles, 3- pass, 4- quit game
* returns the choice of the user.
* @see menu
*/
int menu_1()
{
	int choice;
	printf("Options :\n");
	printf("1- Place a tile on the board.\n2- Pick up a tile from the board.\n3- Exchange tiles.\n4- Pass.\n5- Play\n6- Quit game.\n");
	scanf("%d", &choice);
	return choice;

}