#include <stdio.h>
#include <cs50.h>

int a = 0;
int loop = 0;
int i, space, hash, height;

int main(void){

    // CHECK IF HEIGHT IS IN RANGE
    while (loop == 0) {
        int a = get_int("Height: ");
        if (a < 1 || a > 8)
                continue;
            else
            height = a;
            loop = 1;
    }

    // PRINTING THE TRIANGLE
    for (i = 0; i <= height - 1; i++) {
        for (space = (height - i); space >= 2; --space) {
            printf(" ");
        }
        for (hash = 1; hash <= (i + 1); hash++) {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}