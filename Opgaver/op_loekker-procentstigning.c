/* Befolkning på 9870 personer vokser med 10% om året. 
Hvor mange år tager det før befolkningen er over 30000 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int years = 0, population = 9870;
    double pop_growth = 1.1;

    while (population <= 30000)
    {
        population = population * pop_growth;
        years++;
    }
    printf("%d", years);

    return 0;
}
