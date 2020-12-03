// Conditions and relational operators

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for x
    int x = get_int("x: ");

    // Prompt user for y
    int y = get_int("y: ");

    //Compare x and y
    if (x<y)
    {
        printf("x(%i) is less than y(%i)\n", x, y);
    }
    else if (x>y)
    {
        printf("x(%i) is greater than y(%i)\n", x, y);
    }
    else
    {
        printf("x(%i) is equal to y(%i)\n", x, y);
    }
}