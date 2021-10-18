#include <stdio.h>
#include <math.h>

void solveQuadraticEquation(double, double, double);
double solveDiscriminant(double, double, double);
double solveRoot1(double, double , double , double);
double solveRoot2(double, double , double , double);

double a,b,c;
/* Prints roots of the quadratic equation a * x*x + b * x + c = 0 */
int main(void) {
    
    do
    {
        printf("Enter coeficients a, b, and c: ");
        scanf("%lf %lf %lf", &a, &b, &c);
        solveQuadraticEquation(a, b, c);  
        printf("If you want to stop the program, set a, b and c to 0!\n");
    } while (!(a == 0 && b == 0 && c == 0)); 

    return 0;
}

/*Calculates the quadratic equation and prints it out */
void solveQuadraticEquation(double a, double b, double c){
    double discriminant = solveDiscriminant(a, b, c);
    double answer_root1 = solveRoot1(a,b,c,discriminant);
    double answer_root2 = solveRoot2(a,b,c,discriminant);
    if (discriminant < 0)
    {
        printf("No roots\n");
    }
    else if(discriminant == 0)
    {
        printf("The root is: %lf\n", answer_root1);
    }
    else
    {
        printf("The roots are: %lf and %lf\n", answer_root1, answer_root2);
    }
}   

/*Calculates the discriminant */
double solveDiscriminant(double a, double b, double c){
    double discriminant = b * b - 4 * a * c;
    return(discriminant);
}

/*Calculates root 1 */
double solveRoot1(double a, double b, double c, double discriminant){
    double root1 = (-b + sqrt(discriminant))/(2*a);
    return(root1);
}

/*Calculates root 2 */
double solveRoot2(double a, double b, double c, double discriminant){
    double root2 = (-b - sqrt(discriminant))/(2*a);
    return(root2);
}


