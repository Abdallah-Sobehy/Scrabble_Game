/**@file bag.c to specify the functions for bag of tiles that would be used to represent the bag.
* Tiles are used to initialize both real bag and tiles in the hand of the player using : bag new_real_bag (); bag new_inhand_bag( bag * real );
* Another added function is display_bag, it will be used to display the tiles in the hand of the player
* Other functions:exchange( bag * in_hand , bag * real_bag ); int is_exist ( tile t, bag b); refill_bag , is_empty , insert , withdraw
* \author Abdallah
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bag.h"
#include "tile.h"
/** maximum number of tiles in the bag in hand
*/
# define inhand_max 7 

/**
* function to initialize the bag to NULL.*/
bag new_bag()
{
	bag l;
	l.head=NULL;
	l.cursor = NULL;
	return l;
}

/**
* Initializes the real bag of scrabble, where 100 tiles are inserted in the bag according to the table specified in the requirements model.
*/
bag new_real_bag()
{
	tile *blank, *a , *b , *c , *d , *e , *f , *g , *h , *i , *j , *k , *l , *m , *n , *o , *p , *q , *r , *s , *t , *u , *v , *w , *x , *y , *z;
	blank = (tile*)malloc(sizeof(tile));
	a = (tile*)malloc(sizeof(tile));
	b = (tile*)malloc(sizeof(tile));
	c = (tile*)malloc(sizeof(tile));
	d = (tile*)malloc(sizeof(tile));
		e = (tile*)malloc(sizeof(tile));
	f = (tile*)malloc(sizeof(tile));
	g = (tile*)malloc(sizeof(tile));
	h = (tile*)malloc(sizeof(tile));
	i = (tile*)malloc(sizeof(tile));
		j = (tile*)malloc(sizeof(tile));
	k = (tile*)malloc(sizeof(tile));
	l = (tile*)malloc(sizeof(tile));
	m = (tile*)malloc(sizeof(tile));
	n = (tile*)malloc(sizeof(tile));
		o = (tile*)malloc(sizeof(tile));
	p = (tile*)malloc(sizeof(tile));
	q = (tile*)malloc(sizeof(tile));
	r = (tile*)malloc(sizeof(tile));
	s = (tile*)malloc(sizeof(tile));
		t = (tile*)malloc(sizeof(tile));
	u = (tile*)malloc(sizeof(tile));
	v = (tile*)malloc(sizeof(tile));
	w = (tile*)malloc(sizeof(tile));
	x = (tile*)malloc(sizeof(tile));
	y = (tile*)malloc(sizeof(tile));
	z = (tile*)malloc(sizeof(tile));

	* blank = new_tile ('_');
	* a= new_tile ('A');
	* b= new_tile ('B');
	* c= new_tile ('C');
	* d= new_tile ('D');
	* e= new_tile ('E');

	* f= new_tile ('F');
	* g= new_tile ('G');
	* h= new_tile ('H');
	* i= new_tile ('I');
	* j= new_tile ('J');

	* k= new_tile ('K');
	* l= new_tile ('L');
	* m= new_tile ('M');
	* n= new_tile ('N');
	* o= new_tile ('O');

	* p= new_tile ('P');
	* q= new_tile ('Q');
	* r= new_tile ('R');
	* s= new_tile ('S');
	* t= new_tile ('T');

	* u= new_tile ('U');
	* v= new_tile ('V');
	* w= new_tile ('W');
	* x= new_tile ('X');
	* y= new_tile ('Y');
	* z= new_tile ('Z');

	bag  real_bag;
	//real_bag = (bag*)malloc(sizeof(bag));
	real_bag = new_bag();
	int loop;
	real_bag = insert ( real_bag , *blank);
	real_bag = insert ( real_bag , *blank);
	for (loop = 0; loop < 9; loop++)
	{
		real_bag = insert ( real_bag , *a);
	}
	for (loop = 0; loop < 12; loop++)
	{
		real_bag = insert ( real_bag , *e);
	}
	for (loop = 0; loop < 9; loop++)
	{
		real_bag = insert ( real_bag , *i);
	}
	for (loop = 0; loop < 8; loop++)
	{
		real_bag = insert ( real_bag , *o);
	}
	for (loop = 0; loop < 6; loop++)
	{
		real_bag = insert ( real_bag , *n);
	}
	for (loop = 0; loop < 6; loop++)
	{
		real_bag = insert ( real_bag , *r);
	}
	for (loop = 0; loop < 6; loop++)
	{
		real_bag = insert ( real_bag , *t);
	}
	for (loop = 0; loop < 4; loop++)
	{
		real_bag = insert ( real_bag , *l);
	}
	for (loop = 0; loop < 4; loop++)
	{
		real_bag = insert ( real_bag , *s);
	}
	for (loop = 0; loop < 4; loop++)
	{
		real_bag = insert ( real_bag , *u);
	}
	for (loop = 0; loop < 4; loop++)
	{
		real_bag = insert ( real_bag , *d);
	}
	for (loop = 0; loop < 3; loop++)
	{
		real_bag = insert ( real_bag , *g);
	}
	for (loop = 0; loop < 2; loop++)
	{
		real_bag = insert ( real_bag , *b);
	}
	for (loop = 0; loop < 2; loop++)
	{
		real_bag = insert ( real_bag , *c);
	}
	for (loop = 0; loop < 2; loop++)
	{
		real_bag = insert ( real_bag , *m);
	}
	for (loop = 0; loop < 2; loop++)
	{
		real_bag = insert ( real_bag , *p);
	}
	for (loop = 0; loop < 2; loop++)
	{
		real_bag = insert ( real_bag , *f);
	}
	for (loop = 0; loop < 2; loop++)
	{
		real_bag = insert ( real_bag , *h);
	}
	for (loop = 0; loop < 2; loop++)
	{
		real_bag = insert ( real_bag , *v);
	}
	for (loop = 0; loop < 2; loop++)
	{
		real_bag = insert ( real_bag , *w);
	}
	for (loop = 0; loop < 2; loop++)
	{
		real_bag = insert ( real_bag , *y);
	}
	real_bag = insert ( real_bag , *k);
	real_bag = insert ( real_bag , *j);
	real_bag = insert ( real_bag , *x);
	real_bag = insert ( real_bag , *q);
	real_bag = insert ( real_bag , *z);


	return real_bag;
}

