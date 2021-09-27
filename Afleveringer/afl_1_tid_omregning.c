/*Albert Hald   08-09-2021  Aflevering 1
Et program der konverterer sekunder til Timer, Dage, Timer, Minutter og Sekunder*/
#include <stdio.h>

#define sek_min 60
#define sek_timer 3600
#define sek_dage 86400
#define sek_uger 604800

int main(void)
{
    int sek_input, output_min, output_timer, output_dage, output_uger, output_sek;
    /*User input*/ 
    printf("Skriv antallet af sekunder> ");
    scanf(" %d", &sek_input);
    
    /*Divederer input med antallet af sekunder på en uge (Heltal)*/
    output_uger = sek_input / sek_uger;
    /*Dividerer resten af user input med sekunder på en dag*/
    output_dage = (sek_input % sek_uger) / sek_dage;
    /*osv.*/
    output_timer = (sek_input % sek_dage) / sek_timer;
    output_min = (sek_input % sek_timer) / sek_min;
    output_sek = (sek_input % sek_min);

    /*Output*/
    printf("\nUger: %d Dage: %d Timer: %d Minutter: %d Sekunder: %d",output_uger, output_dage, output_timer, output_min, output_sek);
    return 0;
}