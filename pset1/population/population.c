#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int startingSize = get_int("Start size: ");
    while (startingSize < 9)
    {
        startingSize = get_int("Start size: ");
    } 
    int endingSize = get_int("End size: ");
    // TODO: Prompt for end size
    while (endingSize < startingSize)
    {
        endingSize = get_int("End size: ");
    } 
    // TODO: Calculate number of years until we reach threshold
    int years = 0;
    int p = startingSize;
    while (p < endingSize)
    {
        years += 1;
        // Each year, p/3 llamas are born and p/4 llamas die
        p = p + (p/3) - (p/4);
    }
    // TODO: Print number of years
    printf("Years: %i\n", years);
}
