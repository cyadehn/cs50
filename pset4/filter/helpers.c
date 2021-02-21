#include "stdio.h"
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
    RGBTRIPLE swap;
    // Iterate over image rows + pixels
    for (int r = 0; r < height; r++)
    {
        // Iterate over row pixels until 1/2-way thru + swap with WIDTH - ith item
        for (int p = 0, n = round(width / 2.0); p < n; p++)
        {
            swap = image[r][p];
            image[r][p] = image[r][width-(p+1)];
            image[r][width-(p+1)] = swap;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterate over image rows
    for (int r = 0; r < height; r++)
    {
        // Iterate over row pixels + average with surrounding values
        for (int px = 0; px < width; px++)
        {
            int sum = 0;
            int avg = 0;
            // Iterate over -1 to 1 x & y indexes
            for (int y = -1; y <= 1; y++)
            {
                // Check if index is outside of image height range
                if (r + y < 0 || r + y >= height)
                {
                    continue;
                }
                for (int x = -1; x <= 1; x++)
                {
                    // Check if index is outside of image width range
                    if (px + x < 0 || px + x >= width)
                    {
                        continue;
                    }
                }
            }
            
        }
    }
    // Average surrounding values + assign to current value
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
    // Average and round RGB values
    BYTE avg = round((orig.rgbtBlue + orig.rgbtGreen + orig.rgbtRed) / 3.0);
    // Assign avg to output triple value
    out.rgbtBlue = avg;
    out.rgbtGreen = avg;
    out.rgbtRed = avg;
    return out;
}