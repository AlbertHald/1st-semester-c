#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Fractions {
    int numerator;
    int denuminator;
};
typedef struct Fractions Fractions;


void shortenFraction(Fractions);
produceFraction();
multiplyFractionAndNum();
multiplyFractions();
addFractions();

int main(void) {
    Fractions frac;

    printf("Input numerator > ");
    scanf(" %d", &frac.numerator);
    printf("\nInput denuminator > ");
    scanf(" %d", &frac.denuminator);

    shortenFraction(frac);
    return EXIT_SUCCESS;
}

void shortenFraction(Fractions frac) {
    
}