/**
* Initializes list of tiles in posession of the player, 7 tiles are drawn from the real bag and placed in the bag in_hand
*/

bag new_inhand_bag( bag * real )
{
	int i;
	tile t;
	bag in_hand;
	in_hand = new_bag();
	for ( i = 0; i < 7; ++i)
	{
		t = draw_random(real);
		in_hand = insert (in_hand , t);
	}
	
}

/**
* Refills the in hand bag to contain 7 tiles after each play
* The bag must contain tiles to be able to fill the bag inhand
*/
void refill_inhand_bag ( bag * in_hand, bag * real )
{
	int i ;
	tile t;
	for ( i = size_bag(*in_hand) ; i < 7 ; i++)
	{
		t = draw_random(real);
		*in_hand = insert (*in_hand , t);
	}
	return;
}

/**
* Displays the tiles in the in_hand bag
*/

void display_bag ( bag in_hand)
{
	int i;
	tile tl;
	in_hand.cursor = in_hand.head;// just in case the cursor is not at the beginning.
	for (i=0 ; i < size_bag (in_hand) ; i++)
	{
			printf("[%c,",get_letter(in_hand.cursor->t) );
			printf("%i] ",get_score(in_hand.cursor->t));
			in_hand = next (in_hand);
	}
	printf("\n");
	
}

