#include <stdio.h>
#include <cs50.h>

int main(void)
{
    float x = get_float("x: ");
    float y = get_float("y: ");

    // not possible for computer to store more than the closest possible match for the operation's result
    // precision depends on the data type
    printf("x / y = %.100f\n", x/y);
}