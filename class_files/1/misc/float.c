#include <cs50.h>
#include <stdio.h>

int main(void)
{
    float price = get_float("What's the price of the item you want? ");
    float tax = 1.0625;
    printf("Your total is %f! :D\n", price * tax);
    get_string("");
    printf("Oh... you want that rounded? Okay!\n");
    printf("Your rounded total is %.2f!\n", price * tax);
}