/** @file dictionary.c
 * Implementation of functions related to the dictionary
 * Added functions : word_exist
 * @author: Abdallah 
 * @date: 11-02-15
 */
# include <stdio.h>
#include <string.h>
/**
* Maximum word length in the scrabble dictionary
*/
# define max_dic_word 16 

/**
* the word length of the word to be searched
*/
# define word_len 32





/**
* returns true if the input string exists in the scrabble dictionary.
* \author Abdallah
*/
int word_exist(char str [word_len])
{
	FILE * dic;
	dic  = fopen ("./scrabble.txt", "r");
	char dic_word [max_dic_word] ;// the size of the longest word that exist in the scrabble dictionary (checked practically)
	char str_lower[word_len] ;// to have the word to be searched in lower case, as the dictionary is in lower case
	int i =0;

	strcpy(str_lower, str);
	while(str_lower[i] != '\0')
	{
		str_lower[i] = tolower( str_lower[i] );
		i++;
	}

	while (!feof(dic))
	{
		fscanf (dic , "%s", dic_word);
		if ( ! strcmp(str_lower, dic_word) )
			return 1;
	}
	return 0;// all the file is traversed and no equivalent string is found
}
