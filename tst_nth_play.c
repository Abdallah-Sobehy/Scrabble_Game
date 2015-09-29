/** @file tst_nth_play.c tests the nth play after the first play 
* the board can be at any state of valid words then some tiles are added to the already existing tiles
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
# define max_word

/**
* second play is tested over a valid first play word
* the second play adds one word to the board but amending tiles to the existing wordto form a new word
*/
char str [max_words] [word_len];
int temp_score;

void test_second_valid ()
{
	tile * board [max_rc] [max_rc];
	new_board(board);
	tile * board_prev [max_rc] [max_rc];
	new_board (board_prev);
	tile t1,t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15;
	t1 = new_tile('f');
	t2 = new_tile('i');
	t3 = new_tile('l');
	t4 = new_tile ('l');
	t5 = new_tile('e');
	t6 = new_tile('d');
	t7 = new_tile('y');
	t8 = new_tile ('s');
	t9 = new_tile('t');
	t10 = new_tile('a');
	t11= new_tile('l');
	t12= new_tile ('l');
	t13= new_tile ('i');
	t14= new_tile ('n');
	t15= new_tile ('e');
	board_prev[7][7] = &t1;
	board_prev[7][8] = &t2;
	board_prev[7][9] = &t3;
	board_prev[7][10] = &t4;

	board[7][7] = &t1;
	board[7][8] = &t2;
	board[7][9] = &t3;
	board[7][10] = &t4;

	board[7][11] = &t5;
	board[7][12] = &t6;
	printf("Board before second play\n");
	display_board (board_prev);

	printf("Board after second play\n");
	display_board (board);

	check_board ( board , board_prev , str , &temp_score );
	printf("Expected added value : 11\nF(4) + I(1) + L (1) + L (1) +E (1)*2 + D (2) \n");
	temp_score = 0;

}


/**
* second play is tested over a valid first play word
* the second play adds two words to the board by amending tiles to the existing word to form 2 new words
\author Abdallah
*/
void test_second_valid2 ()
{
	tile * board [max_rc] [max_rc];
	new_board(board);
	tile * board_prev [max_rc] [max_rc];
	new_board (board_prev);
	tile t1,t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15;
	t1 = new_tile('f');
	t2 = new_tile('i');
	t3 = new_tile('l');
	t4 = new_tile ('l');
	t5 = new_tile('s');
	t6 = new_tile('a');
	t7 = new_tile('d');
	
	board_prev[7][7] = &t1;
	board_prev[7][8] = &t2;
	board_prev[7][9] = &t3;
	board_prev[7][10] = &t4;

	board[7][7] = &t1;
	board[7][8] = &t2;
	board[7][9] = &t3;
	board[7][10] = &t4;

	board[7][11] = &t5;
	board[8][11] = &t6;
	board[9][11] = &t7;
	printf("Board before second play\n");
	display_board (board_prev);

	printf("Board after second play\n");
	display_board (board);

	check_board ( board , board_prev , str , &temp_score );
	printf("Expected added value : 14\n F (4) + I (1) + L (1) + L (1) + S (1)*2 = 9 \n s (1)*2 + A (1) + D (2) = 5\n");
	temp_score = 0;
}

/**
* second play is tested over first play
* the second play adds 3 words to the board by amending tiles to the existing word to form 3 new words
*\author Abdallah
*/
void test_second_valid3()
{
	tile * board [max_rc] [max_rc];
	new_board(board);
	tile * board_prev [max_rc] [max_rc];
	new_board (board_prev);
	tile t1,t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15;
	t1 = new_tile('h');
	t2 = new_tile('a');
	t3 = new_tile('s');
	t4 = new_tile ('r');
	t5 = new_tile('e');
	t6 = new_tile('m');
	t7 = new_tile('d');
	
	board_prev[7][7] = &t1;
	board_prev[8][7] = &t2;
	board_prev[9][7] = &t3;

	board[7][7] = &t1;
	board[8][7] = &t2;
	board[9][7] = &t3;

	board[6][8] = &t4;
	board[7][8] = &t5;
	board[8][8] = &t6;
	printf("Board before second play\n");
	display_board (board_prev);

	printf("Board after second play\n");
	display_board (board);

	check_board ( board , board_prev , str , &temp_score );
	printf("Expected value : 21\nR(1)*2 + E(1) + M(3)*2 = 9\nH(4) + E (1) =5 \nA(1) + M(3)*2 = 7\n");
}


