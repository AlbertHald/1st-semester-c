#include <math.h>
#include <stdio.h>
#include <stdlib.h>
void sqrArray(void);
void cubeArray(void);

#define ARRAY_LEGHT 11


int main(void)
{
    sqrArray();
    cubeArray();    
    return EXIT_SUCCESS;
}

void cubeArray(void){
    int cube_array[ARRAY_LEGHT];
    int cube_array_location = 0;
    printf("Her printes cube\n");
    for (int array_location = 0; array_location < ARRAY_LEGHT; array_location++)
    {
        cube_array[array_location] = cube_array_location * cube_array_location;
        printf("%d\n", cube_array[array_location]);
        ++cube_array_location;
    }
    
}
//DET HER FUNGERER IKKE LORTE LORT
void sqrArray(void){
    double sqr_array[ARRAY_LEGHT];
    double sqr_array_location = 0.0;
    printf("Her printes square root\n");
    for (int array_location = 0; array_location < ARRAY_LEGHT; array_location++)
    {
        if(sqr_array_location == 0){
            sqr_array[array_location] = 0.0;
        }
        else{
            sqr_array[array_location] = sqrt(sqr_array_location);
        }
        printf("%lf\n", sqr_array[array_location]);
        ++sqr_array_location;
    }
    
}