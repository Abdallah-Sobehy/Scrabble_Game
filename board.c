/** @file board.c Implementation of the functions related to scrabble board.
* \author Fred and Abdallah 
*/ 
# include <stdio.h>
# include <stdlib.h>
#include <string.h>
#include <ctype.h>
# include "tile.h"
# include "bag.h"
#include "board.h"
#include "dictionary.h"
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

/** index in the string of the added word to store the starting row number
*/
# define starting_row_index 20

/** index in the string of the added word to store the starting column number
*/
# define starting_col_index 23

/** index in the string of the added word to store the ending row number
*/
# define ending_row_index 26

/** index in the string of the added word to store the ending column number
*/
# define ending_col_index 29


    
/** new_board function returns a 2D array of pointer 2 tiles
* Each tile pointer is pointing to an empty, DL, DW, TL, TW tiles.
* /author Abdallah and Fred
*/
void  new_board(tile * board [max_rc][max_rc])
{

	tile *empty, *DL , *DW , *TL, *TW ;
	empty = (tile *)malloc(sizeof(tile)); // an imaginary tile that refers to an empty square on the board
	DL = (tile *)malloc(sizeof(tile)); //  an imaginary tile that refers to a double letter square on the board
	DW = (tile *)malloc(sizeof(tile)); // an imaginary tile that refers to a double word on the board
	TL = (tile *)malloc(sizeof(tile)); //  an imaginary tile that refers to a triple letter square on the board
	TW = (tile *)malloc(sizeof(tile)); //  an imaginary tile that refers to a triple word square on the board
	

	*empty = new_tile (' ');  // a character to represent the empty square
	*DL = new_tile ('"');
	*DW = new_tile ('=');
	*TL = new_tile ('*');
	*TW = new_tile ('^');

	int rows , cols;

	for (rows = 0; rows < max_rc; rows++)
	{
		for (cols = 0; cols < max_rc; cols++)
		{
			if(rows==0) // means we are in the first Row !
			{
				switch (cols)
				{
					case 0 :
					case 7 :
					case 14: board [rows] [cols] = TW; break;
					case 3 :
					case 11: board [rows] [cols] = DL; break;
					default : board [rows] [cols] = empty; break; 

				}

			}

			if (rows==1)
			{
				switch (cols)
				{
					case 1 :
					case 13: board[rows][cols] =  DW;break;

					case 5 :
					case 9 : board [rows][cols] =  TL; break;

					default : board[rows][cols] = empty; break;
				}
			}

			if (rows==2)
			{
				switch (cols)
				{
				  case 2:
				  case 12: board[rows][cols] = DW; break;  
				  
				  case 6:
				  case 8: board[rows][cols] = DL; break;  
				  
				  default : board[rows][cols] = empty; break;
				}
			}
			
			if (rows==3)
			{
				switch (cols)
				{
				  case 3:
				  case 11: board[rows][cols] = DW; break;  

				  case 0:
				  case 14: board[rows][cols] = DL; break ;
				  
				  case 7: board[rows][cols] = DL; break;
				  
				  default : board[rows][cols] = empty; break;
				     
				}
			}
			
			if (rows==4)
			{
				switch (cols)
				{
				  case 4:
				  case 10: board[rows][cols] = DW; break;  
				  
				   default : board[rows][cols] = empty; break;
				  
				 }
			}
			
			 if (rows==5)
			{
				switch (cols)
				{
				  case 1:
				  case 5:  
				  case 9:
				  case 13:  board[rows][cols] = TL; break; 
				    
				  default : board[rows][cols] = empty; break;
				  
				 }
			}
			
			if (rows==6)
			{
				switch (cols)
				{
				  case 2:
				  case 6:  
				  case 8:
				  case 12:  board[rows][cols] = DL; break; 
				    
				  default : board[rows][cols] = empty; break;
				  
				 }
			}
			
			if (rows==7)
			{
				switch (cols)
				{
				  case 0:
				  case 14: board[rows][cols] = TW; break;  
				  
				  case 3:
				  case 11: board[rows][cols] = DL; break; 
				  
				  case 7: board[rows][cols] = DW; break;  
				    
				  default : board[rows][cols] = empty; break;
				  
				 }
			}
			
			if (rows==8)
			{
				switch (cols)
				{
				  case 2:
				  case 6: 
				  case 8:
				  case 12: board[rows][cols] = DL; break; 
				     
				  default : board[rows][cols] = empty; break;
				  
				 }
			}
			
			if (rows==9)
			{
				switch (cols)
				{
				  case 1:
				  case 5: 
				  case 9:
				  case 13: board[rows][cols] = TL; break; 
				     
				  default : board[rows][cols] = empty; break;
				  
				 }
			}
			
			if (rows==10)
			{
				switch (cols)
				{
				  case 4:
				  case 10: board[rows][cols] = DW; break; 
				     
				  default : board[rows][cols] = empty; break;
				  
				 }
			}
			
			if (rows==11)
			{
				switch (cols)
				{
				  case 3:
				  case 11: board[rows][cols] = DW; break;
				  
				  case 0:
				  case 7:
				  case 14: board[rows][cols] = DL; break; 
				     
				  default : board[rows][cols] = empty; break;
				  
				 }
			}
			
			if (rows==12)
			{
				switch (cols)
				{
				  case 2:
				  case 12: board[rows][cols] = DW; break;
				  
				  case 6:
				  case 8: board[rows][cols] = DL; break; 
				     
				  default : board[rows][cols] = empty; break;
				  
				 }
			}
			
			if (rows==13)
			{
				switch (cols)
				{
				  case 1:
				  case 13: board[rows][cols] = DW; break;
				  
				  case 5:
				  case 9: board[rows][cols] = TL; break; 
				     
				  default : board[rows][cols] = empty; break;
				  
				 }
			}
			
			if (rows==14)
			{
				switch (cols)
				{
				  case 0:
				  case 7: 
				  case 14:board[rows][cols] = TW; break;

				  case 3:
				  case 11: board[rows][cols] = DL; break;
				     
				  default : board[rows][cols] = empty; break;
				  
				 }
			}

		}

	}

}




