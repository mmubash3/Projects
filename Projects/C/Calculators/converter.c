// CS2211a 2020
// Assignment 2
// Mir Mubasher
// 251077816
// mmubash3
// 1st October 2020
 
#include <stdio.h>
#define KILOMETERS_PER_MILE 1.609f
#define LITERS_PER_GALLON 3.785f
#define CENTIMETER_PER_INCH 2.54f

float converted_value;

float KILOMETERS_MILES (char CONV_OPTION, float input_value) //function for option 1
{
	switch (CONV_OPTION)
	  {
		case 'K': //conversion from Kilometer to Mile
		converted_value = input_value / KILOMETERS_PER_MILE;
		printf("%f Km = %f Mi\n", input_value,converted_value);
		break;

		case 'M': //conversion from Mile to Kilometer
		converted_value= input_value * KILOMETERS_PER_MILE;
		printf("%f M = %f Km\n", input_value,converted_value);
		break;
		}
    return converted_value;
	}

float LITERS_GALLONS (char CONV_OPTION, float input_value)  //function for option 2
{
	switch (CONV_OPTION)
		{
		case 'L': //conversion from Litre to Gallon
		converted_value = input_value / LITERS_PER_GALLON;
		printf("%f L = %f Gal\n", input_value,converted_value);
		break;

		case 'G': //conversion from Gallon to Litre
		converted_value = input_value * LITERS_PER_GALLON;
		printf("%f Gal = %f L\n", input_value,converted_value);		  
		break;
		}
	return converted_value;
	}

float CENTIMETERS_INCHES (char CONV_OPTION,float input_value) //function for option 3
{
	switch (CONV_OPTION)
		{
		case 'C': // conversion from Centimetre to Inch
		converted_value = input_value / CENTIMETER_PER_INCH;
		printf("%f CM = %f IN\n", input_value,converted_value);
		break;

		case 'I': //conversion from Inch to Centimetre
		converted_value = input_value * CENTIMETER_PER_INCH;
		printf("%f IN = %f CM\n", input_value,converted_value);			  
		break;
		}
	return converted_value;
	}

float FAHRENHEIT_CELCIUS (char CONV_OPTION,float input_value) //function for option 4
{
	switch (CONV_OPTION)
		{
		case 'C': //  conversion from Celsius to Fahrenheit
		converted_value = (input_value * 9/5) + 32;
		printf("%f C = %f F\n", input_value,converted_value);
		break;

		case 'F': //conversion from Fahrenheit to Celsius
		converted_value =  (input_value - 32) * 5/9;
		printf("%f F = %f C\n", input_value,converted_value);			  
		break;
		}
	return converted_value;
	}
	


int main()
{
	char OPTIONS [300] = "Please enter \n1 for conversion between Kilometer and Mile\n2 for conversion between Litre and Gallon\n3 for conversion between Centimetre and Inch\n4 for conversion between Celsius and Fahrenheit\n5 to quit\n";
	char KM_M [100] = "Please enter\nK for conversion from Kilometer to Mile\nM for conversion from Mile to Kilometer\n";
	char L_G [100] = "Please enter\nL for conversion from Litre to Gallon\nG for conversion from Gallon to Litre\n";
	char C_I [100]= "Please enter\nC for conversion from Centimetre to Inch\nI for conversion from Inch to Centimetre\n";
	char F_C [120]= "Please enter\nC for conversion from Celsius to Fahrenheit\nF for conversion from Fahrenheit to Celsius\n";
	char input[50]= "Please input the value\n";
    char OPTION;
    char CONV_OPTION;
	float input_value;
	float converted_value;
	float output_value;
	float s;
	
    printf("Welcome to the converter \n");
	printf("%s",OPTIONS);
    scanf ("%s", &OPTION);
    
	while (OPTION != '5')
	{
		while (OPTION != '1'&& OPTION != '2' && OPTION != '3' && OPTION != '4' && OPTION != '5' ) // to make sure that it asks user for input if 1-5 is not inputed
		{
			printf("%s",OPTIONS);
			scanf ("%s", &OPTION);
				}
		
		switch(OPTION)
		{
		  case '1': //conversion of Kilometer and Mile
		  
		  printf("%s",KM_M);
		  scanf ("%s", &CONV_OPTION);
		  
		  while (CONV_OPTION !='K' && CONV_OPTION != 'M')
		  {
			printf("%s",KM_M);
			scanf ("%s", &CONV_OPTION);
			}
		  printf("Please input the value:\n");
		  scanf("%f",&input_value);
		  s = KILOMETERS_MILES(CONV_OPTION,input_value);
		  printf("%s",OPTIONS);
		  scanf ("%s", &OPTION);
		  break;
		  
			
		  case '2': //conversion of Liter and Gallon
		  
		  printf("%s",L_G);
		  scanf ("%s", &CONV_OPTION);
		  
		  while (CONV_OPTION !='L' && CONV_OPTION != 'G')
		  {
			printf("%s",L_G);
			scanf ("%s", &CONV_OPTION);
			}
		  printf("Please input the value:\n");
		  scanf("%f",&input_value);
		  s = LITERS_GALLONS(CONV_OPTION,input_value);
		  printf("%s",OPTIONS);
		  scanf ("%s", &OPTION);	
		  break;
		  
		  
		  case '3': //conversion of Centimetre and Inch
		  
		  printf("%s",C_I);
		  scanf ("%s", &CONV_OPTION);
		  
		  while (CONV_OPTION !='C' && CONV_OPTION != 'I')
		  {
			printf("%s",C_I);
			scanf ("%s", &CONV_OPTION);
			}
		  printf("Please input the value:\n");
		  scanf("%f",&input_value);
		  s = CENTIMETERS_INCHES(CONV_OPTION,input_value);
		  printf("%s",OPTIONS);
		  scanf ("%s", &OPTION);
		  break;
		  
		  case '4': //conversion of Celsius and Fahrenheit
		  
		  printf("%s",F_C);
		  scanf ("%s", &CONV_OPTION);
		  while (CONV_OPTION !='C' && CONV_OPTION != 'F')
		  {
			printf("%s",F_C);
			scanf ("%s", &CONV_OPTION);
			}
		  printf("Please input the value:\n");
		  scanf("%f",&input_value);
		  s = FAHRENHEIT_CELCIUS(CONV_OPTION,input_value);
		  printf("%s",OPTIONS);
		  scanf ("%s", &OPTION);  
		  break;
		 
	  }
	}
	
  printf("END OF PROGRAM \n");
    
    return 0;
}
