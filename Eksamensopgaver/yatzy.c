// A program that plays Yatzy
//Albert Hald Christensen   
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define YATZY_ROUNDS 16

int amountOfDice();
int sumSection(int);

int main(void)
{
    //How many dice would you like?
    int dice_ammount = amountOfDice();
    printf("\nDice > %d", dice_ammount);

    int *score = (int*) malloc(YATZY_ROUNDS * sizeof(int));
    //Rolls the dice
    playYatzy();
    //Play sum section
    //sumSection();
    //Play lower section
    //lowerSection();
    free(score);
    return EXIT_SUCCESS;
}

int amountOfDice(){
    int dice = 0;
    while(dice < 5)
    {
        printf("How many dice do you want to play with?\n\nYou must play with atleast 5 dice >");
        scanf(" %d", &dice);
        
        //Flush the input if its a char. 
        while ((getchar()) != '\n');
    }

    printf("\nHjælp mig kurt");
    return dice;
}

int sumSection(int dice_ammount)
{
    return dice_ammount;
}