/* CS2211a 2020 */
/* Assignment 05 */
/* Mir Mubasher */
/* 251077816 */
/* mmubash3 */
/* 29th November 2020 */ 

#include "headers.h"
//creates new word and assigns each attribute of word a value
word *newWord(char *char_pointer,int num_char, int pos_word)
{
	word *temp =  (word *)malloc(sizeof(word));
	temp->num_char = num_char;
	temp->pos_word = pos_word;
  temp->char_pointer=char_pointer;
	temp->next_word = NULL;
	return temp;
}
/* this function uses recursion to keep adding words and creating a structure of words*/
word* insertWord(word* root_word,char *char_pointer, int num_char, int pos_word)
{
    /* If the tree is empty, return a new node */
    if (root_word == NULL) //if word is null then makes a new word.
    {
	    return newWord(char_pointer, num_char, pos_word);
	    }
    else
    {
      /* if node isn't empty then the it will point to another word and insert it using the same function*/
      root_word -> next_word =insertWord(root_word -> next_word,char_pointer,num_char, pos_word);

      }
    /* return the (unchanged) node pointer */
    return root_word;
}
//creates new sentence and assigns each attribute of sentence a value
sentence *newSentence(word *word_pointer,int num_words, int line_count)
{
	sentence *temp_sentence =  (sentence *)malloc(sizeof(sentence));
	temp_sentence->num_words = num_words;
	temp_sentence->line_count = line_count;
  temp_sentence->word_pointer=word_pointer;
	temp_sentence->next_sentence = NULL;
	return temp_sentence;
}
/* this function uses recursion to keep adding sentences and creating a structure of sentences*/
sentence* insertSentence(sentence* root_sentence,word *word_pointer, int num_words, int line_count)
{
    // If the tree is empty, return a new node 
    if (root_sentence == NULL) //if sentence is null then makes a new sentence.
    {
	    return newSentence(word_pointer, num_words, line_count);
	    }
    else
    {
      /* if node isn't empty then the it will point to another sentence and insert that using the same function*/
      root_sentence->next_sentence =insertSentence(root_sentence -> next_sentence,word_pointer,num_words, line_count);
      }
    // return the (unchanged) node pointer 
    return root_sentence;
}

//control structure to create the list of sentences
sentence_ctrl* createControlStructure(void)
{
   sentence_ctrl* initial_sentence;
   initial_sentence = (sentence_ctrl*) malloc (sizeof (sentence_ctrl));
	if (initial_sentence)
	   {
      initial_sentence->root = NULL;
      initial_sentence->number_of_sentence = 0;
   	   } // if
	return initial_sentence;
}	// createList