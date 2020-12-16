// get_float to get user's change owed DONE
// re-prompt if negative DONE
// convert dollars to cents (float to int) DONE
// round to nearest penny (eg. round (dollars * 100) to int value)
// implement greedy algorithm DONE
// last line = "%i\n" DONE
#include <cs50.h>
#include <stdio.h>

int GetCoinNum();

int main(void)
{
    float input = 0;
    while (!(input > 0))
    {
        input = get_float("Please enter the change owed (ex. '$$.CC'): ");
    }
    int cents = (input * 100);
    int coinNum = GetCoinNum(cents);
    printf("%i\n", coinNum);
}

//Recursively get cents as the passed values become less and less
//Recursion terminates when the value passed is less than 5 (meaning they just become pennies/cents!)
int GetCoinNum(int cents)
{
    if (cents < 5)
    {
        return cents;
    }
    if (cents < 10)
    {
        return (cents / 5) + GetCoinNum(cents % 5);
    }
    if (cents < 25)
    {
        return (cents / 10) + GetCoinNum(cents % 10);
    }
    return (cents / 25) + GetCoinNum(cents % 25);
}
