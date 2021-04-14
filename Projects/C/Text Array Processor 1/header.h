/* CS2211a 2020 */
/* Assignment 04 */
/* Mir Enan Mubasher*/
/* 251077816 */
/* mmubash3 */
/* 17/11/2020 */ 
#include "definitons.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct {
  char *char_pointer;
  int num_char;
  int pos_word;
}word;

typedef struct {
  word *word_pointer;
  int num_words;
  int line_count;
}sentence;