/** display_board function displays the scrabble board to the user.
* \author Abdallah
*/
void display_board(tile * board[max_rc] [max_rc])
{
	int rows,cols;
	printf("   ");
	for( rows = 0 ; rows < max_rc ; rows++)
		printf(" %.2i ",rows );
	printf("\n");
	

	for (rows=0 ; rows < max_rc ; rows++)
	{
		for (cols=0 ; cols < max_rc ; cols++)
		{
			if ( cols == 0 )
				printf("%.2i{ ", rows);

			printf ("[%c] ",get_letter(*board[rows][cols]) );
			
			if (cols == 14)
				printf("}\n");
		}
	}

}


/** returns the imaginary tile of the original (empty board)
* either returns an empty ( Normal tile on the board ), DL (Double Letter ), DW (Double Word ), 
* TL (Triple Letter), TW (Triple Word ) 
* \author Abdallah
*/
tile get_original (int rows , int cols)
{
	tile empty, DL , DW , TL, TW ;
	empty = new_tile (' ');  // a character to represent the empty square
	DL = new_tile ('"');
	DW = new_tile ('=');
	TL = new_tile ('*');
	TW = new_tile ('^');

			if(rows==0) // means we are in the first Row !
			{
				switch (cols)
				{
					case 0 :
					case 7 :
					case 14: return TW; break;
					case 3 :
					case 11: return DL; break;
					default : return empty; break; 

				}

			}

			if (rows==1)
			{
				switch (cols)
				{
					case 1 :
					case 13: return  DW;break;

					case 5 :
					case 9 : return  TL; break;

					default : return  empty; break;
				}
			}

			if (rows==2)
			{
				switch (cols)
				{
				  case 2:
				  case 12: return DW; break;  
				  
				  case 6:
				  case 8: return DL; break;  
				  
				  default : return empty; break;
				}
			}
			
			if (rows==3)
			{
				switch (cols)
				{
				  case 3:
				  case 11: return DW; break;  

				  case 0:
				  case 14: return DL; break ;
				  
				  case 7: return DL; break;
				  
				  default : return empty; break;
				     
				}
			}
			
			if (rows==4)
			{
				switch (cols)
				{
				  case 4:
				  case 10: return DW; break;  
				  
				   default : return empty; break;
				  
				 }
			}
			
			 if (rows==5)
			{
				switch (cols)
				{
				  case 1:
				  case 5:  
				  case 9:
				  case 13:  return TL; break; 
				    
				  default : return empty; break;
				  
				 }
			}
			
			if (rows==6)
			{
				switch (cols)
				{
				  case 2:
				  case 6:  
				  case 8:
				  case 12:  return DL; break; 
				    
				  default : return empty; break;
				  
				 }
			}
			
			if (rows==7)
			{
				switch (cols)
				{
				  case 0:
				  case 14: return TW; break;  
				  
				  case 3:
				  case 11: return DL; break; 
				  
				  case 7: return DW; break;  
				    
				  default : return empty; break;
				  
				 }
			}
			
			if (rows==8)
			{
				switch (cols)
				{
				  case 2:
				  case 6: 
				  case 8:
				  case 12: return DL; break; 
				     
				  default : return empty; break;
				  
				 }
			}
			
			if (rows==9)
			{
				switch (cols)
				{
				  case 1:
				  case 5: 
				  case 9:
				  case 13: return TL; break; 
				     
				  default : return empty; break;
				  
				 }
			}
			
			if (rows==10)
			{
				switch (cols)
				{
				  case 4:
				  case 10: return DW; break; 
				     
				  default : return empty; break;
				  
				 }
			}
			
			if (rows==11)
			{
				switch (cols)
				{
				  case 3:
				  case 11: return DW; break;
				  
				  case 0:
				  case 7:
				  case 14: return DL; break; 
				     
				  default : return empty; break;
				  
				 }
			}
			
			if (rows==12)
			{
				switch (cols)
				{
				  case 2:
				  case 12: return DW; break;
				  
				  case 6:
				  case 8: return DL; break; 
				     
				  default : return empty; break;
				  
				 }
			}
			
			if (rows==13)
			{
				switch (cols)
				{
				  case 1:
				  case 13: return DW; break;
				  
				  case 5:
				  case 9: return TL; break; 
				     
				  default : return empty; break;
				  
				 }
			}
			
			if (rows==14)
			{
				switch (cols)
				{
				  case 0:
				  case 7: 
				  case 14:return TW; break;

				  case 3:
				  case 11: return DL; break;
				     
				  default : return empty; break;
				  
				 }
			}
}


