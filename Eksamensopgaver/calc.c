#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double runCalculator(void);
void inputCalc(char *operant, double *operator);
void calculator(char operator, double operant, double *akkumulator);
void squareRoot(double *akkumulator);
void division(double *akkumulator, double operant);

int main(void)
{
    double answer = runCalculator(); 
    printf("Answer: %lf", answer);
    return EXIT_SUCCESS;
}

double runCalculator(void){
    int run_program = 1;
    double akkumulator = 0.0, operant;
    char operator;
    while(run_program)
    {
        inputCalc(&operator, &operant);
        calculator(operator, operant, &akkumulator);
        //Stops the calulator and sets the final answer
        if(operator == 'q')
        {
            run_program = 0;  
            return akkumulator;
        }
        printf("Your current value is %lf\n", akkumulator);
    } 
}

//Input unary or binary and operant. If its a unary it does not check for an operant 
void inputCalc(char *operator, double *operant){
    int input_is_valid = 0;
    //Checks if the input is valid, if not you must write inputs again
    while(!input_is_valid)
    {
        //Operator input
        scanf(" %c", operator);
        //If its a unary operator
        if(*operator == '#' || *operator == '%' || *operator == '!' || *operator == 'q')
        {
            *operant = 0.0;
            input_is_valid = 1;
        }
        //If its a binary operator
        else if(*operator == '+'|| *operator == '%'|| *operator == '/'
        || *operator == '^' || *operator == '*' || *operator == '-')
        {
            //Operant input
            scanf(" %lf", operant);
            input_is_valid = 1;
        }
        else
        {
            printf("Input is not valid! Write valid inputs >");
        }
    }
    //Hvis unær så skal scanf være 0
}

//The input is calculated and send back as a new akkumulator value
void calculator(char operator, double operant, double *akkumulator){

    switch (operator)
    {
    //Unary cases
    case '#':
        squareRoot(akkumulator);
        break;
    case '%':
        *akkumulator = -1 * *akkumulator;
        break;
    case '!':
        *akkumulator = 1 / *akkumulator;
        break;
    case 'q':
        *akkumulator;
        break;
    //Binary cases
    case '+':
        *akkumulator += operant;
        break;
    case '-':
        *akkumulator -= operant;
        break;
    case '*':
        *akkumulator *= operant;
        break;
    case '/':
        division(akkumulator, operant);
        break;
    case '^':
        *akkumulator = pow(*akkumulator, operant);
        break;
    default:
        break;
    }
}

void squareRoot(double *akkumulator){
    if(*akkumulator > 0)
    {
        *akkumulator = sqrt(*akkumulator);
    }
}

void division(double *akkumulator, double operant){
    if (operant != 0)
    {
        *akkumulator /= operant;
    }  
}



