/* CS2211a 2020 */
/* Assignment 05 */
/* Mir Mubasher */
/* 251077816 */
/* mmubash3 */
/* 29th November 2020 */ 


#include "headers.h"

int main(void) {
  char input_str[1000];
  sentence_ctrl *control_sentence;
  control_sentence= createControlStructure(); //initializing the control structure
  int number_of_sentences=1;
  sentence *root_sentence = control_sentence->root; //setting root sentence to NULL value

  while(1)
  {
    int number_of_words;
    word *root_word = NULL;
    printf("Enter a string:");
    fgets(input_str, sizeof(input_str), stdin);
    number_of_words = word_count_f(&input_str[0], strlen(input_str));
    if (input_str[0]=='\n') //if no input break out of loop
    {
      number_of_sentences--; //since number of sentence starts from 1 if no sentence is input it reduces that, and number of sentence 
      break;
      }
    else if (number_of_words==0) //if no words input restart loop
    {
      continue;
      }
    else //if sentence is inputed 
    {
      /*In this else block the first word will be processed and set to root word then the first sentence 
      will be initialized and the attributes will be set. Note that within this the code ususally skips the first part and directly goes to the second bit as very rarely an input starts with space, but if it does start with space it is used to ignore the space*/
      int char_address=0;
      int word_pos=0;
      //goes through input sentence and processes it
      for (int i=0,char_count=0;i<strlen(input_str);i++)
        {
          //checks each char of input sentence to make sure white spaces aren't part of output
          if((isspace(input_str[i])!=0))//to reset char_count whenever we face a whitespace
          {
            if(char_count!=0)//put in so it doesn't count whitespace as a word
            {
              //end of a word
              word_pos++;
              int space_for_word = char_count+1;
              char *temp_word = (char*) calloc(space_for_word,sizeof(char));
              *(temp_word+space_for_word-1)='\n'; //adding this to the end of a word to make it compatiable with strcmp
              for (int char_counter=0;char_counter<char_count;char_counter++)
              {
                *(temp_word+char_counter)=input_str[char_counter+char_address];
                }
              //set position, num of chars and pointer for each word
              root_word=insertWord(root_word,temp_word,char_count,word_pos);
              char_address += char_count;
              /*The next part creates a new sentence node every time it knows that the word pos is 1*/
              /*This is as only the first word in each sentence will have word_pos as 1 */
              if (word_pos ==1)
              {
                root_sentence=insertSentence(root_sentence,root_word,number_of_words, number_of_sentences);
                if (number_of_sentences ==1)
                {
                  control_sentence->root = root_sentence; //setting the pointer to first sentence
                  }
                }
              }
            char_count=0; //set char count to zero in order to count number of chars in next word
            char_address++;//address of char in input_sentence will still have to be traversed
            } 
          else if (isspace(input_str[i])==0) //counts number of char per word 
          {
            char_count++;
            }
          }
    }
    control_sentence->number_of_sentence = number_of_sentences; //updating number of sentences in control structure
    number_of_sentences++;
  }
  if (number_of_sentences !=0)//if there is a sentence that is put in run the rest of the code
  {
    printSentences(root_sentence,0); //prints all words from each sentence in a single line
    find_word(root_sentence);//search function to find word in a particular sentence 
    root_sentence = delete_sentence_function(root_sentence,number_of_sentences);//deleting the required sentence and setting new root sentence incase the first sentence was deleted
    clear_memory(root_sentence); //clear all memory from heap memory
    printf("END OF PROGRAM\n");
    }
  else//if there's no sentence input
  {
    printf("There was no input \n");
    printf("END OF PROGRAM\n");
    }

  return 0;
}
