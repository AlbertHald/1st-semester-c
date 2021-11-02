//Opgave 11 side 471-472
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void mergeArray(double*, double*, int, int);
void printTheResult(double*, int);

int main(void)
{
    double array1[] = {-7.6, -1, -0.24, 2, 3.5, 16};
    double array2[] = {-18, -4.52, -1, 3, 3.43, 17, 27, 27.43};
    //Størrelsen på array i bytes, divideret med størrelsen på den type
    //Så finder vi antallet af elementer i vores array.
    const int array1_size = sizeof(array1) / sizeof(double); //6
    const int array2_size = sizeof(array2) / sizeof(double); //8
    //Arrays into new array
    mergeArray(array1, array2, array1_size, array2_size);
    //Prints the new merged array
    return EXIT_SUCCESS;
}


void mergeArray(double *array1, double *array2, int array1_size, int array2_size){
    //Længden på det nye array
    int final_length, length = array1_size + array2_size;
    //Vi laver den stor nok til worst case at skulle tage alle elementer 
    //Dette sker hvis der ikke er nogen repeats.
    double array_merged[length];
    int array1_location = 0, array2_location = 0, array_merged_location = 0;
    //Sammenligner og kombinerer de to arrays i en ny array
    
    while(array1_size > array1_location && array2_size > array2_location)
    {
        if (array1[array1_location] > array2[array2_location])
        {
            array_merged[array_merged_location] = array2[array2_location];
            ++array2_location;
            ++array_merged_location;
        }
        else if (array1[array1_location] < array2[array2_location])
        {
            array_merged[array_merged_location] = array1[array1_location];
            ++array1_location;
            ++array_merged_location;
        }
        else if (array1[array1_location] = array2[array2_location])
        {
            array_merged[array_merged_location] = array1[array1_location];
            ++array1_location;
            ++array2_location;
            ++array_merged_location;
        }
        else
        {
            printf("Fuck");
        }    
    }
    printf("Hæljp\n");
    
    if (array1_location >= array1_size)
    {
        while (array2_location < array2_size)
        {
            array_merged[array_merged_location] = array2[array2_location];
            ++array2_location;
            ++array_merged_location;
        }
    }
    else if (array2_location >= array2_size)
    {
        while (array1_location < array1_size)
        {
            array_merged[array_merged_location] = array1[array1_location];
            ++array1_location;
            ++array_merged_location;
        }   
    }
    
    final_length = array_merged_location;
    
    printTheResult(array_merged, final_length);
}

void printTheResult(double *array_merged, int final_length){
    printf("The sorted array is > [");
    for (int array_location = 0; array_location < final_length; array_location++)
    {
        printf("%lf,", array_merged[array_location]);
    }
    printf("]");
}
