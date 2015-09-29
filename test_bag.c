/**@file test_bag.c tests the different related to the data structure of the bag
* \author Abdallah
*/

# include <stdio.h>
# include "test_bag.h"
# include "bag.h"



/** test initialization of bag_inhand and real_bag, displaying both bags, testing size_bag function
*/
void test_initialization()
{
	bag in_hand;
	bag real_bag;
	char c;
	real_bag = new_real_bag();
	printf("The real bag of size %d before initialzing in_hand bag\n", size_bag(real_bag));
	printf("Expected value is 100\n");

	display_bag (real_bag);

	printf("press enter to see the next test case\n");
	scanf("%c",&c);
	in_hand = new_inhand_bag(&real_bag);


	printf("The real bag of size %d after initialzing in_hand bag\n", size_bag(real_bag));
	printf("Expected value is 93\n");

	printf("press enter to see the next test case\n");
	scanf("%c",&c);
	display_bag(in_hand);
	printf("The bag in_hand of size %d \n", size_bag(in_hand));
	printf("Expected value is 7\n");


}


/** tests refill_bag , withdraw_random , exchange functions
*/
void test2()
{
	bag in_hand;
	bag real_bag;
	char c;
	tile t;
	real_bag = new_real_bag();
	in_hand = new_inhand_bag(&real_bag);
	display_bag(in_hand);
	printf("press any key to withdraw a random tile from the in hand bag\n");
	scanf("%c",&c);

	t = draw_random(& in_hand);
	display_bag(in_hand);
	printf("The withdrawn tile is %c\n", get_letter(t) );
	printf("press any key to withdraw a random tile from the in hand bag\n");
	scanf("%c",&c);

	t = draw_random(& in_hand);
	display_bag(in_hand);
	printf("The withdrawn tile is %c\n", get_letter(t) );
	printf("press any key to withdraw a random tile from the in hand bag\n");
	scanf("%c",&c);

	t = draw_random(& in_hand);
	display_bag(in_hand);
	printf("The withdrawn tile is %c\n", get_letter(t) );
	printf("press enter to refill the in_hand bag\n");
	scanf("%c",&c);

	refill_inhand_bag ( & in_hand, & real_bag );
	display_bag(in_hand);

	printf("Press enter to exchange a tile \n");
	scanf("%c",&c);
	exchange( & in_hand , &real_bag );
	display_bag(in_hand);
}

int main ( int argc , char * argv [])
{
	srand(time(NULL));
	char c;
	test_initialization();
	printf("press enter to see the next test case\n");
	scanf("%c",&c);
	test2();
	return 0;
}