/**
* Handles the exchange option the player can choose during the turn.
* The bag must have at least 7 tiles to execute this option.
* The player chooses tiles in his hand (one at a time) then replaces them by random tile from the real bag.
*/
void exchange( bag * in_hand , bag * real_bag )
{
	if (size_bag(*real_bag) < 7)
	{
		printf("You can not exchange tiles when the bag has less than 7 tiles.\n");
		return;
	}
	else
	{
		tile remove_tile,add_tile;
		char c;
		int i ;
		int choice = 0; // 1 to exchange another tile, 0 to end the turn
		for ( i = 0 ; i < 7 ; i++)
		{

			printf("Enter the letter of the tile you want to exchange:");
			do
				scanf("%c", &c);
			while ( ! isalpha ( c ) && c != '_') ;
			remove_tile = new_tile( c );// tile created just to search the bag in_hand for existence
			if (is_exist ( remove_tile , * in_hand))
			{

				*in_hand = withdraw (*in_hand, remove_tile);
				add_tile = draw_random (real_bag);
				*in_hand = insert(*in_hand, add_tile);
				*real_bag = insert (*real_bag , remove_tile);

				printf("press 1 to exchange another tile, press 0 to end your turn.");
				scanf("%d", &choice);
				if ( choice == 0)
					return;

			}
			else
			{
				printf("Please choose one of the tiles in your posession.\n");
				i--; //so that this loop is not considered as an exchange
			}

		}
					if (i == 7 )// it means that the function didnt return so the user still chooses to replace another tile although he chose 7
			{
				printf("You can not exchange any more than 7 tiles.\n");
				return;
			}
		
	}
}

/**
* the function checks the existence of a tile inside a bag.
*/

int is_exist ( tile t, bag b)
{
	int i;
	b.cursor = b.head;// in case the cursor is not on the beginning of the bag.
	for( i = 0 ; i < size_bag(b) ; i++)
	{
		if ( is_equal(t , b.cursor -> t) )
			return 1;
		else b = next (b);
	}

	return 0;
}

/**
* returns true if the bag is empty */
int is_empty(bag l)
{
	return !(l.head);
}

/**
* returns the number of tiles in the bag.*/
int size_bag(bag l)
{
	if (is_empty(l))
		return 0;
	else 
	{
		l.cursor = l.head;
		int count = 0;
		while (l.cursor)
		{
			count++;
			l.cursor = l.cursor->next;
		}
		l.cursor = l.head;// because the cursor should not be NULL.
		return count;
	}
}

/**
* * inserts the input tile in the bag.*/
bag insert(bag l, tile tl)
{
	struct element * elm;
	elm = (struct element *)malloc(sizeof(struct element));
	elm->t = tl;
	elm->next = l.head;
	if(is_empty(l))
		l.cursor = elm; // initializing the cursor in case of first element added
	l.head = elm;
	return l;
}

/**
* Withdraws the input tile from the bag.*/
bag withdraw(bag l, tile tl)
{
	if(is_empty(l))
	{
		printf("the bag is empty\n");
		return l;
	}
	else if(is_equal(l.head->t ,tl) )
	{
		struct element *  tmp = l.head;
		l.head = l.head->next;
		l.cursor = l.head; // in case the cursor was pointing an unnallocated memory
		free(tmp);
		return l;
	}

	else
	{
		int i;
		struct element * bf_curs; //< a pointer to the element before the cursor, will be needed when to delete the element without breaking the bag */
		
		l.cursor = l.head->next;
		bf_curs = l.head;
		for (i = 0; i < size_bag(l) - 1; i++) // -1 because the head is already checked in the prev condition
		{
			if(l.cursor && is_equal(l.cursor->t,tl))
			{
				struct element * tmp = l.cursor;
				bf_curs->next = l.cursor->next;
				free(tmp);
				l.cursor=l.head;// so that the cursor does not point on an unallocted space
				return l;
			}
			else
			{
				bf_curs = l.cursor;
				l = next (l);
			}
		}
		
	}
	printf("The tile '%c' could not be found in the bag\n", get_letter(tl));
	return l;
}

/**
* moves the cursor to the next element in the bag.*/
bag next (bag l)
{
	if(!is_empty(l))
	{
		if(l.cursor->next != NULL)
			l.cursor = l.cursor->next;
		else
			l.cursor = l.head;
	
	}
	return l;
}

/**
* Gets the value stored in the head of the bag.
*/

tile head (bag l)
{
	if(is_empty(l))
		printf("the bag is empty,can not provide head\n");
	else return l.head->t;
}

/**
* gets a random tile from the bag then removes the tile from the bag
*/

tile draw_random(bag * l)
{
	if(is_empty(*l))
		printf("the bag is empty can not draw\n");
	else
	{
		int i;
		l->cursor = l->head;
		int rand_num = rand() % ( size_bag(*l));
		for( i = 0; i < rand_num ; i++)	
			(*l) = next (*l);
		tile ret = l->cursor->t;
		(*l) = withdraw(*l,ret);	
		return ret;
	}
	
}
