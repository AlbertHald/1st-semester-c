#include <stdlib.h>
#include <stdio.h>

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
    
    int found_suffix = 0;
    int letter_count = 0;

    //Loopes from the back until the letters is not the same
    //Counts up the letters found that is the same
    while (word2[word2_count] == word1[word1_count]) {
        word2_count--;
        word1_count--;
        letter_count++;
    }
    if (letter_count == 0) {
        printf("%s and %s has no suffix", word1, )
    }
    else {
        /* code */
    }

}
