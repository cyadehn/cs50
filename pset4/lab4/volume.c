// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    // For size of file header in bytes, read until header end and write to output
    // I coooooould do this in one step by saying 'I want 44 uint8_t'... but I'd have to make my own type that's 44 bits long or... WAIT I CAN USE MALLOC RIGHT?
    uint8_t b = 0;
    for (int i = 0; i < HEADER_SIZE; i++)
    {
        fread(&b, sizeof(uint8_t), 1, )
    }
    // TODO: Read samples from input file and write updated data to output file

    // Close files
    fclose(input);
    fclose(output);
}
