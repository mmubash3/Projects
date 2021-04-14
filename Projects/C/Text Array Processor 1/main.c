/* CS2211a 2020 */
/* Assignment 04 */
/* Mir Enan Mubasher*/
/* 251077816 */
/* mmubash3 */
/* 17/11/2020 */ 

#include "header.h"

int main(void) {
  char input_str[1000];
  int number_of_sentences=1;
  int total_number_of_words=0;
  int total_number_of_chars=0;
  char *temp;
  word *word_list;
  sentence *sentence_list;
  while(1)
  {
    fgets(input_str, sizeof(input_str), stdin);
    unsigned int length_input=strlen(input_str);
    int whitespace = white_space_function(&input_str[0],strlen(input_str));
    int number_of_words = word_count_f(&input_str[0], strlen(input_str));
    unsigned int length_required = length_input-whitespace;
    if (number_of_sentences==1)
    {
      temp = (char *)malloc(length_required*sizeof(char));
      word_list = (word *)malloc(number_of_words*sizeof(word));
      sentence_list = (sentence *)malloc(1*sizeof(sentence));
      }
    if (input_str[0]=='\n')
    {
      break;
      }
    else if (number_of_words==0)
    {
      continue;
      }
    else
    { 
      if (number_of_sentences>1)
      {
        temp = (char *)realloc(temp,(total_number_of_chars+length_required)*sizeof(char));
        word_list= (word *)realloc(word_list,(total_number_of_words+number_of_words)*sizeof(word));
        sentence_list=(sentence *)realloc(sentence_list,number_of_sentences*sizeof(sentence));
        }

      sentence_list[(number_of_sentences-1)].line_count=number_of_sentences;
      sentence_list[(number_of_sentences-1)].num_words=number_of_words;
     
      int j=total_number_of_chars;//starting address of dynamically allocated array
      //for adding chars from input to main list and getting word count
      sentence_list[number_of_sentences-1].word_pointer= &word_list[j]; 
      for (int i=0,char_count=0;i<length_input;i++)
      {
      if((isspace(input_str[i])==0))
        {
          *(temp+j)=input_str[i];
          j++;
          char_count++;
          } 
      }
      //adds values to each attribute of each item in the word list
      int char_address;
      if (number_of_sentences == 1)
      {
        char_address=0;
        }
      else
      {
        char_address=total_number_of_chars;
        }
      int word_pos=0;
      int position_of_word_in_list=total_number_of_words;
      for (int i=0,char_count=0;i<strlen(input_str);i++)
        {
          if((isspace(input_str[i])!=0))//to reset char_count whenever we face a whitespace
          {
            if(char_count!=0)//put in so it doesn't count whitespace as a word
            {
              word_list[position_of_word_in_list].num_char=char_count;
              word_pos++; //used as word position
              word_list[position_of_word_in_list].pos_word=word_pos;
              word_list[position_of_word_in_list].char_pointer= &temp[char_address]; 
              char_address += char_count;
              position_of_word_in_list++;
              }
            char_count=0;
            } 
          else if (isspace(input_str[i])==0) //counts number of char per word 
          {
            char_count++;
            }
          }
          
      number_of_sentences++;
      total_number_of_chars += length_required;
      total_number_of_words += number_of_words;  
      }
  }
  
  
  int m=1;
  printf("This is all the words printed out one line at a time: \n");
  for (int i=0;i<total_number_of_words;i++)
  {
    for (int j=0;j<(word_list[i].num_char);j++)
    {
      if(i==0&&j==0)
      {
        m=0;
        }
      else{
        m++;
      }
      printf("%c",*(temp+m));
    }
  printf("\n");
  }
    
  printf("This is all the words printed out on the same line as entered:\n");
  m=1;
  for (int i=0;i<total_number_of_words;i++)
  {
    for (int j=0;j<(word_list[i].num_char);j++)
    {
      if(i==0&&j==0)
      {
        m=0;
        }
      else{
        m++;
      }
      printf("%c",*(temp+m)); 
    }
    printf(" ");
    if(word_list[i+1].pos_word==1)
    {
    printf("\n");
      }
  }
  printf("\n");


  int number_of_comp_words=1;
  char *temp_word;
  while(1)    //while true
  {
    int counter=0; //counter should be in while loop so it resets everytime new input word is put
    int match_check=0; //to check if there are any matches 
    printf("Enter a word to search: "); 
    fgets(input_str, sizeof(input_str), stdin); //ask for an input
    if (input_str[0]=='\n') //if no input break
    {
      break;
      }
    else
    {
    unsigned int size_of_word = strlen(input_str)-1; //size of input word without the nullspace
    if(number_of_comp_words==1) //if it is the first input word, use malloc
    {
    temp_word = (char *)malloc((size_of_word+1)*sizeof(char));
      }
    else{  
      free(temp_word);// else free the space and realloc space for new entry comparison
      temp_word = (char *)malloc((size_of_word+1)*sizeof(char));
    }
    for(int i=0;i<(number_of_sentences-1);i++) //i will signify which sentence it is in(goes through each sentence)
    {
      for (int x=0;x<(sentence_list[i].num_words);x++) //x will signify which word(goes through each word)
      {
        if (word_list[counter].num_char==size_of_word)//check if the word and input are same size
        {
          for(int m=0; m<word_list[counter].num_char;m++)//for each char in the entire list
          {
            *(temp_word+m)=*(word_list[counter].char_pointer+m);// for loop ends here
            }
            *(temp_word+word_list[counter].num_char)='\n';
            if(strcmp(temp_word,input_str)==0)
            {
              printf("%s found in line %d position %d\n",input_str,(i+1),(x+1));
              match_check++;
            }
          number_of_comp_words++;
          }
          counter++;
        }
      }
    }
    if (match_check==0){
      printf("was not there in this file\n");
    }
  }
  return 0;
}
