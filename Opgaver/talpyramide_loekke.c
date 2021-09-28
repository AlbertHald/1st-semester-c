/* Lav en talpyramide med nested loops 
Hvilken form for løkke er mest oplagt */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int number = 0;
    for (int rows = 0; rows < 11; rows++)
    {
        if (number <= 5)
        {
            while (number <= 5)
            {
                printf("%d ", number++);
            }
        }
        
        if (number = 5)
        {
            while (number >= 0)
            {
                printf("%d ", number--);
            }
            
        }
    
        printf("\n");
        
    }
    return 0;
}
