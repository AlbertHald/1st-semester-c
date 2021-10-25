#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "unary_operators.h"
#include "binary_operators.h"

double akkumulator = 0.0;
int end_program = 0;
char calc_input;

int main(void)
{
    while(!end_program)
    {
        /* Ends the program */
        if(calc_input = "q")
        {
            end_program = 1;  
            printf("Answer: %f", akkumulator);
        }
        else if (/* condition */)
        {
            /* code */
        }
        
        
    }
    /* Unær operatorer skal regnes med input sådan: unær_operator akkumulator */
    /* Binære operatorer skal regnes med input sådan: akkumulator binær_operator højre_opperand */
    return EXIT_SUCCESS;
}
