/* Et program der finder største fælles divisor */
/* 27-09-2021 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int input_1, input_2, pos_divisor; 
    char GoAgain;
    do
    {    
        int GCD = 0,  NumFound = 0;
        /* Skriv to positive hele tal */
        printf("Skriv et helt positivt tal > ");
        scanf(" %d", &input_1);
        printf("Skriv et helt positivt tal mere > ");
        scanf(" %d", &input_2);
        /* Finder det største tal af de to inputs */
        int max_input = (input_1 >= input_2) ? input_1 : input_2; 
        int min_input = (input_1 < input_2) ? input_1 : input_2;
        
        /* Tjekker om et af de indtastet tal er 0 */
        if (min_input == 0) {
            pos_divisor = max_input;
            NumFound = 1;
        }
        
        /* Kører fra det laveste af de to tal og ned til 0.
        Stopper ved den første (største) divisor for begge */
        pos_divisor = min_input;
        while (!NumFound) {
            if (max_input % pos_divisor == 0 && min_input % pos_divisor == 0) {
                NumFound = 1;
            }    
            else {
                pos_divisor--;
            }         
        }
        printf("GCD for de to tal %d og %d er derfor: %d \n", max_input, min_input, pos_divisor); 
        /* Skal programmet køres igen? */
        printf("Skal programmet koere igen? Tryk Y/y ellers tryk en vilkaarlig knap");
        scanf(" %c", &GoAgain);
    }
    while (GoAgain == 'y' || GoAgain == 'Y');
    return 0;
}
