/* CS2211a 2020 */
/* Assignment 05 */
/* Mir Mubasher */
/* 251077816 */
/* mmubash3 */
/* 29th November 2020 */ 

#include "headers.h"

//function to find the word in a sentence and to find it's position
void find_word(sentence *root_sentence)
{
  char input_word[100];//input word to be found
  sentence *main_sentence = root_sentence;
  while(1)//will keep asking for words to find until blank input
  {
    root_sentence = main_sentence;//to reset it to the root sentence everytime
    printf("Enter a word to search: ");
    fgets(input_word, sizeof(input_word), stdin);//request for input word
    int match_check=0; //used to see if the word exisits in the file
    if (input_word[0]=='\n') //if no input break out of loop and function
    {
      break;
      }
    else
    {
      while(root_sentence !=NULL) //goes through every sentence
      {
        word *root_word = root_sentence->word_pointer;//initiating the root word for each sentence 
        while((root_word)!=NULL) //goes through every word
        {
          if(strcmp((root_word->char_pointer),(input_word))==0)//if the word and the input is same
          {
            printf("%s found in line %d position %d \n",input_word,(root_sentence->line_count),(root_word->pos_word));// prints where in file word is
            match_check++;//a word has been found
            }
          root_word = root_word->next_word;//goes to next word to check with that word
          }
        root_sentence = (root_sentence->next_sentence);//goes to next sentence to check all words in sentence
        }
      printf("\n");
      if (match_check==0)//if no matches then prints not there in file
      {
        printf("%s was not found in this file\n",input_word);
        printf("\n");
        }  
      }
    }
}
