/*Programmet er det første program i undervisning om loops. */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int input_tal, output_value = 0, i = 0;
    /* Printer talrækken 1+2+3...+ n */
    scanf(" %d", &input_tal);
    while (input_tal >= i)
    {
        output_value = output_value + i;
        i++;
    }
    
    printf("%d", output_value);
    /* Printer tallet n*(n+1)/2 */
    int output_value = input_tal * (input_tal + 1) / 2;

    printf("\n%d", output_value);
    return 0;
}
