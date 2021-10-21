/* Alle lige heltal større end 6 kan udtrykkes som summen af to ulige primtal */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int potential_primenumber = 0, even_interger = 7;

int main(void)
{
    printf("Alle lige heltal større end 6 kan udtrykkes som summen af to ulige primtal. Tjekker i intervallet 7 til 2.000.000!");
    while(even_interger >= 2000000)
    {
        /* Hvis der er to tal der giver den even interger så er dettee statement sandt */
        if (answerSuccess(even_interger))
        {
            printf("%d kan prodceres af de to ulige primtal: %d og %d", currentEvenInterger, oddPrimenumber1, oddPrimenumber2);
        }
        else
        {
            printf("%d Har ikke to ullige primtal der sammen giver det!!!!");
        }
    }
    return 0;
}



/* Vi indputter tal og isPrime tester om det er et primtal. 
Hvis det er lige bruges det*/

/* Answer success skal return 1 eller 0 */
