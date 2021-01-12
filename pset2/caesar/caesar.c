#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int keyLen = 0;
int key = 0;
char rotate(char p);

// accept a single command-line argument (non-negative integer)
int main(int argc, string argv[])
{
    // check if user entered exactly 1 command-line arguments
    // check if user key contains only real numbers
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        keyLen = strlen(argv[1]);
        for (int i = 0; i < keyLen; i++)
        {
           if (!isdigit(argv[1][i]))
           {
                printf("Usage: ./caesar key\n");
                return 1;
           }
        }
    }
    // convert key to integer
    key = atoi(argv[1]);
    // print plaintext prompt to get string from user
    // iterate over plaintext, do for each character:
        // rotate and print character, if uppercase or lowercase alphabetical char
        // print original character if neither upper or lowercase
    // print a newline + return 0
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        printf("%c", rotate(plaintext[i]));
    }
    printf("\n");
    return 0;
}

char rotate(char p)
{
    return p + 1;
}
