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
void playTwoPairs(int dice_array[], int dice_ammount, int score[]);
void playTOAK(int dice_array[], int dice_ammount, int score[]);
void playFOAK(int dice_array[], int dice_ammount, int score[]);
void playSmallStraight(int dice_array[], int dice_ammount, int score[]);
void playLargeStraight(int dice_array[], int dice_ammount, int score[]);
void playFullHouse(int dice_array[], int dice_ammount, int score[]);
void playChance(int dice_array[], int dice_ammount, int score[]);
void rollDice(int dice_array[], int dice_ammount);
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

    playTOAK(dice_array, dice_ammount, score);

    playFOAK(dice_array, dice_ammount, score);

    playSmallStraight(dice_array, dice_ammount, score);

    playLargeStraight(dice_array, dice_ammount, score);

    playFullHouse(dice_array, dice_ammount, score);

    playChance(dice_array, dice_ammount, score);

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
        }
        else
        {
            score[(number_to_roll_for - 1)] = 0;
        }
    
    }
    //Takes all the values of the upper and determines wether the bonus is given        
}


void playOnePair(int dice_array[], int dice_ammount, int score[]){
    int high_score = 6;
    //Array to store the values of the countDice
    int rolls_array[] ={0,0,0,0,0,0};
    int curr_array_pos = 5;
    rollDice(dice_array, dice_ammount);
    //Will store the values of the amount of each dice value
    countDice(dice_array, rolls_array, dice_ammount);

    while (rolls_array[curr_array_pos] < 2 && curr_array_pos >= 0)
    {
        --curr_array_pos;
        --high_score;
    }
    score[7] = high_score * 2;
}


void playTwoPairs(int dice_array[], int dice_ammount, int score[]){
    score[8] = 0;
    int rolls_array[] ={0,0,0,0,0,0};
    int curr_array_pos = 5;
    int found_pair = 0;
    
    rollDice(dice_array, dice_ammount);
    countDice(dice_array, rolls_array, dice_ammount);
    
    while (found_pair < 2 && curr_array_pos >= 0){
        if (rolls_array[curr_array_pos] >= 2)
        {
            score[8] += ((curr_array_pos + 1) * 2);
        }
        --curr_array_pos;
    }
}


void playTOAK(int dice_array[], int dice_ammount, int score[]){
    int rolls_array[] = {0,0,0,0,0,0};
    int curr_array_pos = 5;
    int found_TOAK = 0;
    
    rollDice(dice_array, dice_ammount);
    countDice(dice_array, rolls_array, dice_ammount);
    while (found_TOAK == 0 && curr_array_pos >= 0)
    {
        if (rolls_array[curr_array_pos] >= 3)
        {
            score[9] = ((curr_array_pos + 1) * 3);
            found_TOAK = 1;
        }
        else if (curr_array_pos == 0)
        {
            score[9] = 0;
            found_TOAK = 1;
        }
        else
        {
            --curr_array_pos;
        }
    }
}


void playFOAK(int dice_array[], int dice_ammount, int score[]){
    int rolls_array[] ={0,0,0,0,0,0};
    int curr_array_pos = 5;
    int found_FOAK = 0;
    
    rollDice(dice_array, dice_ammount);
    countDice(dice_array, rolls_array, dice_ammount);
    while (found_FOAK == 0 && curr_array_pos >= 0)
    {
        if (rolls_array[curr_array_pos] >= 4)
        {
            score[10] = ((curr_array_pos + 1) * 4);
            found_FOAK = 1;
        }
        else if (curr_array_pos == 0)
        {
            score[10] = 0;
            found_FOAK = 1;
        }
        else
        {
            --curr_array_pos;
        }
    }
}

