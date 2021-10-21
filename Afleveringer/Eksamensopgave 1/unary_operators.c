#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char/* eller char ved det ikke helt endnu */ unary_operators(char calc_input, double akkumulator)
{
    /* Takes the squareroot of the akkumulator, returns original akkumulator value if less than 0*/
    if ('#')
    {
        if(akkumulator >= 0)
        {
            akkumulator = sqrt(akkumulator);
        }
        else
        {
            akkumulator;
        }
        
    }
    /* Switches the fortegn */
    else if ('%%')
    {
        akkumulator = -1*akkumulator;
    }
    /* Divides 1 with the akkumulator */
    else if ('!')
    {
        akkumulator = 1/akkumulator;
    }

    return(akkumulator);
}