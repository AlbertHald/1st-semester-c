//Navn: Albert Hald Christensen     ID: albchr21@student.aau.dk
//Studieretning: Software           Gruppe: 226 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define FILE_PATH "kampe-2020-2021.txt"
#define TEAM_AMOUNT 12
#define MATCHES 132
#define WEEKDAY_LENGTH 4
#define MAX_DATE_LENGTH 6
#define MAX_TIME_LENGTH 6
#define MAX_TEAM_NAME_LENGTH 4
#define WIN 3
#define TIE 1

typedef struct {
    char weekday[WEEKDAY_LENGTH];
    char date[MAX_DATE_LENGTH];
    char time[MAX_TIME_LENGTH];
    char team_home[MAX_TEAM_NAME_LENGTH];
    char team_away[MAX_TEAM_NAME_LENGTH];
    unsigned int team_home_score;
    unsigned int team_away_score;
    unsigned int spectators;
} Matches;

typedef struct {
    char team_name[MAX_TEAM_NAME_LENGTH];
    unsigned int goals_scored;
    unsigned int goals_let_in;
    unsigned int points;
} Team_score;

void readFile(Matches match[], char *file_path);
void loadTeams(Matches match[], Team_score teams[]);
void giveScore(Matches match[], Team_score teams[]);
void sortScore(Team_score teams[]);
void scoreBoard(Team_score teams[]);


int main() {
    
    Matches match[MATCHES];
    Team_score teams[TEAM_AMOUNT];

    readFile(match, FILE_PATH);
    loadTeams(match, teams);
    giveScore(match, teams);
    sortScore(teams);
    scoreBoard(teams);
    
    return EXIT_SUCCESS;
}

void readFile(Matches match[], char *file_path) {
    
    //Temporary variables
    FILE *fp;
    
    // Open the file in "read" mode
    fp = fopen(file_path, "r");
    if (fp == NULL) {
        printf("This does not read");
        exit(EXIT_FAILURE); 
    }

    //Loops through the file and inserts the data in the correct place
    for (int match_index = 0; match_index < MATCHES; match_index++) {
        fscanf(fp,"%s %s %s %s - %s %u - %u %u", 
    
                                                    match[match_index].weekday,
                                                    match[match_index].date,
                                                    match[match_index].time,
                                                    match[match_index].team_home,
                                                    match[match_index].team_away,
                                                    &match[match_index].team_home_score,
                                                    &match[match_index].team_away_score,
                                                    &match[match_index].spectators);
    }

    fclose(fp);
}

void loadTeams(Matches match[], Team_score teams[]) {
    
    int curr_team_amount = 0;
    int match_index = 0;

    //Runs 132 times and check if the team exists
    while(curr_team_amount < TEAM_AMOUNT) {

        int team_found = 0, temp_team = 0;

        //If the name does note exist it puts it at index i
        //Checks all teams
        while (!team_found && temp_team < curr_team_amount) {
            if (strcmp(match[match_index].team_home, teams[temp_team].team_name) == 0) {
                
                team_found = 1;
            }
            temp_team++;   
        }

        if (!team_found) {
            strcpy(teams[curr_team_amount].team_name, match[match_index].team_home);   
            curr_team_amount++;
        }  
        
        match_index++;
    }
}

void giveScore(Matches match[], Team_score teams[]) {
    //Clean the structs with goals and points
    for (int c = 0; c < TEAM_AMOUNT; c++) {
        teams[c].goals_scored = 0;
        teams[c].goals_let_in = 0;
        teams[c].points       = 0;
    }
    
    //Runs through entire matchlist
    for (int i = 0; i < MATCHES; i++) {
        int teamhome_found = 0;
        int teamaway_found = 0;
        int teamhome_index = 0;
        int teamaway_index = 0;
        
        //Calculate goals to Team home
        while (!teamhome_found) {
            
            //Looks for the right team
            if (strcmp(match[i].team_home, teams[teamhome_index].team_name) == 0) {
                teams[teamhome_index].goals_scored += match[i].team_home_score;
                teams[teamhome_index].goals_let_in += match[i].team_away_score;

                teamhome_found = 1;
            }
            
            teamhome_index++;
        }

        //Calculate goals to Team away
        while (!teamaway_found)
        {
            //Looks for the right team
            if (strcmp(match[i].team_away, teams[teamaway_index].team_name) == 0) {
                teams[teamaway_index].goals_scored += match[i].team_away_score;
                teams[teamaway_index].goals_let_in += match[i].team_home_score;

                teamaway_found = 1;
            }
            teamaway_index++;
        }

        //Give points
        if (match[i].team_home_score > match[i].team_away_score) {
            teams[teamhome_index -1].points += (unsigned int)WIN;
        }
        else if (match[i].team_home_score == match[i].team_away_score){
            teams[teamhome_index-1].points += (unsigned int)TIE;
            teams[teamaway_index-1].points += (unsigned int)TIE;
        }
        else {
            teams[teamaway_index-1].points += (unsigned int)WIN;
        }
        
    }
}

void sortScore(Team_score teams[]) {
    char temp_name[MAX_TEAM_NAME_LENGTH];
    unsigned int temp_scored;
    unsigned int temp_let_in;
    unsigned int temp_point;

    for (int i = 0; i < TEAM_AMOUNT; i++) {
            for (int j = i + 1; j < TEAM_AMOUNT; j++) {
                if (teams[i].points < teams[j].points) {
                    //Moves the name
                    strcpy(temp_name, teams[i].team_name);
                    strcpy(teams[i].team_name, teams[j].team_name);
                    strcpy(teams[j].team_name, temp_name);
                    //Moves the goals scored
                    temp_scored = teams[i].goals_scored;
                    teams[i].goals_scored = teams[j].goals_scored;
                    teams[j].goals_scored = temp_scored;
                    //Moves the goals let in
                    temp_let_in = teams[i].goals_let_in;
                    teams[i].goals_let_in = teams[j].goals_let_in;
                    teams[j].goals_let_in = temp_let_in;
                    //Moves the points
                    temp_point = teams[i].points;
                    teams[i].points = teams[j].points;
                    teams[j].points = temp_point;
                }
            }
    }
}

//Prints scoreboard of teams
void scoreBoard(Team_score teams[]) {

    printf("|----------------------------------------------|\n");
    printf("| Teams | Points | Goals scored | Goals let in |\n");
    printf("|----------------------------------------------|\n");
    for (int i = 0; i < TEAM_AMOUNT; i++) {
        printf("| %5s | %4u   | %7u      | %7u      |\n", teams[i].team_name, teams[i].points, teams[i].goals_scored,teams[i].goals_let_in);
    }
    printf("|----------------------------------------------|\n");
}