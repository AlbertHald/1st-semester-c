/*Opgave 11 side 125*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int m, n, side_1, side_2, hypotenuse;
    
    printf("Skriv m > ");
    scanf(" %d", &m);
    printf("\n Skriv n >");
    scanf(" %d", &n);

    if (m>n)
    {
       side_1 = (m*m)-(n*n);
       side_2 = 2*m*n;
       hypotenuse = (m*m) + (n*n);

       printf("\nSide 1 er: %d  Side 2 er: %d  Hypetenusen er: %d", side_1, side_2, hypotenuse);
    }
    else
        printf("M skal vaere stoerre end N!");
        printf("Hello World");
    return 0;
}
