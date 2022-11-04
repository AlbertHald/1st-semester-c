//A program that finds the longest suffix of two words.
//Found with snprintf. DONE

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void findSuffix(char word1[], char word2[]);

int main()
{
    char word1[] = {"program"};
    char word2[] = {"diagram"};

    findSuffix(word1, word2);
    return 0;
}

void findSuffix(char word1[], char word2[]) {
    //Search for same and if there is any, count up the amount of letters that is the same.
    int word1_count = 0;
    int word2_count = 0;

    //Counts first word
    while (word1[word1_count] != '\0') {
        word1_count++;
    }

    //Counts second word
    while (word2[word2_count] != '\0') {
        word2_count++;
    }
    
    //Removes the end of line so it does not get compared
    word1_count--;
    word2_count--;

    int found_suffix = 0;
    int letter_count = 0;

    //Loopes from the back until the letters is not the same
    //Counts up the letters found that is the same
    while (word2[word2_count] == word1[word1_count]) {
        word2_count--;
        word1_count--;
        letter_count++;
        found_suffix = 1;
    }

    //If no suffix is found
    if (found_suffix == 0) {
        printf("%s and %s has no suffix", word1, word2);
    }

    //Produce the suffix and prints it out
    else {
        //Allocates ram for the suffix with space for the end of string caracter 
        char *suffix = malloc((letter_count + 1)  * sizeof(char));

        //Puts the suffix in the suffix array
        snprintf(suffix, letter_count + 1, word1 + (word1_count + 1));
        printf("The suffix of %s and %s is %s", word1, word2, suffix);

        free(suffix);
    }
}
