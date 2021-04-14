/* CS2211a 2020 */
/* Assignment 04 */
/* Mir Enan Mubasher*/
/* 251077816 */
/* mmubash3 */
/* 17/11/2020 */ 
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
int word_count_f(char *input_sentence,unsigned long int length) //to get word count of each sentence
{
  int word_count = 0;
  for (int i=0,char_count=0;i<length;i++)
  {
    if((isspace(*(input_sentence+i))!=0))
    {
      if(char_count!=0)//put in so it doesn't count whitespace as a word
        {
          word_count++;
          }
      char_count=0;
    }
    else if((isspace(*(input_sentence+i))==0))
    {
      char_count++;
      } 
  }
  return word_count;
}
