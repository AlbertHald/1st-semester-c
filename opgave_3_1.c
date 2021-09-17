#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define DELTA_THICC 0.2 

int main(void)
{
    double x,y,r;
    /* Indsæt punkter og radius */
    printf("Skriv først en radius og derefter punkterne x og y > ");
    scanf(" %lf %lf %lf", &r, &x, &y);
   
    /* Print om afstanden er større, lig med eller mindre end radius */ 
    double dist = sqrt(pow(x, 2.0)+(pow(y, 2.0)));
    
    printf("Punktet (%lf, %lf) ligger derfor %s cirklen",x, y, (((r + DELTA_THICC) >= dist && (r - DELTA_THICC) <= dist) ? "direkte på" : 
    (r < dist) ? "udenfor" : "indenfor"));
    return 0;
    /* Delta er intervallet, hvor distancen mellem punkterne er godtager */
}