/** Checks board for the added word or words
* Checks the validity of the added tiles in terms of the position of the tiles, and existence in dictionary
* returns the added word/words if valid in the array of strings 
* \author Abdallah
*/
int check_board (tile * board [max_rc] [max_rc], tile * board_prev [max_rc] [max_rc] , char words [max_words] [word_len], int * temp_score)
{
	
	// The following code is valid only for the first play 
	if (! isalpha (get_letter( *board_prev [max_rc/2] [max_rc/2] ) ) )// this condition is sufficient to indicate that it is the first turn
		return check_first_play ( board , words[0]) ;

	else // the board is checked for nth play where n >1
	{
		int rows , cols ;
		int words_count = 0; // number of words added used to save the word in a new position in the array of strings
		char new_word [word_len]; // the word extracted from the new tile is saved here to be checked if it does not already exist in the 
		// array of strings before adding it to the array
		* temp_score = 0 ; //initializing the temp score to zero 
		int temp_temp = 0 ; // this temp score is incremented with the letters of the new word but only is added to temp_score if the word is valid and not repeated
		int DW_flag = 0 ; // Double word flag; incremented each time the word passes by a DW square
		int TW_flag = 0 ; // Triple word flag ; incremented each time the word passes by a TW square
		int starting_col;// the starting point of the column to be checked
		int starting_rows;
		int index = 0;// the position for letters to be added in a string for the added word
		int connection_flag = 0; // this flag is used to make sure at least one of the added tiles is connectd to a tile from the previous turn
		for (rows = 0; rows < max_rc; rows++)
		{
			for (cols = 0; cols < max_rc; cols++)
			{
				
				if (! is_equal ( *board [rows] [cols] , *board_prev [rows] [cols] )  ) // the first tile that wasadded this turn
				{
					if ( ! is_connected (board , rows , cols)) // not connected to any other tile on the board
					{
						printf("All the placed tiles must align in one rows or column and must be connected.\n");
						return 0;
					}
					if ( is_connected (board , rows , cols) == 1 || is_connected (board , rows , cols) == 3 )//Do this if connected horizontally or both horizontally or vertically
					{
						starting_col = horizontal_start ( board , rows , cols);
						amend_letter_right_n(board , board_prev , rows , starting_col , new_word , &index , &temp_temp, &DW_flag , &TW_flag , &connection_flag);
						int ending_col = starting_col + strlen(new_word) -1;
						delimit_string ( new_word , rows , starting_col, rows , ending_col );
						
						if ( ! word_repeated ( new_word , words , words_count))
						{
							if (connection_flag == 0)
							{
								printf("The added tiles must at least touch one already existing tile.\n");
								return 0;
							}
							printf("horizontally connected\n");
							if (word_exist (new_word))
							{
								strcopy ( words [words_count] , new_word );
								words_count ++; // the word is stored in the array of strings so move to the new position
								*temp_score += temp_temp * power(2,DW_flag) * power(3,TW_flag);
								printf("The added score for the word %s is %d cumulative added score is %d \n",new_word , temp_temp ,*temp_score );
								temp_temp = 0; // reset temp_temp in case there is another word is found
								DW_flag = 0;
								TW_flag = 0;
								index = 0;
							}
							else
							{
								printf("The word %s does NOT exist in the dictionary\n", new_word );
								return 0;
							}	
						}						
					}
					if ( is_connected (board , rows , cols) == 2 || is_connected (board , rows , cols) == 3)//If connected vertically or connected vertically and horizontally
					{

						starting_rows = vertical_start ( board , rows , cols);
						amend_letter_bottom_n( board , board_prev ,  starting_rows , cols, new_word , &index , &temp_temp, &DW_flag , &TW_flag , &connection_flag );
						int ending_rows = starting_rows + strlen(new_word) -1;
						delimit_string (new_word , starting_rows , cols , ending_rows , cols );
						if ( ! word_repeated ( new_word , words , words_count))
						{
							if (connection_flag == 0)
							{
								printf("The added tiles must at least touch one already existing tile.\n");
								return 0;
							}
							printf("vertically connected\n");
							if (word_exist (new_word))
							{
								strcopy ( words [words_count] , new_word );
								words_count ++; // the word is stored in the array of strings so move to the new position
								*temp_score += temp_temp * power(2,DW_flag) * power(3,TW_flag);
								printf("The added score for the word %s is %d cumulative added score is %d \n",new_word , temp_temp ,*temp_score );
								temp_temp = 0; // reset temp_temp in case there is another word is found
								DW_flag = 0;
								TW_flag = 0;
								index = 0;
							}
							else
							{
								printf("The word %s does NOT exist in the dictionary\n", new_word );
								return 0;
							}	
						}
				
					}
				}
			}
		}
		print_words (words , words_count);

	}

}


