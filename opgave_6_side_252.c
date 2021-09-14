#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    double x,y;
    /* Indtast de to punkter */
    printf("Skriv din x-værdi i kommatal > ");
    scanf(" %f", &x);

    printf("Skriv din y-værdi i kommatal > ");
    scanf(" %f", &y);

    if (x != 0.0 || y != 0.0)
    {
        /* Første kvadrat */
        if(x > 0.0 && y > 0.0)
        {
            printf("1.");
        }
        /*Anden kvadrant */
        else if (x < 0.0 && y > 0.0)
        {
            printf("2.");
        }
        /* Tredje kvadrant */
        else if (x < 0.0 && y < 0.0)
        {
            printf("3.");
        }
        /* Fjerde kvadrant */
        else if(x > 0.0 && y < 0.0)
        {
            printf("4.");
        }
        else{
            printf("Skriv noget ordenligt!");
        }
        
    }
    /* Exe hvis punktet ligger på y- eller x-aksen */
    else if(x == 0.0 || y == 0.0)
    {
        if(x == 0.0)
        {
            printf("\n(%f, %f) is on the x-axis",x, y);
        }
        else
        {
            printf("\n(%f, %f) is on the y-axis", x, y);
        }
    }
    else{
        printf("Skriv noget ordenligt");
    }
    return 0;
}
