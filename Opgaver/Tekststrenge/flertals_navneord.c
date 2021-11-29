#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void flush(void);

int main(void) {
    
    flush();

    return EXIT_SUCCESS;
}

void flush(void) {
    while ((getchar()) != '\n');
}