/** for the nth play where n > 1 the function returns the horizontal starting point of a word
* Used by the check_board function to know where to start amending to right
* returns the column number that the word starts at
* @param [in] board The current board
* @param [in] i the row number where the new tile was found
* @param [in] j the column number where the new tile was found
* @see check_board
* \author Abdallah
*/
int horizontal_start ( tile *board[max_rc][max_rc] , int rows , int cols)
{
	if(isalpha ( get_letter(*board [rows] [cols - 1] ) ) )
	{
		return horizontal_start ( board, rows , cols - 1);
	}
	else return cols;
}

/** for the nth play where n > 1 the function returns the vertical starting point of a word
* Used by the check_board function to know where to start amending to bottom
* returns the rows number that the word starts at
* @param [in] board The current board
* @param [in] rows the rows number where the new tile was found
* @param [in] cols the column number where the new tile was found
* @see check_board
* \author Abdallah
*/
int vertical_start (tile *board[max_rc][max_rc] , int rows , int cols )
{
	if(isalpha ( get_letter(*board [ rows - 1 ] [cols] ) ) )
	{
		return vertical_start ( board, rows - 1 , cols );
	}
	else return rows;
}

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
int is_connected ( tile *board[max_rc][max_rc] , int rows  , int cols )
{
	int ret  = 0 ;
	if ( ( cols != 14 && isalpha ( get_letter ( *board [rows] [cols + 1]  ) ) ) || ( cols != 0 && isalpha ( get_letter ( *board [rows] [cols - 1]  ) ) ) ) // if it is connected horizontally
		ret += 1;
	if ( (rows != 14 && isalpha ( get_letter ( *board [rows + 1] [cols]  ) ) ) || ( rows != 0 && isalpha ( get_letter ( *board [rows - 1] [cols]  ) ) ) ) // if it is connected vertically
		ret += 2;
	return ret ; 

}


