/* CS2211a 2020 */
/* Assignment 03 */
/* Mir Mubasher */
/* 251077816 */
/* mmubash3 */
/* 17th October 2020 */ 

/*
In summary this program will give you the sum of all prime numbers till the number which is put in.
e.g. 
2=2
3=2+3=5
5=2+3+5=10
7=2+3+5+7=17
the two arrays below show the corresponding values for the input vs output. (Note that values only increase at prime numbers)
INPUT VALUES  	[1	2	3	4	5	6	7	8	9	10	11	12	13	14	15	16	17	18	19	20	21	22	23	24	25	26	27	28	29	30]
OUTPUT VALUES 	[0	2	5	5	10	10	17	17	17	17	28	28	41	41	41	41	58	58	77	77	77	77	100	100	100	100	100	100	129	129]

INPUT = the value input by the user
OUTPUT = the value to be displayed after calculation
COUNTER1 = counter for forloop
COUNTER2 = counter for forloop
TRACKER = to check if COUNTER1%COUNTER2 is divisible

How the code works:
Larger process
the code asks user for an input
If 0 is entered it will stop the code 
if the input != 0 then the code will process the number and give out the answer and then ask for another number
this process is repeated until 0 is entered
this is done using the whileloop as the whileloop is supposed to run as long as it's true which is perpetutually.
execept there is the if condition where if input=0 then it will break out of the while loop

NOTE:
The most important part of the code is the second_forloop and the two if conditions, as if the number has more than one number divisible to it then it give a value of d>1
if it only has one value which the input is divisible by and the number it is divisible by is the input itself, then d == 1 and hence is added to the final output.

*/

#include <stdio.h> //opening the stdio.h library to use certain functions from that library
int main()	//initializing the main function
{
    int OUTPUT,COUNTER2,INPUT,TRACKER; //initializing the values OUTPUT,COUNTER2,INPUT and TRACKER and assigns them the memory to store an integer
	//whileloop
	//this makes sure that the program runs in a loop to keep asking for values, as long atleast one of the functions holds true it will keep running (1=True)
    while(1) 	
    {
		//assigning OUTPUT a value of 0
        OUTPUT=0; 
		//asking for the input value from the user
        printf("Input? "); 
		//taking the input value from the user and assigning the value to the INPUT variable
        scanf("%d",&INPUT);	
		//this part is to make the entire program end if 0 is entered, if 0 isn't entered the while function will make this program loop forever
        if (INPUT==0)  
        {
			//used to break out of the while loop
            break;	
            }
		//first_forloop	
		// initializing COUNTER1 as an integer and assigning it a value of 1; condition = for loop will only occur if COUNTER1 is smaller than or equal to INPUT; after all functions in the forloop are finished COUNTER1 increases in value by 1
		for (int COUNTER1=1;COUNTER1<=INPUT;COUNTER1++) 
		{
            //assigning TRACKER a value of 0
			TRACKER = 0;
			//second_forloop
            //initializing COUNTER2 as an integer and assigning it a value of 2 ; condition = for loop will only occur if COUNTER2 is smaller than or equal to COUNTER1 ; after all functions in forloop are finished COUNTER2 increases in value by 1
			for (COUNTER2=2; COUNTER2 <= COUNTER1; COUNTER2++)
			{ 
			// if COUNTER1 is divisible by COUNTER2 then TRACKER will increase in value by 1
				if (COUNTER1%COUNTER2==0) 	
				{
					//adds +1 to TRACKER
					TRACKER++; 
					}
			    }
			// if TRACKER is 1 then the new output value will be the old output value plus the value of COUNTER1
            if (TRACKER==1) 
            {
                OUTPUT=OUTPUT+COUNTER1;   
                }
                
            }
		//when the INPUT value is smaller than COUNTER1 the loop will stop and they will give the answer through this function
        printf("The final total is: %d\n",OUTPUT); 
        }
	// after the main function is executed it has a value of 0
    return 0; 
} 