/**
* second play is tested over first play
* the second play adds 4 words to the board by amending tiles to the existing word to form 4 new words
* this give me a huge error but from the analysis I can assume it is from the part when the the char is changed to int and vice versa because if the tenth is changed from 1 to 0 the answer would be correct
*\author Abdallah
*/
void test_second_valid4()
{
	tile * board [max_rc] [max_rc];
	new_board(board);
	tile * board_prev [max_rc] [max_rc];
	new_board (board_prev);
	tile t1,t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15;
	t1 = new_tile('h');
	t2 = new_tile('a');
	t3 = new_tile('i');
	t8 = new_tile('r');
	t4 = new_tile ('r');
	t5 = new_tile('e');
	t6 = new_tile('m');
	t7 = new_tile('s');
	
	board_prev[7][7] = &t1;
	board_prev[7][8] = &t2;
	board_prev[7][9] = &t3;
	board_prev[7][10] = &t8;


	board [7][7] = &t1;
	board [7][8] = &t2;
	board [7][9] = &t3;
	board [7][10] = &t8;

	board[8][6] = &t4;
	board[8][7] = &t5;
	board[8][8] = &t6;
	board[8][9] = &t7;

	printf("Board before second play\n");
	display_board (board_prev);

	printf("Board after second play\n");
	display_board (board);

	check_board ( board , board_prev , str , &temp_score );
	printf("Expected value is 10 + 5 + 7 + 2 = 24 \n");
}

/**
* second play is tested over first play
* the second play adds a word that does not exist in the dictionary
*\author Abdallah
*/
void test_second_invalid()
{
	tile * board [max_rc] [max_rc];
	new_board(board);
	tile * board_prev [max_rc] [max_rc];
	new_board (board_prev);
	tile t1,t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15;
	t1 = new_tile('h');
	t2 = new_tile('a');
	t3 = new_tile('i');
	t8 = new_tile('r');
	t4 = new_tile ('r');
	t5 = new_tile('g');
	t6 = new_tile('m');
	t7 = new_tile('s');
	
	board_prev[7][7] = &t1;
	board_prev[7][8] = &t2;
	board_prev[7][9] = &t3;
	board_prev[7][10] = &t8;


	board [7][7] = &t1;
	board [7][8] = &t2;
	board [7][9] = &t3;
	board [7][10] = &t8;

	board[8][6] = &t4;
	board[8][7] = &t5;
	board[8][8] = &t6;
	board[8][9] = &t7;

	printf("Board before second play\n");
	display_board (board_prev);

	printf("Board after second play\n");
	display_board (board);

	check_board ( board , board_prev , str , &temp_score );
}

/**
* second play is tested over first play
* the second play adds a word that exists in the dictionary but is nor properly connected
*\author Abdallah
*/
void test_second_invalid2()
{
	tile * board [max_rc] [max_rc];
	new_board(board);
	tile * board_prev [max_rc] [max_rc];
	new_board (board_prev);
	tile t1,t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15;
	t1 = new_tile('h');
	t2 = new_tile('a');
	t3 = new_tile('s');
	t4 = new_tile ('r');
	t5 = new_tile('e');
	t6 = new_tile('m');
	t7 = new_tile('d');
	
	board_prev[7][7] = &t1;
	board_prev[8][7] = &t2;
	board_prev[9][7] = &t3;

	board[7][7] = &t1;
	board[8][7] = &t2;
	board[9][7] = &t3;

	board[6][1] = &t4;
	board[7][1] = &t5;
	board[8][1] = &t6;
	printf("Board before second play\n");
	display_board (board_prev);

	printf("Board after second play\n");
	display_board (board);

	check_board ( board , board_prev , str , &temp_score );
}


/**
* nth play where the board is in a valid state that can occur after more than one play and a tile is added to add 2 words one horizontal and one vertical
* \author Abdallah
*/
void test_nth_valid()
{
	tile * board [max_rc] [max_rc];
	new_board(board);
	tile * board_prev [max_rc] [max_rc];
	new_board (board_prev);
	tile t1,t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15;
	t1 = new_tile('c');
	t2 = new_tile('l');
	t3 = new_tile('a');
	t8 = new_tile('n');
	t4 = new_tile ('n');
	t5 = new_tile('o');
	t6 = new_tile('n');
	t7 = new_tile('s');
	
	board_prev[7][7] = &t1;
	board_prev[7][8] = &t2;
	board_prev[7][9] = &t3;
	board_prev[7][10] = &t8;
	board_prev[8][10] = &t5;
	board_prev[9][10] = &t6;
	


	board [7][7] = &t1;
	board [7][8] = &t2;
	board [7][9] = &t3;
	board [7][10] = &t8;

	board[8][10] = &t5;
	board[9][10] = &t6;
	

	board[8][9] = &t7;

	printf("Board before second play\n");
	display_board (board_prev);

	printf("Board after second play\n");
	display_board (board);

	check_board ( board , board_prev , str , &temp_score );
	printf("The expected added score is 2+ 2 = 4\n");
}

