/** @file dictionary.h
 * This header file contains functions related to the dictionary
 * Added functions : word_exist
 * @author: Abdallah 
 * @date: 11-02-15
 */

 # if ! defined (DICTIONARY_H)
 # define DICTIONARY_H

/**
* returns true if the input string exists in the scrabble dictionary.
* \author Abdallah
*/
int word_exist(char str [word_len]);

 # endif