#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string input = "";
    string quit = "quit";
    int n = 0;
    while ( input != quit )
    {
        n = get_int("n: ");
        if ( n % 2 == 0)
        {
            printf("Your number is even!\n");
        }
        else
        {
            printf("Your number is odd... strange.\n");
        }
        input = get_string("Type 'quit' to exit... ");
    }

}