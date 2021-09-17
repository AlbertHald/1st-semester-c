/*17-09-2021  Aflevering 2
Et program der konverterer sekunder til Timer, Minutter og Sekunder*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SEK_MIN 60
#define SEK_TIMER 3600

int main(void)
{
    int sek_input, output_min, output_timer, output_sek;
   
    /*User input*/ 
    printf("Skriv antallet af sekunder> ");
    scanf(" %d", &sek_input);
    
    /* Mellemregningen beregner  */
    output_timer = sek_input / SEK_TIMER;
    output_min = (sek_input % SEK_TIMER) / SEK_MIN;
    output_sek = (sek_input % SEK_MIN);

    /* Hvis mere end / eller 1 time i sekunder indtastes */
    if (output_timer > 0)
    {
        /* Hvis der både er en rest minutter og sekunder */
        if((output_min > 0) && (output_sek > 0))
        {
            printf("%d %s, %d %s og %d %s", output_timer, ((output_timer > 1) ? "Timer" : "Time"), output_min, 
            ((output_min > 1) ? "Minutter" : "Minut"), output_sek, ((output_sek > 1) ? "Sekunder" : "Sekund"));
        }
        /* Hvis der er en rest minutter men ingen sekunder */    
        else if ((output_min > 0) && (output_sek == 0))
        {
            printf("%d %s og %d %s", output_timer, ((output_timer > 1) ? "Timer" : "Time"), 
            output_sek, ((output_sek > 1) ? "Sekunder" : "Sekund"));
        }
        /* Hvis der er en rest sekunder men ikke minutter */
        else if ((output_min == 0) && (output_sek > 0))
        {
            printf("%d %s og %d %s", output_timer, ((output_timer > 1) ? "Timer" : "Time"), 
            output_sek, ((output_sek > 1) ? "Sekunder" : "Sekund"));
        }
        /* Hvis der hverken er en rest af minutter eller sekunder */
        else
        {
            printf("%d %s", output_timer, ((output_timer > 1) ? "Timer" : "Time"));
        }    
    }
    
    /* Hvis mindre end / eller en time og mere en / eller 1 minut i sekunder indtastes */
    else if (output_min > 0)
    {
        /* Hvis der er en rest sekunder */
        if(output_sek > 0)
        {
            printf("%d %s og %d %s", output_min, ((output_min > 1) ? "Minutter" : "Minut"), 
            output_sek, ((output_sek > 1) ? "Sekunder" : "Sekund"));
        }
        /*Hvis der ikke er en rest sekunder */
        else
        {
            printf("%d %s", output_min, ((output_min > 1) ? "Minutter" : "Minut"));
        }
        
    }
    
    /*Hvis mindre end / eller 1 minut og mere end 0 sekunder indtastes */
    else if ((output_timer == 0) && (output_min == 0) && (output_sek > 0))
    {
        printf("%d %s", output_sek, ((output_sek > 1) ? "Sekunder" : "Sekund"));
    }
   
    /* Hvis 0 indtastes */
    else if (sek_input == 0)
    {
        printf("0 Sekunder");
    }
    return 0;
}
