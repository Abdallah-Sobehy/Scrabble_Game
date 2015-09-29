/** @file ui.h user interface functions that is in a form of a menu. 
\author Abdallah
*/

# if ! defined (UI_H)
# define UI_H

/* menu displays the first menu for the user when the game opens.
* Provides a brief about scrabble game.
* offers the choice to a 1-new game, 2-language choice, 3-reading the rules, 4-exiting the game
* returns the choice of the user.
*/
int menu() ; 

/*
* new_game() function is the core function of scrabble where the board, bag are initialized and displayed.
* The scrabble game is started interactively with the user
*/
void new_game();

/*
* menu_1 is the first option in the main menu: menu() which is new game
* offers the choice to 1-place/pick up a tile, 2- exchange tiles, 3- pass, 4- quit game
* returns the choice of the user.
* @see menu
*/
int menu_1();






# endif