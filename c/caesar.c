// encrypts a message by "rotating" a plaintext by a user-given key

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int n, i, key, l, j;

int main(int argc, string argv[]) {

    // CHECK IF KEY IS VALID
    if (argc == 2) {
        n = strlen(argv[1]);

        for (i = 0; i < n; i++) {
            if (!isdigit(argv[1][i])) {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }

        // CONVERT KEY FROM STRING TO INTEGER
        key = atoi(argv[1]);
        string plain = get_string("plaintext: ");
        l = strlen(plain);

        // CONVERTING PLAINTEXT TO CIPHERTEXT
        printf("ciphertext: ");
        for (j = 0; j < l; j++) {
            if (isupper(plain[j])) {
                printf("%c", (((plain[j] - 'A') + key) % 26) + 'A'); //"RESTARTS" THE ASCII VALUE, AS A TO 0, THEN RETURNS IT TO TRUE VALUE
            }
            else if (islower(plain[j])) {
                printf("%c", (((plain[j] - 'a') + key) % 26) + 'a'); //"RESTARTS" THE ASCII VALUE, AS a TO 0, THEN RETURNS IT TO TRUE VALUE
            }
            else {
                printf("%c", plain[j]);
            }
        }
    printf("\n");
    }

    // RETURNS ERROR IF FORMAT IS NOT FOLLOWED
    else {
        printf("Usage: ./casesar key\n");
        return 1;
    }
}