/** returns true iF the tile is connected to a tile from the previous turn
* used by check_board to ake sure that at least one of the added tiles is connected to a tile from a previous turn
*\author Abdallah
*/
int is_connected_to_prev ( tile *board_prev[max_rc][max_rc] , int rows  , int cols )
{
	if (  ( rows != 0 && isalpha(get_letter(* board_prev [ rows - 1] [cols] )) )  || ( cols != 0 && isalpha(get_letter(* board_prev [ rows ] [cols - 1] )) ) || (rows != 14 && isalpha( get_letter(* board_prev [ rows + 1] [cols] ) ) )|| ( cols != 14 && isalpha(get_letter(* board_prev [ rows ] [cols + 1] )) ) )  
		return 1;
}
/** used by check_board function to check the first play
* it is considered as a special case as: only one word is added, the word does not have to touch an already existing word
* \author Abdallah
*/
int check_first_play (tile * board [max_rc] [max_rc], char str [word_len])
{
	int words_found = 0 ; // counter for the added words in one play
	int index = 0; // index to add characters to the word whenever a valid tile is encountered
	int start_i , start_cols , end_i , end_cols; // start and end rows and column numbers for the added word
	str[0] = '\0';// starting with the state that no words are found
	int rows, cols;// to traverse the whole grid
	if( ! isalpha( get_letter( *board[max_rc/2][max_rc/2]) ) )
	{
		printf("A tile must be placed on the central sqaure at [7,7] in the first turn.\n");
		return 0;
	}


	for (rows = 0; rows < max_rc; rows++)
	{
		for (cols = 0; cols < max_rc; cols++)
		{
			index = 0; // reset index
			if (isalpha(get_letter( *board [rows] [cols]) ) && words_found == 0 )
			{
				str[index] = get_letter( *board [rows] [cols]);
				index ++ ; 
				words_found ++ ;
				start_i = rows;
				start_cols = cols;
				if( cols != 14 && isalpha(get_letter( *board [rows] [cols + 1]) ) ) // checking the tile to is right
				{
					end_i = rows;// as the word is horizontal (on the same rows)
					amend_letter_right(board , rows , cols , str , &index);
					end_cols = cols + strlen(str) -1;
				}
				else if( rows != 14 && isalpha(get_letter( *board [rows + 1] [cols]) ) ) // checking the tile to is right
				{
					end_cols = cols;// as the word is vertical (on the same rows)
					amend_letter_bottom(board , rows , cols , str , &index);
					end_i = rows + strlen(str) -1;
				}

				else// only one letter 
				{
					str[1] = '\0';
				}
			}
			else if (isalpha(get_letter( *board [rows] [cols]) ) && words_found !=0 )// you found another tile after amending a word !
			{
				if ( ! ( (rows >= start_i && rows <= end_i) && (cols >= start_cols && cols <= end_cols) ) ) // the found tile is not in the range of the found word
				{
					str[0] = '\0';// the computed word will be discarded, an empty string is returned
					printf("All the placed tiles must align in one rows or column and must be connected. \n");
					return 0;
				}
			}
		}
	}

	if(strlen(str) == 0)
	{
		printf("No tiles were placed on the board. Choose pass if you can not place a word.\n");
		return 0;
	}
	else if(strlen(str) == 1)
	{
		printf("You can not form a word with one tile.\n");
		return 0;
	}
	else
	{
		if(word_exist(str))
			return 1;
		else
		{
			printf("The word '%s' does NOT exist in the dictionary. \n", str);
			return 0;
		}
	}
}


/** used by check_first_play function, gets the letter in the tile to the right and amends it to the string 
* @param [in] index is the index of the letters inside the formed string,used to add letters correctly
* @param [in] str the string where the word will be saved
* Recusrively continues until the string is amended with all letters aligned horizontally @see check_first_play
* \author Abdallah
*/
void amend_letter_right(tile * board [max_rc] [max_rc] ,int rows ,int cols ,char str [word_len] ,int * index)
{
	str [*index] = get_letter (*board [rows][cols+1]);
	(*index) ++;
	cols++;
	if( cols != 14 && isalpha(get_letter( *board [rows] [cols + 1]) ) )
	{
		amend_letter_right(board ,rows , cols ,str, index);
	}
	else
		str[*index]='\0';//End of word
	return;
}


/** Gets the letter in the tile to the right and amends it to the string for the nth play where n > 1
* Recusrively continues until the string is amended with all letters aligned horizontally
* used inside check_board function to help getting the added word @see check_board
* \author Abdallah 
*/
void amend_letter_right_n(tile * board [max_rc] [max_rc] , tile * board_prev [max_rc] [max_rc]  ,int rows ,int cols ,char str [word_len] ,int * index , int * temp_temp , int * DW_flag , int * TW_flag, int *connection_flag)
{
	str [*index] = get_letter (*board [rows][cols]);
	if (is_connected_to_prev(board_prev , rows, cols))
		*connection_flag =1;
	if ( board [rows] [cols] != board_prev [rows] [cols] )// if the tile is added in this turn then the special squares can be in effect
		*temp_temp += (get_score( *board [rows] [cols] ) * get_score( get_original ( rows , cols ) ) );
	else *temp_temp += (get_score( *board [rows] [cols] ) ); // the score of the tile is added without consideration to the special square

	if (get_letter ( get_original ( rows , cols )) == '=' && board [rows] [cols] != board_prev [rows] [cols] ) // a tile added in this turn that passes DW square
		*DW_flag =1;
		//*DW_flag +=1;
	if (get_letter ( get_original ( rows , cols )) == '^' && board [rows] [cols] != board_prev [rows] [cols] )
		*TW_flag =1;
		//*TW_flag +=1;
	
	(*index) ++;
	cols++;
	if( cols != 15 && isalpha(get_letter( *board [rows] [cols]) ) )
	{
		amend_letter_right_n(board , board_prev ,rows , cols ,str, index, temp_temp , DW_flag , TW_flag , connection_flag);
	}
	else
	{
		str[*index]='\0';//End of word
		*index = 0 ;
	}
	return;

}


