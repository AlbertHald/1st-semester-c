// A program that plays Yatzy
//Albert Hald Christensen   
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define YATZY_ROUNDS 16

int amountOfDice();
int playYatzy(int*, int);
int rollDice(int *dice_array, int dice_ammount);

int main(void)
{
    //How many dice would you like?
    int dice_ammount = amountOfDice();
    int *score = (int*) malloc(YATZY_ROUNDS * sizeof(int));
    //Rolls the dice
    playYatzy(score, dice_ammount);
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

int playYatzy(int *score, int dice_ammount)
{
    int *dice_array = (int*)malloc(dice_ammount * sizeof(int));
    //Plays upperpart, shall return the score to the elements in the "score" array
    void playUpperPart();
    //Plays lowerpart

    //Give a final score
    free(dice_array); 
}

//Should return the array but with randomized numbers
int rollDice(int *dice_array, int dice_ammount){
    for (int current_dice = 0; current_dice < dice_ammount; current_dice++)
    {
        *dice_array[current_dice] = (rand() % 5) + 5; 
    }
    
}