void playSmallStraight(int dice_array[], int dice_ammount, int score[]){
    int rolls_array[] = {0,0,0,0,0,0};
    int found_small_straight = 0;
    //Starts at index 4 because we dont need 6's
    int curr_array_pos = 4;
    rollDice(dice_array, dice_ammount);
    countDice(dice_array, rolls_array, dice_ammount);

    while (curr_array_pos >= 0)
    {
        if (rolls_array[curr_array_pos] > 0)
        {
            ++found_small_straight;
        }
        --curr_array_pos; 
    }
    if (found_small_straight == 5)
    {
        score[11] = 1 + 2 + 3 + 4 + 5;
    }
    else
    {
        score[11] = 0;
    }  
}


void playLargeStraight(int dice_array[], int dice_ammount, int score[]){
    int rolls_array[] ={0,0,0,0,0,0};
    int found_large_straight = 0;
    //Starts at index 4 because we dont need 6's
    int curr_array_pos = 5;
    rollDice(dice_array, dice_ammount);
    countDice(dice_array, rolls_array, dice_ammount);

    while (curr_array_pos >= 1)
    {
        if (rolls_array[curr_array_pos] > 0)
        {
            ++found_large_straight;
        }
        --curr_array_pos; 
    }
    if (found_large_straight == 5)
    {
        score[12] = 2 + 3 + 4 + 5 + 6;
    }
    else
    {
        score[12] = 0;
    }  
}


void playChance(int dice_array[], int dice_ammount, int score[]){
    int rolls_array[] ={0,0,0,0,0,0};

    rollDice(dice_array, dice_ammount);
    countDice(dice_array, rolls_array, dice_ammount);
    
}


void playFullHouse(int dice_array[], int dice_ammount, int score[]){
    int rolls_array[] ={0,0,0,0,0,0};
    int curr_array_pos_three = 5;
    int curr_array_pos_two = 5;
    int three_found = 0;
    int two_found = 0;
    int potential_score = 0;

    rollDice(dice_array, dice_ammount);
    countDice(dice_array, rolls_array, dice_ammount);
    
    //Search for 3 of a kind
    while (curr_array_pos_three >= 0 && three_found == 0)
    {
        if (rolls_array[curr_array_pos_three] >= 3)
        {
            potential_score += (curr_array_pos_three + 1) * 3;
            three_found = 1;
            //Removes the already used values so they dont show up in 2 of a kind
            rolls_array[curr_array_pos_three] = 0;
        }
        --curr_array_pos_three;
    }
    
    //If there is 3 - search for 2 of a kind
    if (three_found == 1)
    {
        while (curr_array_pos_two >= 0 && two_found == 0)
        {
            if (rolls_array[curr_array_pos_two] >= 2)
            {
                potential_score += (curr_array_pos_two + 1) * 2;
                two_found = 1;
            }
            --curr_array_pos_two;
        }
        if (two_found == 1)
        {
            score[13] = potential_score;
        }
        else
        {
            score[13] = 0;
        }  
    }
    else
    {
        score[13] = 0;
    }
    
}

//Should return the array but with randomized numbers
void rollDice(int dice_array[], int dice_ammount){
    for (int current_dice = 0; current_dice < dice_ammount - 1; current_dice++)
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

//Prints the scoreboard when finished
void scoreBoard(int score[]){
    int upper_score = 1;
    int pair_score = 0;
    printf("\n\n|--------------Scoreboard--------------|\n");
    for (pair_score = 0; pair_score < 6; pair_score++)
    {
        printf("The score of dices showing %d       > %d\n", upper_score, score[pair_score]);
        ++upper_score;
    }
    
    printf("\nScore for Bonus                    > \n");
    printf("Score for One Pair is              > %d\n", score[7]);
    printf("Score for Two Pairs is             > %d\n", score[8]);
    printf("Score for Three Of A Kind is       > %d\n", score[9]);
    printf("Score for Four Of A Kind is        > %d\n", score[10]);
    printf("Score for Small Straight is        > %d\n", score[11]);
    printf("Score of Large Straight is         > %d\n", score[12]);
    printf("Score for Full House is            > %d\n", score[13]);
}