/** Gets the letter in the tile to the bottom and amends it to the string for the nth play where n > 1
* Recusrively continues until the string is amended with all letters aligned horizontally
* used inside check_board function to help getting the added word @see check_board
* \author Abdallah
*/
void amend_letter_bottom_n(tile * board [max_rc] [max_rc] , tile * board_prev [max_rc] [max_rc]  ,int rows ,int cols ,char str [word_len] ,int * index , int * temp_temp, int * DW_flag , int * TW_flag, int *connection_flag)
{
	str [*index] = get_letter (*board [rows][cols]);
	if (is_connected_to_prev(board_prev , rows, cols))
		*connection_flag =1;
	if ( board [rows] [cols] != board_prev [rows] [cols] )// if the tile is added in this turn then the special squares can be in effect
		*temp_temp += (get_score( *board [rows] [cols] ) * get_score( get_original ( rows , cols ) ) );
	else *temp_temp += (get_score( *board [rows] [cols] ) ); // the score of the tile is added without consideration to the special square

	if (get_letter ( get_original ( rows , cols )) == '=' && board [rows] [cols] != board_prev [rows] [cols] ) // a tile added in this turn that passes DW square
		*DW_flag =1;
		//*DW_flag +=1;
	if (get_letter ( get_original ( rows , cols )) == '^' && board [rows] [cols] != board_prev [rows] [cols] )
		*TW_flag =1;
		//*TW_flag +=1;
	
	
	(*index) ++;
	rows ++ ;
	if( rows != 15 && isalpha(get_letter( *board [rows] [cols]) ) )
	{
		amend_letter_bottom_n(board , board_prev ,rows , cols ,str, index, temp_temp , DW_flag , TW_flag, connection_flag);
	}
	else
	{
		str[*index]='\0';//End of word
		*index = 0 ;
	}
	return;
}



/** used by check_first_play function, Gets the letter in the tile to the bottom and amends it to the string
* Recusrively continues until the string is amended with all letters aligned vertically @see check_first_play
* \author Abdallah
*/
void amend_letter_bottom(tile * board [max_rc] [max_rc] ,int rows ,int cols ,char str [word_len] ,int * index)
{
	str [*index] = get_letter (*board [rows+1][cols]);
	(*index) ++;
	rows++;
	if( rows != 14 && isalpha(get_letter( *board [rows + 1] [cols]) ) )
	{
		amend_letter_bottom(board ,rows , cols ,str, index);
	}

	else
		str[*index]='\0';// End of word
	return;
}

/*  Asks player to place tile on the board and checks whether tile to be placed corresponds to any 
 * of the tiles in the player's hand. Also request player to enter index to place the tile.
 * \author Fred
 */
