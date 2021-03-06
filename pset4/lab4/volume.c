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

    // DONE: Copy header from input file to output file
    // Allocate mem for header
    uint8_t *header = malloc(HEADER_SIZE * sizeof(uint8_t));
    // Check if pointer is null
    if (header == NULL)
    {
        return 1;
    }
    else
    {
        // Read, write header
        fread(header, sizeof(uint8_t), HEADER_SIZE, input);
        fwrite(header, sizeof(uint8_t), HEADER_SIZE, output);
        // Free malloc block
        free(header);
    }
    // TODO: Read samples from input file and write updated data to output file
    // Allocate memory for samples
    int16_t *sample = malloc(sizeof(int16_t));
    // Read samples one at a time
    while (fread(sample, sizeof(int16_t), 1, input))
    {
        // Multiple by factor + write sample to file
        *sample = *sample * factor;
        fwrite(sample, sizeof(int16_t), 1, output);
    }
    // Free malloc'd sample
    free(sample);
    // Close files
    fclose(input);
    fclose(output);
}
