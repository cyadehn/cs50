#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int keyLen = 0;

// accept a single command-line argument (non-negative integer)
int main(int argc, string argv[])
{
    // check if user entered exactly 1 command-line arguments
    // check if user key contains only real numbers
    if (argc != 2)
    {
        printf("Usage: ./caesar key");
        return 1;
    }
    else
    {
        keyLen = strlen(argv[1]);
        for (int i = 0; i < keyLen; i++)
        {
           if (!isdigit(argv[1][i]))
           {
                printf("Usage: ./caesar key");
                return 1;
           }
        }
    }
    printf("Success\n");
    printf("%s\n", argv[1]);
    return 0;
    // TODO: convert key to integer
    // TODO: print plaintext prompt to get string from user
    // TODO: iterate over plaintext, do for each character:
        // rotate and print character, if uppercase or lowercase alphabetical char
        // print original character if neither upper or lowercase
    // TODO: print a newline + return 0
}
