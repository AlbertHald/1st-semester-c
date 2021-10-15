#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "primes.h"

int main(void)
{
    int prim_input, current_number = 1, current_prim_input = 0;
    printf("Hvor mange primtal vil du have printet? >");
    scanf(" %d", &prim_input);

    while (prim_input != current_prim_input)
    {
        /* Tjekker om detnummer jeg er kommet til er et primtal */
        if (is_prime(current_number))
        {
            current_prim_input++;
            printf("Primtal %d: %d \n", current_number, current_prim_input);
        }    
        current_number++;
    }
    

    return 0;
}
