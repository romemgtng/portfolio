#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int i;
float letters = 0, words = 1, sentences = 0;
float L, S;

int main(void) {
    string text = get_string("Text: ");


    for (i = 0; text[i] != '\0'; i++) {
        // COUNT NUMBER OF LETTERS
       if (isalnum((unsigned char)text[i])) {
           letters++;
       }
        // COUNT NUMBER OF WORDS
       if (text[i] == ' ' && text[i+1] != ' ') {
           words++;
       }
        // COUNT NUMBER OF SENTENCES
       if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
           sentences++;
       }
    }

    // COMPUTATION FOR INDEX
    L = (letters/words) * 100;
    S = (sentences/words) * 100;

    float index = 0.0588*L - 0.296*S - 15.8;
    int grade = (int)(round(index));

    // GRADE LEVEL OUTPUT
    if (grade < 1) {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16) {
        printf("Grade 16+\n");
    }
    else {
        printf("Grade %d\n", grade);
    }
}