bag place_tile( bag in_hand, tile *board[max_rc][max_rc], int *temp_score, int *DW_flag, int *TW_flag){
      
    if ( is_empty( in_hand) )
    {
      printf(" You do not have any tiles to place on the board\n ");
      return in_hand;
    }
     char c, ch;
     int rows, cols;
     tile * tile_ptr;
     tile_ptr = (tile *) malloc (sizeof( tile));
     
        printf("Please enter the character : ");
	while (1)
	{
	    do
		scanf("%c", &c);
		while ( ! isalpha ( c ) && c != '_') ;

	    *tile_ptr = new_tile(c);
	      if ( is_exist( *tile_ptr, in_hand )){
	      in_hand = withdraw(in_hand, *tile_ptr);
		if ( blank_tile (*tile_ptr) ){
		  *tile_ptr = assign_char(*tile_ptr);
		  }
	      printf("Please enter the rows to place the tile : " );
		    scanf("%i", &rows);
		  while ( rows < 0 || rows > 14 )
		  {
			printf("Row number out of range\n");
			printf("Please enter a valid rows number : \n");
			scanf("%i", &rows);
	     }
	      printf("Please enter the column to place the tile : " );
	      scanf("%i", &cols);  
		      while ( rows < 0 || rows > 14 ){
			printf("Column number out of range.\n");
			printf("Please enter a valid column number : \n");
			scanf("%i", &cols);
			
	      }
	      break;
	    }
	    else{
	      printf("Please enter a letter in your possession\n");
	    } 
	}
          
        
	  ch = get_letter(*board[rows][cols]);
	  // ch_new = board[i][cols];
	  
	  if (ch == ' '){
	    board[rows][cols] = tile_ptr;
	    *temp_score += get_score(*tile_ptr);
	   }
	 else if (ch == '"' ){
	   board[rows][cols] = tile_ptr;
	   *temp_score += 2*get_score(*tile_ptr);
	}
	 else if (ch == '=' ){
	   board[rows][cols] = tile_ptr;
	   *temp_score += get_score(*tile_ptr);
	   *DW_flag += 1;
	}
	else if (ch == '*' ){
	   board[rows][cols] = tile_ptr;
	   *temp_score += 3*get_score(*tile_ptr);
	   }
	  else if (ch == '^' ){
	   board[rows][cols] = tile_ptr;
	   *temp_score += get_score(*tile_ptr);
	     *TW_flag += 1;
	  }
	  
	  else {
	    printf("You cannot place a tile on a tile\n");
	    in_hand = insert(in_hand, *tile_ptr);
	  }
	  
	  return in_hand;
}
    

/**
 * Request player for index to remove tile from the board. This tile should be in the same turn of play.
 * After successful removal of tile temp_score is decremented accordingly. 
 * \author Fred
 */
bag pickup_tile(bag in_hand, tile *board[max_rc][max_rc], int *temp_score, int *DW_flag, int *TW_flag){
      
     
	char c, ch;
	tile *t;
	int rows, cols;
	 tile * tile_ptr, *special_tile_ptr;
	 tile_ptr = (tile *) malloc (sizeof( tile));
	  t = (tile *) malloc (sizeof( tile));
       printf("Please enter rows to pick up letter from : " );
       scanf("%d", &rows);
       
       while ( rows < 0 || rows > 14 )
		  {
			printf("Row number out of range\n");
			printf("Please enter a valid rows number : \n");
			scanf("%d", &rows);
	     }
	      printf("Please enter the column to pick up letter from : " );
	      scanf("%i", &cols);  
		      while ( rows < 0 || rows > 14 ){
			printf("Column number out of range.\n");
			printf("Please enter a valid column number : \n");
			scanf("%d", &cols);
       
      }  
	      char character;
	    *t = get_original (rows , cols); 
	    if ( blank_tile(*board[rows][cols]) ){
		 *board[rows][cols] = new_tile ('_');
	      }
	      character = get_letter(*board[rows][cols]);
	    
	    if ( ! isalpha ( get_letter ( *board[rows][cols]) ) && character != '_' ) 
	    {
		printf( "Sorry, no tile exist in this index \n");
		
		 return in_hand;
	    }
	    else
	    {
	       *tile_ptr = *board[rows][cols];
		board[rows][cols] = t;
		ch = get_letter(*t);
		
		switch (ch)
		{
		  case(' '):         // Checks if the tile on the board is normal tile and calculates the score accordingly
	    in_hand = insert(in_hand, *tile_ptr);   
	    *temp_score -= get_score(*tile_ptr);
	      break;
	      
		  case('"'):        // Checks if the tile on the board is Double Letter(DL) tile and calculates the score accordingly
	   in_hand = insert(in_hand, *tile_ptr);  
	   *temp_score -= 2*get_score(*tile_ptr);
	   break;
	
		  case('='):       // Checks if the tile on the board is Double Word(DW) tile and calculates the score accordingly
	    in_hand = insert(in_hand, *tile_ptr); 
	   *temp_score -= get_score(*tile_ptr);
	   *DW_flag -= 1;
	   break;
	
		  case ('*'):    // Checks if the tile on the board is Triple Letter(TL) tile and calculates the score accordingly
	    in_hand = insert(in_hand, *tile_ptr);   
	   *temp_score -= 3*get_score(*tile_ptr);
	   break;
	   
		  case('^'):     // Checks if the tile on the board is Triple Word(TW) tile and calculates the score accordingly 
	     in_hand = insert(in_hand, *tile_ptr);   
	   *temp_score -= get_score(*tile_ptr);
	     *TW_flag -= 1;
	     break;
	  
		  default:        // If letter to be picked cannot be found.
	    printf("You cannot find tile\n");
	  }
	  	 
	  return in_hand;
   }
}

	  
/**
 * When the player chooses to play his turn, if the added word is valid in terms of position and existence in the dictionary
 * The score of the player is updated with the information of the temp_score and the DW and TW flags
 * used only in the first play @see check_first_play
 * \author Abdallah
 */
 int update_score( int score , int * tmp_score , int * DW_flag, int * TW_flag)
 {
 	score += *tmp_score * power(2,*DW_flag) * power(3,*TW_flag);
 	*DW_flag = 0;
 	*TW_flag = 0;
 	* tmp_score = 0;
 	return score;
 }

 /**Power function to return x^n to be used by update_score function @see update_score
 * \author Abdallah
 */
