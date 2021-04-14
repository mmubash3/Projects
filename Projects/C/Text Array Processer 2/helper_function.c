/* CS2211a 2020 */
/* Assignment 05 */
/* Mir Mubasher */
/* 251077816 */
/* mmubash3 */
/* 29th November 2020 */ 

#include "headers.h"

/*counts total whitespaces in a sentence*/
int white_space_function(char *input_sentence,unsigned long int length) //to get number of white space
{
  int whitespace=0;
  for(int i=0;i<length;i++)
  {
    if((isspace(*(input_sentence+i))!=0))
    {
      whitespace++;
      }  
  }
  return whitespace;
}

/*counts the number of words in a sentence*/
int word_count_f(char *input_sentence,unsigned long int length) //to get word count of each sentence
{
  int word_count = 0;
  for (int i=0,char_count=0;i<length;i++) // goes through entire input sentence
  {
    /* will start with elseif part if a normal sentence is put in*/
    if((isspace(*(input_sentence+i))!=0)) //checks if the char is a space
    {
      if(char_count!=0)//put in so it doesn't count whitespace as a word
        {
          word_count++; //word count goes up
          }
      char_count=0;
    }
    else if((isspace(*(input_sentence+i))==0)) //if the char is not a space char count increases
    {
      char_count++;
      } 
  }
  return word_count;
}
