/** @file main.c For testing scrabble in real time execution
* \author Abdallah
*/
# include <stdio.h>
# include <stdlib.h>
# include "tile.h"
# include "bag.h"
#include "board.h"
# include "ui.h"


int main (int argc , char* argv [])
{
	srand(time(NULL));
	int choice;
	while (1)
	{
		choice = menu();

		switch (choice)
		{
			case 1:
				new_game();
				break;

			case 2:
				printf("Call choose_language function.\n");//call new_game() function
				break;

			case 3:
				printf("Call display_rules() function.\n");//call new_game() function
				break;

			case 4:
				break;
			
			default: 
				printf("Please enter a valid choice.\n");//call new_game() function
				break;
			
		}
		if(choice == 4)
			break;
	}

return 0;
}
