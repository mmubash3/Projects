// CS2211a 2020
// Assignment 2
// Mir Mubasher
// 251077816
// mmubash3
// 1st October 2020
 
#include <stdio.h>

#include <stdio.h>

float exponent_calc(float a, int n)
{
    float y;
    if (n==0)
    {
        return 1;
        }
    
    else if (n%2 == 0)
    {
        y = exponent_calc(a, n/2);
        return y*y;
        }
    
    else
    {
        return a* exponent_calc(a,n-1);
        }
    }

int main()
{
    float a; //base
    int n; //exponant
	float output;
    printf("Welcome to the exponential calculator\n");
    printf("Please enter a base\n");
    scanf("%f",&a);
    printf("Pleasae enter an exponent\n");
    scanf("%d",&n);
    
    while (a != 0)
    {
        if (n>0)												//if the value of n is positive
        {
			printf("%f^%d = %f\n", a,n,exponent_calc(a,n));
			printf("Please enter a base\n");
			scanf("%f",&a);
			printf("Pleasae enter an exponent\n");
			scanf("%d",&n);
            }

        else													//if the value of n is negative
        {
			int temp_n = n * -1;
			output = 1/exponent_calc(a,temp_n);
			printf("%f^%d = %f\n", a,n,output);
            printf("Please enter a base\n");
            scanf("%f",&a);
            printf("Pleasae enter an exponent\n");
            scanf("%d",&n);
			}
		}
	
    printf("Program has ended\n");

    return 0;
}
