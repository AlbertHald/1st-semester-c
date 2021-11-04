// A program that plays Yatzy
//Albert Hald Christensen   
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <assert.h>

#define YATZY_ROUNDS 16

int amountOfDice();
void playYatzy(int*, int);
void playUpperPart(int dice_array[], int dice_ammount, int score[]);
void playOnePair(int dice_array[], int dice_ammount, int score[]);
void rollDice(int *dice_array, int dice_ammount);
void countDice(int dice_array[], int rolls_array[], int dice_ammount);
void scoreBoard(int score[]);

int main(void)
{   
    //Seeding
    srand(time(0));
    //How many dice would you like?
    int dice_ammount = amountOfDice();
    int *score = (int*) malloc(YATZY_ROUNDS * sizeof(int));
    
    playYatzy(score, dice_ammount);
    scoreBoard(score);

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

void playYatzy(int score[], int dice_ammount)
{
    int *dice_array = (int*)malloc(dice_ammount * sizeof(int));
    //Plays upperpart, shall return the score to the elements in the "score" array
    playUpperPart(dice_array, dice_ammount, score);
    //Plays lowerpart
    playOnePair(dice_array, dice_ammount, score);

    playTwoPairs(dice_array, dice_ammount, score);

    //playTOAK(dice_array, dice_ammount, score);

    //playFOAK(dice_array, dice_ammount, score);

    //playSmallStraight(dice_array, dice_ammount, score);

    //playLargeStraight(dice_array, dice_ammount, score);

    //playFullHouse(dice_array, dice_ammount, score);

    //playChance(dice_array, dice_ammount, score);

    //playYatzyRound(dice_array, dice_ammount, score);
    //Give a final score
    scoreBoard(score);
    free(dice_array); 
}

void playUpperPart(int dice_array[], int dice_ammount, int score[]){
    
    //Goes through the numbers 1 to 6 to collect the number of each.
    for(int number_to_roll_for = 1; number_to_roll_for < 7; number_to_roll_for++)
    {
        //Roll the dice
        rollDice(dice_array, dice_ammount);
        int dice_collected = 0;
        //Runs through the array and looks for the number to roll for
        for (int i = 0; i < dice_ammount - 1; i++)
        {
            if(dice_array[i] == number_to_roll_for)
            {
                //Collect max of 5 dice
                if(dice_collected < 5)
                {
                    ++dice_collected;
                }
            }
        }  
        
        //Store the score values in position
        if (dice_collected > 0)
        {
            score[number_to_roll_for - 1] = number_to_roll_for * dice_collected;
            printf("\nThe score of round: %d is > %d", (number_to_roll_for), score[(number_to_roll_for - 1)]);
        }
        else
        {
            score[(number_to_roll_for - 1)] = 0;
            printf("\nThe score of round: %d is > %d", number_to_roll_for, score[(number_to_roll_for - 1)]);
        }
        //SKal have bonus med!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    }    
}

void playOnePair(int dice_array[], int dice_ammount, int score[]){
    int high_score = 6;
    int rolls_array[] ={0,0,0,0,0,0};
    int curr_array_pos = 5;
    rollDice(dice_array, dice_ammount);
    countDice(dice_array, rolls_array, dice_ammount);

    while (rolls_array[curr_array_pos] < 2 && curr_array_pos >= 0)
    {
        --curr_array_pos;
        --high_score;
    }
    score[7] = high_score * 2;
}

playTwoPairs()

//Should return the array but with randomized numbers
void rollDice(int dice_array[], int dice_ammount){
    for (int current_dice = 0; current_dice < dice_ammount; current_dice++)
    {
        dice_array[current_dice] = (rand() % 6) + 1; 
    }
}
void countDice(int dice_array[], int rolls_array[], int dice_ammount){

    //Goes through the dice array and check the value in a switch
    for (int curr_dice = 0; curr_dice < dice_ammount - 1; curr_dice++)
    {
        switch (dice_array[curr_dice])
        {
            case 1:
                rolls_array[0]++; break;
            case 2:
                rolls_array[1]++; break;
            case 3:
                rolls_array[2]++; break;   
            case 4:
                rolls_array[3]++; break;
            case 5:
                rolls_array[4]++; break; 
            case 6:
                rolls_array[5]++; break; 
            default:
                break;
        }
    }
    
}
//Indexering
void scoreBoard(int score[]){
    int upper_score = 1;
    int pair_score = 0;
    printf("\n\n|----------Scoreboard----------|\n");
    for (pair_score = 0; pair_score < 6; pair_score++)
    {
        printf("The score of dices showing %d       > %d\n", upper_score, score[pair_score]);
        ++upper_score;
    }
    
    printf("Score for bonus                    > \n");
    printf("Score for one pair is              > %d\n", score[7]);
    printf("\n");
    printf("\n");
}