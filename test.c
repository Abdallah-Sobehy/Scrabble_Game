/** @file test.c tests the check_board function, to be able to extract a word from the added tiles if they were put in valid positions
* It also checks if they exist in the dictionary
* Tested functions : newboard , check_first_play , display_board , display_bag , get_letter , amend_letter_right, amend_letter_bottom
* \author Abdallah
*/
# include <stdio.h>
# include <stdlib.h>
# include "tile.h"
# include "bag.h"
#include "board.h"
# include "dictionary.h"
#include "test.h"
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

char str [max_words] [word_len]; // to be sent to the check_board function to store added words
int temp_score; // to be sent to check_board function to store the added score for one play
/** The added word is valid in term of position (horizontally) exists in the dictionary
*\author Abdallah
*/
void test_horizontal_valid ()
{
	tile * board [max_rc] [max_rc];
	new_board(board);
	tile * board_prev [max_rc] [max_rc];
	new_board (board_prev);
	bag real_bag, inhand_bag;
	tile t1,t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15;
	real_bag = new_real_bag();//initializing the real bag
	inhand_bag = new_inhand_bag(&real_bag);// initializing the 7 tiles in posession of the player from the real bag
    //tested word:holocrystalline, longest possible (15 letters)
	t1 = new_tile('h');
	t2 = new_tile('o');
	t3 = new_tile('l');
	t4 = new_tile ('o');
	t5 = new_tile('c');
	t6 = new_tile('r');
	t7 = new_tile('y');
	t8 = new_tile ('s');
	t9 = new_tile('t');
	t10 = new_tile('a');
	t11= new_tile('l');
	t12= new_tile ('l');
	t13= new_tile ('i');
	t14= new_tile ('n');
	t15= new_tile ('e');
	board[7][0] = &t1;
	board[7][1] = &t2;
	board[7][2] = &t3;
	board[7][3] = &t4;
	board[7][4] = &t5;
	board[7][5] = &t6;
	board[7][6] = &t7;
	board[7][7] = &t8;
	board[7][8] = &t9;
	board[7][9] = &t10;
	board[7][10] = &t11;
	board[7][11] = &t12;
	board[7][12] = &t13;
	board[7][13] = &t14;
	board[7][14] = &t15;
	display_board(board);
	display_bag (inhand_bag);

	char new_word [word_len];
	check_board ( board , board_prev , str , & temp_score );
	printf("The word added to the board is %s\n",str [0] );

}
/** The added word is valid in term of position (vertically) and exists in the dictionary
*\author Abdallah
*/
void test_vertical_valid ()
{
	tile * board [max_rc] [max_rc];
	new_board(board);
	tile * board_prev [max_rc] [max_rc];
	new_board (board_prev);
	bag real_bag, inhand_bag;
	tile t1,t2, t3, t4;// tiles to be used for testing purposesone for the real bag and the other for hand
	real_bag = new_real_bag();//initializing the real bag
	inhand_bag = new_inhand_bag(&real_bag);// initializing the 7 tiles in posession of the player from the real bag
	


	//Testing horizontal "to"
	t1 = new_tile('l');
	t2 = new_tile('o');
	t3 = new_tile('s');
	t4 = new_tile ('e');
	board[7][7] = &t1;
	board[8][7] = &t2;
	board[9][7] = &t3;

	board[10][7] = &t4;
	display_board(board);
	display_bag (inhand_bag);

	char new_word [word_len];
	check_board ( board , board_prev , str , & temp_score);
	printf("The word added to the board is %s\n",str [0] );
}

/** The added word is invalid in term of position (horizontally) but it does not exist in the dictionary
*\author Abdallah
*/
void test_horizontal_invalid ()
{
	tile * board [max_rc] [max_rc];
	new_board(board);
	tile * board_prev [max_rc] [max_rc];
	new_board (board_prev);
	bag real_bag, inhand_bag;
	tile t1,t2, t3, t4;// tiles to be used for testing purposesone for the real bag and the other for hand
	real_bag = new_real_bag();//initializing the real bag
	inhand_bag = new_inhand_bag(&real_bag);// initializing the 7 tiles in posession of the player from the real bag
	


	//Testing horizontal "to"
	t1 = new_tile('t');
	t2 = new_tile('w');
	t3 = new_tile('o');
	t4 = new_tile ('x');
	board[7][7] = &t1;
	board[7][8] = &t2;
	board[7][9] = &t3;

	board[7][6] = &t4;
	display_board(board);
	display_bag (inhand_bag);

	char new_word [word_len];
	check_board ( board , board_prev , str , & temp_score);

}

/** The added word is valid in term of position (vertically) and it does not exist in the dictionary
*\author Abdallah
*/
void test_vertical_invalid ()
{
	tile * board [max_rc] [max_rc];
	new_board(board);
	tile * board_prev [max_rc] [max_rc];
	new_board (board_prev);
	bag real_bag, inhand_bag;
	tile t1,t2, t3, t4;// tiles to be used for testing purposesone for the real bag and the other for hand
	real_bag = new_real_bag();//initializing the real bag
	inhand_bag = new_inhand_bag(&real_bag);// initializing the 7 tiles in posession of the player from the real bag
	


	//Testing horizontal "to"
	t1 = new_tile('t');
	t2 = new_tile('w');
	t3 = new_tile('o');
	t4 = new_tile ('x');
	board[7][7] = &t1;
	board[8][7] = &t2;
	board[9][7] = &t3;

	board[10][7] = &t4;
	display_board(board);
	display_bag (inhand_bag);

	char new_word [word_len];
	check_board ( board , board_prev , str , & temp_score);

}
/** The player tries to play the first turn without adding any tiles, a warning message is displayed to ask him to add a tile passing through the center
*\author Abdallah
*/
void test_empty()
{
	tile * board [max_rc] [max_rc];
	new_board(board);
	tile * board_prev [max_rc] [max_rc];
	new_board (board_prev);
	bag real_bag, inhand_bag;
	real_bag = new_real_bag();//initializing the real bag
	inhand_bag = new_inhand_bag(&real_bag);// initializing the 7 tiles in posession of the player from the real bag
	display_board(board);
	display_bag (inhand_bag);

	char new_word [word_len];
	check_board ( board , board_prev , str , & temp_score);
	printf("Invalid placement; no tiles \n");
}

