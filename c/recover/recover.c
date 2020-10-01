#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#define blockSize 512


bool isjpgHeader(uint8_t buffer[])
{
    // CHECK IF FILE STARTS WITH JPG HEXADECIMAL
    return buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0;
}

int main(int argc, char *argv[])
{
    // CHECK IF VALID COMMAND LINE ARGUMENT
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    char *inputFile = argv[1];
    if (inputFile == NULL)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // CHECK IF FILE CAN BE OPENED
    FILE *inputPtr = fopen(inputFile, "r");
    if (inputPtr == NULL)
    {
        printf("Unable to open file: %s\n", inputFile);
        return 1;
    }


    char fileName[8];
    FILE *outputPtr = NULL;
    uint8_t buffer[blockSize];
    int jpgCounter = 0;

    while (fread(buffer, sizeof(uint8_t), blockSize, inputPtr) || feof(inputPtr) == 0)
    {
        if (isjpgHeader(buffer))
        {
            if (outputPtr != NULL)
            {
                fclose(outputPtr);
            }
            sprintf(fileName, "%03i.jpg", jpgCounter);
            outputPtr = fopen(fileName, "w");
            jpgCounter++;
        }
        if (outputPtr != NULL)
        {
            fwrite(buffer, sizeof(buffer), 1, outputPtr);
        }
    }

    if (inputPtr == NULL)
    {
        fclose(inputPtr);
    }

    if (outputPtr == NULL)
    {
        fclose(outputPtr);
    }
    return 0;
}