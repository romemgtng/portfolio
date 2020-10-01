#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            // GET AVERAGE OF ALL PIXELS
            float newColor = (round(red) + round(green) + round(blue)) / 3;
            newColor = round(newColor);

            image[i][j].rgbtRed = newColor;
            image[i][j].rgbtGreen = newColor;
            image[i][j].rgbtBlue = newColor;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            // SEPIA EQUATION
            float sepiaRed = 0.393 * red + 0.769 * green + 0.189 * blue;
            float sepiaGreen = 0.349 * red + 0.686 * green + 0.168 * blue;
            float sepiaBlue = 0.272 * red + 0.534 * green + 0.131 * blue;

            // SETS MAX VALUE TO 255
            if (sepiaRed >= 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = round(sepiaRed);
            }

            if (sepiaGreen >= 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = round(sepiaGreen);
            }

            if (sepiaBlue >= 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = round(sepiaBlue);
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // PLACE PIXEL IN A TEMPORARY BIN BEFORE SWAPPING
            int tempRed = image[i][j].rgbtRed;
            int tempGreen = image[i][j].rgbtGreen;
            int tempBlue = image[i][j].rgbtBlue;

            image[i][j].rgbtRed = image[i][width - 1 - j].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - 1 - j].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - 1 - j].rgbtBlue;

            image[i][width - 1 - j].rgbtRed = tempRed;
            image[i][width - 1 - j].rgbtGreen = tempGreen;
            image[i][width - 1 - j].rgbtBlue = tempBlue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // CREATE COPY FILE
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float count = 0, newRed = 0, newGreen = 0, newBlue = 0;

            // CHECK IF ADJACENT PIXELS EXIST, ASSUME 3x3 GRID AROUND EACH PIXEL
            for (int a = 0; a < 3; a++)
            {
                for (int b = 0; b < 3; b++)
                {
                    if ((i + a - 1 >= 0 && i + a - 1 < height) && (j + b - 1 >= 0 && j + b - 1 < width))
                    {
                        // ADD VALUES IF PIXELS EXIST
                        newRed = newRed + (float)copy[i + a - 1][j + b - 1].rgbtRed;
                        newGreen = newGreen + (float)copy[i + a - 1][j + b - 1].rgbtGreen;
                        newBlue = newBlue + (float)copy[i + a - 1][j + b - 1].rgbtBlue;
                        count++;
                    }
                }
            }

            // CHANGE PIXEL COLOR TO AVERAGE OF SURROUNDINGS
            image[i][j].rgbtRed = (int)round(newRed / count);
            image[i][j].rgbtGreen = (int)round(newGreen / count);
            image[i][j].rgbtBlue = (int)round(newBlue / count);
        }
    }
    return;
}
