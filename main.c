#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// & - get the address of the variable (like A0-A15 in comparison to the EPROM)
// * - get the data / value at the address (like D0-D15 in comparison to the EPROM)

int progress;
char *text;

int english_us_dictionary_scan () {
    unsigned short matching_characters_amount_per_word;

    FILE *us_words = fopen("words/english_US.txt", "r"); // initialises the file
    if (us_words == NULL) { // if file is missing or there is an issue return -1
        printf("File is Empty!\n");
        return -1;
    }

    char word_in_dictionary[256]; // holds the word on each line
    while (fgets(word_in_dictionary, sizeof(word_in_dictionary), us_words) != NULL) { // loops through each line from the file and [fgets] returns NULL when at the end of the file
        word_in_dictionary[strcspn(word_in_dictionary, "\n")] = '\0'; // strcspn finds the position of \n and replaces it with \0 to clean up the string
        
        /*
            assign a point rating system for each matching character and then turn it into a percent (e.g. a 5 letter word with 3 letters matching would be 60% and say that it's an AI even though it's an algorithm)
        
            make it so there is a rating for how many characters match and then also a rating for how many characters match in the same position

            for loop for each character
        */

        // compare each char of word_in_dictionary to text (eventually make it word in text)
        for (int i=0; i <= strlen(text); i++) {
            for (int j=0; j <= strlen(word_in_dictionary); j++) {
                if(text[i] == word_in_dictionary[j]) {
                    // assign a point rating system for each matching character and then turn it into a percent (e.g. a 5 letter word with 3 letters matching would be 60% and say that it's an AI even though it's an algorithm)
                    matching_characters_amount_per_word++;

                    // make it so there is a rating for how many characters match and then also a rating for how many characters match in the same position

                }
            }
        }
        

        // if (strcmp(word_in_dictionary, text) == 0) { // compares two strings and returns 0 when identical
        //     printf("String Matches 100%%, the word is:\n", word_in_dictionary);
        // }
    }
    fclose(us_words);
    return 0;
}

int ceasars_decypher() {

    int shifted_by;

    english_us_dictionary_scan();

    for(int j=0; j < 26; j++) {
        for(int i=0; i < strlen(text); i++) {
            printf("%c", text[i]);
            if ((int)text[i] >= 'z') {
                text[i] = 'a';
            } else {
                text[i]++;
            }
            shifted_by = j;
        }
        printf("\n");
    }

    if (shifted_by > 13) {
        shifted_by = 13 - shifted_by;
    } else {
        // nothing
    }
    printf("Original text is most likely shifted by %d\n", shifted_by);

    free(text);

    return 0;
}



int cypher_main() {
    printf("Please enter the text you want to encypher:\n");
    text = malloc(1000 * sizeof(char));
    scanf("%s", text);
    printf("\n");

    return 0;
}



int decypher_main() {
    printf("Please enter the text you want to decypher:\n");
    text = malloc(1000 * sizeof(char));
    scanf("%s", text);


    ceasars_decypher();
    printf("Checking ceasars cypher...\nProgress: %d%%", progress);
    return 0;
}



int main() {
    int user_input;
    printf("Would you like to encypher or decypher the message?\n");
    printf("1. Encypher\n");
    printf("2. Decypher\n");
    printf("3. Exit\n");

    scanf("%d", &user_input);
    
    switch (user_input) {
    case 1:
        cypher_main();
        break;
    case 2:
        decypher_main();
        break;
    case 3:
        return 0;
        break;    
    default:
        break;
    }

    return 0;
}