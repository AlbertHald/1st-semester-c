#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#define TEAMS 12
#define MATCHES 132
#define MAX_DATE_LENGTH 12
#define MAX_TEAM_NAME_LENGTH 5
#define DAYS_IN_WEEK 7

enum days_in_week{Man, Tir, Ons, Tor, Fre, Lor, Son};

typedef struct {
    int weekday[DAYS_IN_WEEK];
    char date[MAX_DATE_LENGTH];
    char team[MAX_TEAM_NAME_LENGTH];
    int goals;
    int goals_against;
    int spectators
} football_team;


int main() {
    readFile();

    return EXIT_SUCCESS;
}
