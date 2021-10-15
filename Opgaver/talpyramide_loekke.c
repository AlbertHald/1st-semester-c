/* Lav en talpyramide med nested loops 
Hvilken form for løkke er mest oplagt */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(void)
{
    int rows = 0, max_rows;
    scanf(" %d", &max_rows);
    int tjekker = max_rows;
    for (rows = 0; rows < max_rows; rows++)
    {
        for ( int number = 0; number <= rows; number++)
        {
            printf("%d ", number);
        }
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