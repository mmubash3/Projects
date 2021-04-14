/* CS2211a 2020 */
/* Assignment 05 */
/* Mir Mubasher */
/* 251077816 */
/* mmubash3 */
/* 29th November 2020 */ 


#include "headers.h"

/*This functions adjusts the line number of the sentence structs nodes */
void set_sentence_numbers (sentence *root_sentence, int sentence_to_delete, int number_of_sentences)
{
  for (int i=0; i<number_of_sentences; i++)
  {
    if((root_sentence->line_count)>sentence_to_delete)
    {
      root_sentence->line_count--;
      }
    root_sentence = root_sentence->next_sentence;
    }
}

/* this function deletes all words form a sentence node*/
void delete_all_words(word *root_word)
{
  if (root_word == NULL)
  {
    return;
  }
  else
  {
    /*recursive call used to go to the last word and then free that word and then work backwards towards root_word*/
    root_word = root_word ->next_word;
    delete_all_words(root_word);
    free(root_word);
    }
  }

/*this functions deletes each sentence node and adjusts the pointer to next sentence*/
sentence* delete_sentence (sentence *root_sentence, int sentence_to_delete, int number_of_sentences)
{
  set_sentence_numbers(root_sentence,sentence_to_delete,number_of_sentences);
  sentence *pre_sentence; //previous sentence
  sentence *post_sentence; //next sentence
  sentence *new_root=root_sentence;//new root sentence if 1st sentence is deleted
  if (sentence_to_delete == 1)//if the root sentence is being deleted then 2nd sentence is the new root
  {
    new_root = root_sentence->next_sentence;
    delete_all_words(root_sentence->word_pointer);
    free(root_sentence);
    return new_root;//to return the new root
    }
  else //if any other than root sentence is being deleted 
  {
    while((root_sentence->line_count)!=sentence_to_delete) //traverse through sentence nodes till we reach the node meant to be deleted
    {
      if ((root_sentence->line_count)==sentence_to_delete-1)//while traversing find the previous node
      {
        pre_sentence = root_sentence;
        }
      root_sentence = root_sentence->next_sentence;
      }
    post_sentence = root_sentence->next_sentence; //the node after the one meant to be deleted
    delete_all_words(root_sentence->word_pointer); //delete all words from the sentence node
    free(root_sentence); //delete the sentence node
    pre_sentence->next_sentence = post_sentence; //adjust the pointers prev_node points to next node now
    return new_root; //to return the new root
    }
}


//used in main to take in conditions of which line to be deleted
sentence* delete_sentence_function(sentence *root_sentence, int number_of_sentences)
{
  int total_sentences=number_of_sentences; //in order to reduce total number of 
  sentence *main_sentence = root_sentence; 
  int sentence_number;
  char sentence_num[100];
  while(1)
  {
    printf("Enter sentence number to delete: ");
    //scanf("%d", &sentence_number);//asking for the sentence to be deleted
    fgets(sentence_num, sizeof(sentence_num), stdin);
    if (sentence_num[0]=='\n') //if no input break
    {
      //ask ta about how to break if no input is put in
      break;
      }
    else
    {
      sentence_number=atoi(sentence_num);
      if (sentence_number>total_sentences) //to request for a new input if the input was greater than number of sentences
      {
        printf("Request denied: Input sentence number is greater than number of sentences\n");
        continue;
        }
      else//if input is within number of sentences
      {
        //uses the delete sentence to delete the input sentence
        main_sentence = delete_sentence(main_sentence,sentence_number,total_sentences);
        total_sentences--;
        if (total_sentences==0) //if all sentences are deleted then it will quit
        {
          printf("No more sentences remaining\n");
          break;
          }
        else //will print the remaining sentences
        {
          printf("remaining sentences are: \n");
          printSentences(root_sentence,1);
          }
        }
      }
    }
  return main_sentence;//returns the new root of sentence if the 1st sentence has been deleted
}

//to clear all nodes at end of program
void clear_memory(sentence *root_sentence)
{
  printf("Beginning to clear memory\n");
  if (root_sentence ==NULL)
  {
    printf("Nothing in memory to clear\n");
    return;
    }
  else
  {
    while(root_sentence!=NULL)//to go through each node of sentence till next sentence is a NULL
    {
      sentence *sentence_to_clear = root_sentence;//sets node to clear
      root_sentence = (root_sentence->next_sentence); //goes to next node
      delete_all_words(sentence_to_clear->word_pointer);//clears words from first node
      free(sentence_to_clear);//clears node
      }
     printf("All of the memory in heap has been cleared\n"); 
    }
}
