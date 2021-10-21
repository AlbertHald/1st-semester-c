#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define DOLLAR_TO_EURO 0.86
#define DOLLAR_TO_KRONER 6.39
#define DOLLAR_TO_RUBLER 71.05
#define DOLLAR_TO_YEN 114.30

double inputDollar(void);
void valutaConverter(double);
void convertDollar(double, double *, double *, double *, double *);

int main(void)
{
    valutaConverter(inputDollar());
    return EXIT_SUCCESS;
}

double inputDollar(void){
    double input;
    printf("Skriv dine dollars: ");
    scanf("%lf", &input);
    return input;
}

void valutaConverter(double input_som_det_er_at_der_er_dollars){
    double euro, kroner, rubler, yen;
    convertDollar(input_som_det_er_at_der_er_dollars, &euro, &kroner, &rubler, &yen);
    printf("%lf Dollars converts to: %lf Euro    %lf kroner  %lf rubler    %lf yen!!!!!!!\n", 
    input_som_det_er_at_der_er_dollars, euro, kroner, rubler, yen);
}

void convertDollar(double input, double *euro, double *kroner, double *rubler, double *yen){
    *euro = input * DOLLAR_TO_EURO; 
    *kroner = input * DOLLAR_TO_KRONER;
    *rubler = input * DOLLAR_TO_RUBLER;
    *yen = input * DOLLAR_TO_YEN;
}
