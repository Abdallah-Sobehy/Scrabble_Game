/**@file test_bag.h tests the different related to the data structure of the bag
* \author Abdallah
*/

# if ! defined (TEST_BAG_H)
# define TEST_BAG_H

# include <stdio.h>
# include "bag.h"

/** test initialization of bag_inhand and real_bag, displaying both bags
*/
void test_initialization();

/** tests refill_bag , withdraw_random , exchange functions
*/
void test2();

# endif