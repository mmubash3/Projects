/* CS2211a 2020 */
/* Assignment 05 */
/* Mir Mubasher */
/* 251077816 */
/* mmubash3 */
/* 29th November 2020 */ 


#include "headers.h"

//prints all words in a sentence
//the is_new_line is a variable if you want the word to be printed on the next line or not
void printWords(word *root_word,int is_new_line)
{
    if (root_word == NULL)
    {
      return;
      }
    else
    {
      while(root_word!=NULL) //goes through all words 
      {
        for (int i=0;i<root_word->num_char;i++) //goes throuh each char in a word
        {
        printf("%c",*((root_word->char_pointer)+i));
        }
        printf(" ");
        //you can use the below print function to see the position of the word and num of chars
        //printf(" pos word: %d, num char: %d",(root_word->pos_word),(root_word->num_char));
        if (is_new_line==1)//if new line is wanted
        {
          printf("\n");
          }
        root_word = root_word->next_word;//goes to next word and prints this word
        }
      }
}

//prints all words in all sentences in new line
void printWordSeparately(sentence *root_sentence)
{
    if (root_sentence == NULL) 
    {
      return;
    }
    else
    {
      printf("This is all the words printed out one line at a time:\n");
      while(root_sentence != NULL)//keeps going to next sentence node till the node after that is NULL
      {  
        printWords((root_sentence->word_pointer),1);//use printword function to print all words in sentence
        root_sentence = (root_sentence->next_sentence);//goes to next sentence node
        }
      printf("\n");
    }

}
//prints each sentence in a single line and if show line =1 then will show which line is being printed.
void printSentences(sentence *root_sentence,int show_line)
{
    if (root_sentence == NULL)
    {
      return;
    }
    else
    {
      while(root_sentence != NULL) //will keep going till next sentence is nULL
      {  
        if(show_line==1) //will print the line no. if this is initiated
        {
          printf("Sentence no. %d \n",(root_sentence->line_count));
          }
        printWords((root_sentence->word_pointer),0);//prints all words in a sentence without breaking into new line
        printf("\n");
        root_sentence = (root_sentence->next_sentence);//prints sentence
        }
      printf("\n");
    }
}