/**
* nth play where the board is in a valid state that can occur after more than one play and a tile is added to add 2 words one horizontal and one vertical but does not exist in the dictionary
* \author Abdallah
*/
void test_nth_invalid()
{
	tile * board [max_rc] [max_rc];
	new_board(board);
	tile * board_prev [max_rc] [max_rc];
	new_board (board_prev);
	tile t1,t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15;
	t1 = new_tile('c');
	t2 = new_tile('l');
	t3 = new_tile('a');
	t8 = new_tile('n');
	t4 = new_tile ('n');
	t5 = new_tile('o');
	t6 = new_tile('n');
	t7 = new_tile('x');
	
	board_prev[7][7] = &t1;
	board_prev[7][8] = &t2;
	board_prev[7][9] = &t3;
	board_prev[7][10] = &t8;
	board_prev[8][10] = &t5;
	board_prev[9][10] = &t6;
	


	board [7][7] = &t1;
	board [7][8] = &t2;
	board [7][9] = &t3;
	board [7][10] = &t8;

	board[8][10] = &t5;
	board[9][10] = &t6;
	

	board[8][9] = &t7;

	printf("Board before second play\n");
	display_board (board_prev);

	printf("Board after second play\n");
	display_board (board);

	check_board ( board , board_prev , str , &temp_score );
}

/**
* nth play where the board is in a valid state that can occur after one or more plays the added tiles are valid and pass by a double word square
* \author Abdallah
*/
void test_nth_valid2()
{
	
	tile * board [max_rc] [max_rc];
	new_board(board);
	tile * board_prev [max_rc] [max_rc];
	new_board (board_prev);
	tile t1,t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15;
	t1 = new_tile('c');
	t2 = new_tile('l');
	t3 = new_tile('a');
	t8 = new_tile('n');
	t4 = new_tile ('n');
	t5 = new_tile('o');
	t6 = new_tile('n');
	t7 = new_tile('e');
	
	board_prev[7][7] = &t1;
	board_prev[7][8] = &t2;
	board_prev[7][9] = &t3;
	board_prev[7][10] = &t8;
	board_prev[8][10] = &t5;
	board_prev[9][10] = &t6;
	


	board [7][7] = &t1;
	board [7][8] = &t2;
	board [7][9] = &t3;
	board [7][10] = &t8;
	board[8][10] = &t5;
	board[9][10] = &t6;
	

	board[10][10] = &t7;

	printf("Board before second play\n");
	display_board (board_prev);

	printf("Board after second play\n");
	display_board (board);

	check_board ( board , board_prev , str , &temp_score );
	printf("Expected added score is 8\n");
}


/**
* nth play where the board is in a valid state that can occur after one or more plays the added tiles are valid and pass by a triple word square
* \author Abdallah
*/
void test_nth_valid3()
{
	tile * board [max_rc] [max_rc];
	new_board(board);
	tile * board_prev [max_rc] [max_rc];
	new_board (board_prev);
	tile t1,t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15;
	t1 = new_tile('c');
	t2 = new_tile('l');
	t3 = new_tile('a');
	t8 = new_tile('n');
	t4 = new_tile ('o');
	t5 = new_tile('v');
	t6 = new_tile('a');
	t7 = new_tile('l');

	t9 = new_tile('o');
	t10 = new_tile ('n');
	
	board_prev[7][7] = &t1;
	board_prev[7][8] = &t2;
	board_prev[7][9] = &t3;
	board_prev[7][10] = &t8;
	board_prev[6][10] = &t4;
	board_prev[6][11] = &t5;
	board_prev[6][12] = &t6;
	board_prev[6][13] = &t7;
	


	board [7][7] = &t1;
	board [7][8] = &t2;
	board [7][9] = &t3;
	board [7][10] = &t8;
	board [6][10] = &t4;
	board [6][11] = &t5;
	board [6][12] = &t6;
	board [6][13] = &t7;

	board[7][13] = &t9;
	board[7][14] = &t10;

	printf("Board before second play\n");
	display_board (board_prev);

	printf("Board after second play\n");
	display_board (board);

	check_board ( board , board_prev , str , &temp_score );
	printf("Expected added score is 8\nL(1) + O (1) =2 \n( O(1) + N (1) )*3 = 6\n");
}

int main (int argc , char * argv [] )
{
	char c;
	test_second_valid();
	printf("press enter to see the next test\n");
	scanf("%c", &c);
	test_second_valid2();
	printf("press enter to see the next test\n");
	scanf("%c", &c);

	test_second_valid3();

	printf("press enter to see the next test\n");
	scanf("%c", &c);

	test_second_valid4();

	printf("press enter to see the next test\n");
	scanf("%c", &c);
	test_second_invalid();

	printf("press enter to see the next test\n");
	scanf("%c", &c);
	test_second_invalid2();

	printf("press enter to see the next test\n");
	scanf("%c", &c);

	test_nth_valid();

	printf("press enter to see the next test\n");
	scanf("%c", &c);
	test_nth_invalid();

	printf("press enter to see the next test\n");
	scanf("%c", &c);
	test_nth_valid2();
	printf("press enter to see the next test\n");
	scanf("%c", &c);
	test_nth_valid3();
	return 0;
}