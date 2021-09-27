#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int input_1, input_2, modulus_out, i, GCD = 0, num_found = 0; 
    /* Skriv to positive hele tal */
    scanf("%d", &input_1);
    scanf("%d", &input_2);
    /* Har to tal. finder det største og tager divisoren af det */
    int max_input = (input_1 >= input_2) ? input_1 : input_2; 
    int min_input = (input_1 < input_2) ? input_1 : input_2;
    /* Så længe number ikke er found kører den videre */
    /* Hvor i er fælles divisor */
    /* Kører igennem indtil den største divisor er fundet */
    if (max_)
    {
        /* code */
    }
    
    i = min_input;
    while (!num_found)
    {
        if (max_input % i == 0 && min_input % i == 0)
        {
            num_found = 1;
        }
            
        else
        {
            i--;
        }
            
    }
    printf("GCD er derfor %d", i);
    
    return 0;
}
