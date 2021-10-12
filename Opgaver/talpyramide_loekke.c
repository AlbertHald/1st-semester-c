/* Lav en talpyramide med nested loops 
Hvilken form for løkke er mest oplagt */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ROWS 5

int main(void)
{
    int rows = 0, tjekker = 5;
    for (rows = 0; rows < MAX_ROWS; rows++)
    {
        for ( int number = 0; number <= rows; number++)
        printf("%d ", number);
        printf("\n");
    }
        for ( int number = rows; number >= 0; number--)
        {
           for (int number = 0; number <= tjekker; number++)
           {
               printf("%d ", number);
           }
           printf("\n");
           tjekker--;
        }

    return 0;
}