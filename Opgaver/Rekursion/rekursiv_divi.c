#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    int dividend, divisor;
    printf("Type dividend > ");
    scanf(" %d", &dividend);
    printf("\nType divisor >");
    scanf(" %d", &divisor);

    int division_answer = division(dividend, divisor);

    return 0;
}


int division(int divident, int divisor) {

    
    return division(divident - divisor, divisor);
}
//Function that recursivly divides by using the "-" operator 

int modulus(int divident, int divisor) {
    
}