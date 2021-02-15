#include "helpers.h"
#include "math.h"

RGBTRIPLE greyscalePx();

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE in, out;
    BYTE avg = 0;
    // Iterate over rows + pixels
    for (int r = 0; r < height; r++)
    {
        for (int p = 0; p < width; p++)
        {
            // Average BRG values + assign to each byte
            in = image[r][p];
            out = greyscalePx(in);
            image[r][p] = out;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterate over image rows
    // Iterate over row pixels until 1/2-way thru + swap with WIDTH - ith item
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterate over image rows
    // Iterate over row pixels + average with surrounding values
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterate over rows
    // Iterate over row pixels + apply image processing matrices
    // Calculate Sobel value and assign to output stream
    return;
}

RGBTRIPLE greyscalePx(RGBTRIPLE orig)
{
    RGBTRIPLE out;
    BYTE avg = rint((orig.rgbtBlue + orig.rgbtGreen + orig.rgbtRed) / 3);
    out.rgbtBlue = avg;
    out.rgbtGreen = avg;
    out.rgbtRed = avg;
    return out;
}