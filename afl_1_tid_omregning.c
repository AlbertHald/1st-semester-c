//Albert Hald   08-09-2021  Aflevering 1
//Et program der konverterer sekunder til Timer, Dage, Timer, Minutter og Sekunder
#include <stdio.h>

#define sec_min 60
#define sec_hour 3600
#define sec_day 86400
#define sec_week 604800

int main(void)
{
    int sec_input, output_min, output_hour, output_day, output_week, output_sec;
    //User input 
    printf("Skriv antallet af sekunder> ");
    scanf("%d", &sec_input);
    
    //Divederer input med antallet af sekunder på en uge (Heltal)
    output_week = sec_input / sec_week;
    //Dividerer resten af user input med sekunder på en dag
    output_day = (sec_input % sec_week) / sec_day;
    //osv.
    output_hour = (sec_input % sec_day) / sec_hour;
    output_min = (sec_input % sec_hour) / sec_min;
    output_sec = (sec_input % sec_min);

    //Output
    printf("\nWeeks: %d Days: %d Hour: %d Minutes: %d Seconds: %d",output_week, output_day, output_hour, output_min, output_sec);
    return 0;
}