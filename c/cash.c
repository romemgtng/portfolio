// computes the minimum number of coins a person is owed in change

#include <stdio.h>
#include <cs50.h>
#include <math.h>

float dollars;
int cents, count;

int main(void) {
    // INPUT CHANGE DUE
    do {
        dollars = get_float("Change owed: ");
    }
    while (dollars <= 0);

    // CONVERT CENTS TO INTEGER FOR PRECISION
    cents = round(dollars * 100);

    for (;cents >= 25; count++) {
        cents = cents - 25;
    }

    for (;cents >= 10; count++) {
        cents = cents - 10;
    }

    for (;cents >= 5; count++) {
        cents = cents - 5;
    }

    for (;cents >= 1; count++) {
        cents = cents - 1;
    }

    printf("%d\n", count);
}