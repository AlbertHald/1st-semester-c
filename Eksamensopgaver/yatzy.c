// A program that plays Yatzy
//Albert Hald Christensen   
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define YATZY_ROUNDS 16

int amountOfDice();
int playYatzy(int*, int);
void playUpperPart(int dice_array[], int dice_ammount, int score[]);
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
        
        //Flush the input if its a char. Lav en function Albert Hald !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        while ((getchar()) != '\n');
    }

    return dice;
}

int playYatzy(int score[], int dice_ammount)
{
    int *dice_array = (int*)malloc(dice_ammount * sizeof(int));
    //Plays upperpart, shall return the score to the elements in the "score" array
    playUpperPart(dice_array, dice_ammount, score);
    //Plays lowerpart
    for (int i = 0; i < dice_ammount; i++)
    {
        printf(" %d ", dice_array[i]);
    }
    
    //Give a final score
    free(dice_array); 
}

void playUpperPart(int dice_array[], int dice_ammount, int score[]){
    rollDice(dice_array, dice_ammount);
}

//Should return the array but with randomized numbers
int rollDice(int dice_array[], int dice_ammount){
    for (int current_dice = 0; current_dice < dice_ammount; current_dice++)
    {
        dice_array[current_dice] = (rand() % 6) + 1; 
    } 
}