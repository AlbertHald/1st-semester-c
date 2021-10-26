//Navn: Albert Hald Christensen     ID: albchr21@student.aau.dk
//Studieretning: Software           Gruppe: 226

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double runCalculator(void);
void inputCalc(char *operant, double *operator);
void calculator(char operator, double operant, double *accumulator);
void squareRoot(double *accumulator);
void division(double *accumulator, double operant);

int main(void)
{
    printf("Answer: %lf", runCalculator());
    return EXIT_SUCCESS;
}

double runCalculator(void){
    int run_program = 1;
    double accumulator = 0.0, operant;
    char operator;
    printf("The calculator is running\n0\n");
    while(run_program)
    {
        inputCalc(&operator, &operant);
        calculator(operator, operant, &accumulator);
        //Stops the calulator and sets the final answer
        if(operator == 'q')
        {
            run_program = 0;  
            return accumulator;
        }
        printf("Your current value is %lf\n", accumulator);
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
        //If its a unary operator. If yes the operant is set to 0 
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
}

//The input is calculated and send back as a new accumulator value
void calculator(char operator, double operant, double *accumulator){

    //
    switch (operator)
    {
    //Unary cases
    case '#':
        squareRoot(accumulator);
        break;
    case '%':
        *accumulator = -1 * *accumulator;
        break;
    case '!':
        *accumulator = 1 / *accumulator;
        break;
    case 'q':
        *accumulator;
        break;
    //Binary cases
    case '+':
        *accumulator += operant;
        break;
    case '-':
        *accumulator -= operant;
        break;
    case '*':
        *accumulator *= operant;
        break;
    case '/':
        division(accumulator, operant);
        break;
    case '^':
        *accumulator = pow(*accumulator, operant);
        break;
    default:
        break;
    }
}
//If 0 or lower it does nothing to the accumulator
void squareRoot(double *accumulator){
    if(*accumulator > 0)
    {
        *accumulator = sqrt(*accumulator);
    }
}

//You can not divide by 0. If 0 then the accumulator is not chanced.
void division(double *accumulator, double operant){
    if (operant != 0)
    {
        *accumulator /= operant;
    }  
}