/** A valid vertical word (position and exist in the dictionary) but another tile is place in an unconnected square
* \author Abdallah
*/
void test_invalid1()
{
	tile * board [max_rc] [max_rc];
	new_board(board);
	tile * board_prev [max_rc] [max_rc];
	new_board (board_prev);
	bag real_bag, inhand_bag;
	tile t1,t2, t3, t4;// tiles to be used for testing purposesone for the real bag and the other for hand
	real_bag = new_real_bag();//initializing the real bag
	inhand_bag = new_inhand_bag(&real_bag);// initializing the 7 tiles in posession of the player from the real bag
	
	t1 = new_tile('t');
	t2 = new_tile('w');
	t3 = new_tile('o');
	t4 = new_tile ('x');
	board[7][7] = &t1;
	board[8][7] = &t2;
	board[9][7] = &t3;

	board[10][10] = &t4;
	display_board(board);
	display_bag (inhand_bag);

	char new_word [word_len];
	check_board ( board , board_prev , str , & temp_score);
	printf("Invalid placement \n");
}

/** A valid horizontal word (position and exist in the dictionary) but another tile is place in an unconnected square
* \author Abdallah
*/
void test_invalid2()
{
	tile * board [max_rc] [max_rc];
	new_board(board);
	tile * board_prev [max_rc] [max_rc];
	new_board (board_prev);
	bag real_bag, inhand_bag;
	tile t1,t2, t3, t4;// tiles to be used for testing purposesone for the real bag and the other for hand
	real_bag = new_real_bag();//initializing the real bag
	inhand_bag = new_inhand_bag(&real_bag);// initializing the 7 tiles in posession of the player from the real bag
	
	t1 = new_tile('t');
	t2 = new_tile('w');
	t3 = new_tile('o');
	t4 = new_tile ('x');
	board[7][7] = &t1;
	board[7][8] = &t2;
	board[7][9] = &t3;

	board[10][10] = &t4;
	display_board(board);
	display_bag (inhand_bag);

	char new_word [word_len];
	check_board ( board , board_prev , str , & temp_score);
printf("Invalid placement \n");
}


/**
* Tiles are in an invalid position. Though connected, they are not aligning in one row or column
* \author Abdallah
*/
void test_invalid3()
{
	tile * board [max_rc] [max_rc];
	new_board(board);
	tile * board_prev [max_rc] [max_rc];
	new_board (board_prev);
	bag real_bag, inhand_bag;
	tile t1,t2, t3, t4;// tiles to be used for testing purposesone for the real bag and the other for hand
	real_bag = new_real_bag();//initializing the real bag
	inhand_bag = new_inhand_bag(&real_bag);// initializing the 7 tiles in posession of the player from the real bag
	
	t1 = new_tile('t');
	t2 = new_tile('w');
	t3 = new_tile('o');
	t4 = new_tile ('x');
	board[7][7] = &t1;
	board[7][8] = &t2;
	board[7][9] = &t3;

	board[8][8] = &t4;
	display_board(board);
	display_bag (inhand_bag);

	char new_word [word_len];
	check_board ( board , board_prev , str , & temp_score);
printf("Invalid placement \n");
}


/**
* A word placed but not passing by the central square
* \author Abdallah
*/
void test_invalid4()
{
	tile * board [max_rc] [max_rc];
	new_board(board);
	tile * board_prev [max_rc] [max_rc];
	new_board (board_prev);
	bag real_bag, inhand_bag;
	tile t1,t2, t3, t4;// tiles to be used for testing purposesone for the real bag and the other for hand
	real_bag = new_real_bag();//initializing the real bag
	inhand_bag = new_inhand_bag(&real_bag);// initializing the 7 tiles in posession of the player from the real bag
	
	t1 = new_tile('g');
	t2 = new_tile('o');
	t3 = new_tile('o');
	t4 = new_tile ('d');
	
	board[7][8] = &t1;
	board[7][9] = &t2;
	board[7][10] = &t3;
	board[7][11] = &t4;
	display_board(board);
	display_bag (inhand_bag);

	char new_word [word_len];
	check_board ( board , board_prev , str , & temp_score);
printf("Invalid placement \n");
}

int main (int argc , char * argv [])
{
	srand(time(NULL));
	char c;
	test_horizontal_invalid();
	printf("press enter to see the next test\n");
	scanf("%c", &c);
	test_vertical_invalid();
	printf("press enter to see the next test\n");
	scanf("%c", &c);
	
	test_empty();
	printf("press enter to see the next test\n");
	scanf("%c", &c);
	
	test_invalid1();
	printf("press enter to see the next test\n");
	scanf("%c", &c);
	
	test_invalid2();
	printf("press enter to see the next test\n");
	scanf("%c", &c);
	
	test_invalid3();
	printf("press enter to see the next test\n");
	scanf("%c", &c);
	
	test_invalid4();
	printf("press enter to see the next test\n");
	scanf("%c", &c);

	test_horizontal_valid();
	printf("press enter to see the next test\n");
	scanf("%c", &c);
	
	test_vertical_valid();
	return 0;
}