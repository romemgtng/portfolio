#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompt that asks user for their name//
    string name = get_string("What is your name?\n");

    printf("Hello, %s\n", name);
}