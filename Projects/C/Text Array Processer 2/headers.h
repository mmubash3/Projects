/* CS2211a 2020 */
/* Assignment 05 */
/* Mir Mubasher */
/* 251077816 */
/* mmubash3 */
/* 29th November 2020 */ 


#ifndef HEADERS_H_INCLUDED
#define HEADERS_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct {
  char *char_pointer;
  int num_char;
  int pos_word;
  struct word *next_word;
}word;

typedef struct {
  word *word_pointer;
  int num_words;
  int line_count;
  struct sentence *next_sentence;
}sentence;

typedef struct{
  sentence *root;
  int number_of_sentence;
}sentence_ctrl;

//helper functions
int white_space_function(char *input_sentence,unsigned long int length);
int word_count_f(char *input_sentence,unsigned long int length);

//find word function
void find_word(sentence *root_sentence);

//setting up word,sentence structures 
word *newWord(char *char_pointer,int num_char, int pos_word);
word* insertWord(word* root_word,char *char_pointer, int num_char, int pos_word);
sentence *newSentence(word *word_pointer,int num_words, int line_count);
sentence* insertSentence(sentence* root_sentence,word *word_pointer, int num_words, int line_count);
sentence_ctrl* createControlStructure(void);	// createList

//print functions
void printWords(word *root_word,int is_new_line);
void printWordSeparately(sentence *root_sentence);
void printSentences(sentence *root_sentence,int show_line);

//delete functions
void set_sentence_numbers (sentence *root_sentence, int sentence_to_delete, int number_of_sentences);
void delete_all_words(word *root_word);
sentence* delete_sentence (sentence *root_sentence, int sentence_to_delete, int number_of_sentences);
sentence* delete_sentence_function(sentence *root_sentence, int number_of_sentences);

//clear all memory function
void clear_memory(sentence *root_sentence);

#endif // HEADERS_H_INCLUDED