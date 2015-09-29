/**@file bag.h bag header file to specify the functions for bag of tiles that would be used to represent the bag.
* Tiles are used to initialize both real bag and tiles in the hand of the player using : bag new_real_bag (); bag new_inhand_bag( bag * real );
* Another added function is display_bag, it will be used to display the tiles in the hand of the player
* Other functions:exchange( bag * in_hand , bag * real_bag ); int is_exist ( tile t, bag b); refill_bag , is_empty , insert , withdraw
* \author Abdallah
*/
# if ! defined (BAG_H)
# define BAG_H

# include <stdio.h>
# include "tile.h"

/**
* Element of a bag is a data structure that contains a tile and a link to the next tile.
*/
struct element 
{
	tile t; /**< value to be stored in the element */
	struct element * next; /**< pointer to the next element in the bag. */
};

/**bag would represent the collection of tiles in the bag. It consists of a pointer to one of the tiles and a cursor.
*/
typedef struct
{
	struct element * head; /**< head of the bag. */
	struct element * cursor;/**< a cursor to reach any element in the bag.*/
}bag;

/**
* function to initialize the bag by setting the head and the curser to NULL.
*/
bag new_bag();

/**
* Initializes the real bag of scrabble, where 100 tiles are inserted in the bag according to the table specified in the requirements model.
*/
bag new_real_bag ();

/**
* Initializes bag of tiles in posession of the player, 7 tiles are drawn from the real bag and placed in the bag in_hand
*/

bag new_inhand_bag( bag * real );

/**
* Refills the in hand bag to contain 7 tiles after each play
* The bag must contain tiles to be able to fill the bag inhand
*/
void refill_inhand_bag ( bag * in_hand, bag * real );

/**
* Displays the tiles in the in_hand bag
*/

void display_bag ( bag in_hand);

/**
* Handles the exchange option the player can choose during the turn.
* The bag must have at least 7 tiles to execute this option.
* The player chooses tiles in his hand (one at a time) then replaces them by random tile from the real bag.
*/
void exchange( bag * in_hand , bag * real_bag );


/**
* returns true if the bag is empty 
*/
int is_empty(bag l); 

/**
* returns the number of tiles in the bag.
*/
int size_bag(bag l);

/**
* inserts the input tile in the bag.
*/
bag insert(bag l, tile tl);

/**
* Withdraws the input tile from the bag.
*/
bag withdraw(bag l, tile tl);

/**
* moves the cursor to the next element in the bag.*/
bag next (bag l);

/**
* Gets the value stored in the head of the bag.
*/
tile head (bag l);

/**
* Withdraws the input tile from the bag.*/
tile draw_random(bag * l);

/**
* the function checks the existence of a tile inside a bag.
*/

int is_exist ( tile t, bag b);
# endif