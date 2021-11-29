//A program that represents a polynomium that has n coeficients. Max of 8 
//DONE Mangler at printe det regnet poly

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int inputNCoefficients(void);
void definePolynomium(double coeff[], int max_coefficients);
void inputXValue(double*);
double evalPolynomium(double coeff[], double x_value, int max_coefficents);
double calcPolynomium(double coeff[], double x_value, int max_coef);
void flushInput(void);

int main(void) {
    
    //Returns the ammount of coefficients wanted
    int max_coefficients = inputNCoefficients();
    printf("Max_coeff is > %d\n", max_coefficients);
    
    //Allocating array space
    double *coeff = (double*) malloc(max_coefficients * sizeof(double));
    definePolynomium(coeff, max_coefficients);
    
    //Input x value
    double x_value;
    inputXValue(&x_value);

    printf("\nThe value of x is: %lf", x_value);
    
    //Prints the polinomium and calculates it
    evalPolynomium(coeff, x_value, max_coefficients);
    
    free(coeff);
    return EXIT_SUCCESS;
}

int inputNCoefficients(void) {
    int coe_amount; 
    printf("\nHow many coefficients do you want? > ");
    scanf(" %d", &coe_amount);
    return coe_amount;
}

void definePolynomium(double coeff[], int max_coefficients) {
    double coeff_input = 0;
    printf("\nmax_coefficients is now %d\n", max_coefficients);
    
    //Input the a values up to a*n
    for (int i = 0; i < max_coefficients; i++) {
        if (i == 0) {
            printf("\nEnter the %dst value > ", i + 1);
        }
        else if(i == 1) {
            printf("\nEnter the %dnd value > ", i + 1);
        }
        else if(i == 2) {
            printf("\nEnter the %drd value > ", i + 1);
        }
        else {
            printf("\nEnter the %dth value > ", i + 1);
        }
        scanf(" %lf", &coeff_input); 
        
        //Flushes the inputbuffer
        flushInput();

        coeff[i] = coeff_input;
    }
}

void inputXValue(double* x_value) {
    printf("\nInput the value of x > ");
    scanf(" %lf", x_value);
}

double evalPolynomium(double coeff[], double x_value, int max_coefficents) {
    printf("The polinomium : p(x) = ");
    
    //Prints the polynomium 
    for (int i = 0; i < max_coefficents; i++) {
        if (i > 0 && coeff[i] > 0) {
            printf("+ %lfx^%d", coeff[i], i);
        }
        else if (i == 0) {
            printf("%lf", coeff[i]);
        }
        else {
            printf("%lfx^%d", coeff[i], i);
        }
    }
    return calcPolynomium(coeff, x_value, max_coefficents);
}

//Flush the input buffer
void flushInput(void) {
    while ((getchar()) != '\n');
}

double calcPolynomium(double coeff[], double x_value, int max_coef) {
    double answer = 0;

    for (int i = 0; i < max_coef; i++) {
        if (i == 0) {
            answer += coeff[i];
        }
        else {
            answer += coeff[i] * (pow(x_value, i));
        }   
    }
    return answer;
}
