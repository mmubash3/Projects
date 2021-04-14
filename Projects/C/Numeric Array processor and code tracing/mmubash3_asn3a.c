/* CS2211a 2020 */
/* Assignment 03 */
/* Mir Mubasher */
/* 251077816 */
/* mmubash3 */
/* 17th October 2020 */ 


#include <stdio.h>
#include <string.h>

int main() {
	int array[] = { 12,63,44,89,3,55,73,27,37,18,2,69,420,62,91}; 

	//initialization
	int SizeOfArray = sizeof(array);
	printf("Size of array: %d bytes \n",SizeOfArray);
    int LengthOfArray = sizeof(array)/sizeof(array[0]);
    printf("Length of array: %d elements \n",LengthOfArray);
    
    puts("");
    
    //part 1
    puts("PART 1:");
    puts("The values store into the array are :");
    for (int temp = 0; temp < LengthOfArray; temp++)
    {
        printf("%d     ",array[temp]);
        }
        
    puts("\n");

    //part 2
    puts("PART 2:");
    puts("The values store into the array in reverse are :");
    for (int temp = LengthOfArray-1; temp > -1; temp--)
    {
        printf("%d     ",array[temp]);
        }
        
    puts("\n");    
    
    //part 3
    puts("PART 3:");
    puts("The smallest value stored in the array is :");
    int smallest_value = array[0];
    int position_of_value;
    for (int temp = 0; temp < LengthOfArray; temp++)
    {
        if (smallest_value > array[temp])
        {
            smallest_value = array[temp];
            position_of_value = temp+1;
            }
        }
    
    printf("value: %d at the %dth position from the left",smallest_value,position_of_value);
    
    puts("\n"); 
    
    //part 4
    puts("PART 4:");
    puts("The sum (total) value of the array is :");
    //code for addition
    int SUM_VALUE = 0;
    for (int temp = 0; temp < LengthOfArray; temp++)
    {
        SUM_VALUE= SUM_VALUE + array[temp];
        }
    //code for visual output
    for (int temp = 0; temp < LengthOfArray; temp++)
    {
        printf("%d  ",array[temp]);
        for (temp; temp < LengthOfArray-1; temp++)
        {
        fputs("+  ",stdout);
        break;
            }
        }
    printf("equals: %d",SUM_VALUE);
    
    puts("\n");
    
    //part 5
    puts("PART 5:");
    puts("Copy the array into a new array, but in reverse order :");
    puts("Original array :");
    for (int temp = 0; temp < LengthOfArray; temp++)
    {
        printf("%d     ",array[temp]);
        }
    puts("\nNew (Reversed) array :");
    int reverse_array[LengthOfArray+1];
    int tempvar = 0;
    for (int temp = LengthOfArray-1; temp > -1; temp--)
    {
        while (tempvar < LengthOfArray)
        {
            reverse_array[tempvar]=array[temp];
            tempvar++;
            break;
            }
        }
    for (int temp = 0; temp < LengthOfArray; temp++)
    {
        printf("%d     ",reverse_array[temp]);
        }

    puts("\n");
    
    //part 6
    puts("PART 6:");
    puts("Switch the first value in the array with the last value in the array :");
    puts("Original array :");
    for (int temp = 0; temp < LengthOfArray; temp++)
    {
        printf("%d     ",array[temp]);
        }
    puts("\nChanged array :");
    int firstvalue = array[0];
    int lastvalue = array[LengthOfArray-1];
    array[0] = lastvalue;
    array[LengthOfArray-1] = firstvalue;
    for (int temp = 0; temp < LengthOfArray; temp++)
    {
        printf("%d     ",array[temp]);
        }
        
    puts("\n");
    
    //part 7
    puts("PART 7:");
    puts("Sort the array in ascending order :");
    puts("Original array :");
    for (int temp = 0; temp < LengthOfArray; temp++)
    {
        printf("%d     ",array[temp]);
        }
    puts("\nChanged array :");   
    
    int counter = ((LengthOfArray-1)/2)*LengthOfArray; //using triangle number for while loop
	int x = 0;
	while (x < counter)
	{
		int i=0;
		int j=1;
		while(j < LengthOfArray)
		{
			if (array[j]<array[i])
			{
			int tempintsmall = array[j];
			int tempintlarge = array[i];
			array[i] = tempintsmall;
			array[j] = tempintlarge;
				}
		i++;
		j++;
			}
	x++;
		}
 
    for (int temp = 0; temp < LengthOfArray; temp++)
    {
        printf("%d     ",array[temp]);
        } 
    puts("\n");

    return 0;
}