int power ( int x,  int n)
{
	if(n==0)
		return 1;
	if(n==1)
		return x;
	return x * power(x , n-1);
}

/** copy the content of the first input board into the second input board
*  \author Abdallah
*/
void copy_board( tile * copy [max_rc][max_rc] , tile * paste [max_rc][max_rc] )
{
	int rows , cols;
	for (rows = 0; rows < max_rc; ++rows)
	{
		for (cols = 0; cols < max_rc; ++cols)
		{
			paste [rows] [cols] = copy [rows] [cols] ; 
		}
	}
}


/** prints all words stored in the array of strings
* mainly for testing uses
* \author Abdallah
*/
void print_words (char words [max_words] [word_len] , int words_count)
{
	int rows;
	for ( rows = 0; rows < words_count; ++rows)
	{
		printf("%s\n",words [rows] );
	}
}


/** saves the starting and ending indices ( rows and col number ) 
* in the position [20] for starting rows number and [23] for starting col number
* in position [26] for ending rows number and [29] for ending col number
*/

void delimit_string (char word [word_len] , int start_i , int start_cols , int end_i , int end_cols )
{
	word [starting_row_index] = (char) (((int)'0')+ (start_i / 10) );//to store the thenth of the number
	word [starting_row_index +1] = (char) (((int)'0')+(start_i % 10) ) ;// to store the units of the number
	word [starting_row_index +2] = '\0';

	word [starting_col_index] = (char) (((int)'0')+( start_cols /10) );
	word [starting_col_index + 1] = (char) (((int)'0')+(start_cols %10) );
	word [starting_col_index + 2] = '\0';


	word [ending_row_index] = (char) (((int)'0')+( end_i / 10) );
	word [ending_row_index + 1] = (char) (((int)'0')+( end_i % 10) );
	word [ending_row_index +2] = '\0';


	word [ending_col_index] = (char) (((int)'0')+(end_cols /10) );
	word [ending_col_index + 1] = (char) (((int)'0')+(end_cols % 10) );
	word [ending_col_index + 2 ] = '\0';

}


/** gets the starting row number for a word stored in the mentioned position in the string 
* @see starting_row_index
* \author Abdallah
*/
int get_starting_rows (char word [word_len])
{
	return atoi (& word [starting_row_index]);
}


/** gets the starting col number for a word stored in the mentioned position in the string 
* @see starting_col_index
* \author Abdallah
*/
int get_starting_col (char word [word_len])
{
	return atoi (& word [starting_col_index]);
}

/** gets the ending row number for a word stored in the mentioned position in the string 
* @see ending_row_index
* \author Abdallah
*/
int get_ending_rows (char word [word_len])
{
	return atoi (& word [ending_row_index]);
}

/** gets the ending col number for a word stored in the mentioned position in the string 
* @see ending_col_index
* \author Abdallah
*/
int get_ending_col (char word [word_len])
{
	return atoi (& word [ending_col_index]);
}


/** returns true if the word already exist in the array of strings
* \author Abdallah
*/
int word_repeated ( char new_word [word_len] , char words [max_words] [ word_len ] ,int words_count )
{
	if (words_count == 0)
		return 0 ; // if there are no words in the array then the word is not repeated
	int rows;
	for (rows = 0; rows < words_count; ++rows)
	{

		if ( get_starting_rows (words [rows] ) == get_starting_rows ( new_word ) && get_starting_col (words [rows] ) == get_starting_col ( new_word ) && get_ending_rows (words [rows] ) == get_ending_rows ( new_word ) && get_ending_col (words [rows] ) == get_ending_col ( new_word )  )
			return 1;
	}
	return 0 ;
}


/** copies the second input string into the first one because the strcop will not be sufficient as the strings used here have more than one \0
* \author Abdallah
*/
void strcopy (char str1 [word_len] , char str2 [word_len] )
{
	int rows;
	for ( rows = 0; rows < word_len; ++rows)
	{
		str1[rows] = str2[rows];
	}

}