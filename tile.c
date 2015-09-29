/**
 * @authors : Abdallah & Fred
 * @date: 05-01-2015
 */

# include<stdio.h>
#include<stdlib.h>
 #include <ctype.h>
# include "tile.h"

/**
 * Initializes the tile with the input character and the corresponding point value 
 * Also, new_tile changes lower case letters to upper case before creating the tile.*/ 
tile new_tile(char letter)
  {
     
      tile A;
      A.letter = islower(letter)? toupper( letter) : letter;
      
      switch (A.letter)
      {
        case ' ' : A.point_value = 1; break; // point value for the empty square = 1, to be used when calculating score ( the letter is multiplied by 1)
        case '"' : A.point_value = 2; break; // point value for the double letter square = 2, to be used when calculating score ( the letter is multiplied by 2)
        case '=' : A.point_value = 1; break;
        case '*' : A.point_value = 3; break; // point value for the triple letter = 3, to be used when calculating score ( the letter is multiplied by 3)
        case '^' :  A.point_value = 1; break;

        case '_' : A.point_value = 0 ; break;
        case 'E' :
        case 'A' :
        case 'I' :
        case 'O' :
        case 'N' :
        case 'R' :
        case 'T' :
        case 'L' :
        case 'S' :
        case 'U' : A.point_value = 1; break ;

        case 'D' :
        case 'G' : A.point_value = 2; break ;

        case 'B' :
        case 'C' :
        case 'M' :
        case 'P' : A.point_value = 3; break ;

        case 'F' :
        case 'H' :
        case 'V' :
        case 'W' :
        case 'Y' : A.point_value = 4; break ;

        case 'K' : A.point_value = 5; break ;

        case 'X' :
        case 'J' : A.point_value = 8; break ;

        case 'Q' :
        case 'Z' : A.point_value = 10; break ;



        default :
          printf("Cannot create a tile with this input character\n");
          return ; 
      }
      return A;
    
  }
/**
 *
 * Function to assign a character to the blank tile. 
 * request user to choose a character of choice. blank tiles have point value of 0.
 */
tile assign_char(tile A){
   
   if( get_score(A) != 0 ) // it is better to check it is a blank tile with it's point value because a blank tile can have different letters !
     printf("You cannot assign a character to a non-blank tile. \n");
   else
   {
     char letter;
     printf("Enter a letter to be assigned to the blank tile : ");
     do
  scanf("%c", &letter );
    while ( ! isalpha ( letter ) ) ;
  letter = islower(letter)? toupper( letter) : letter;
  A.letter = letter ; //
   }
   return A;
  
}

/**
 * The get score function returns the point value of the input tile 
 */
int get_score(tile A){
    
    return A.point_value;
}

/**
 * Returns the letter of the input tile */
char get_letter(tile A){
    
   return A.letter;
}

/**
* Returns true if the input tiles are the same.
*/

int is_equal(tile t1, tile t2)
{
  if(get_letter(t1) == get_letter(t2) )
    return 1;
  else return 0;
}


/**
* Checks if the tile picked is blank
*/
int blank_tile ( tile blank)
{
  if ( get_score (blank) == 0)
    return 1;
  return 0;
}