#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //while ( true )
    //{
     //   printf("hello, world\n");
       //
    //}
    int i = 0;
    printf("%i", i);
    while ( i < 50 )
    {
        printf("Hello, world!\n");
        i++;
        printf("%i\n", i);
    }
    for ( int counter = 1; counter < 10; counter++ )
    {
        printf("Hello, world! You're on your %ith life! :)\n", counter);
    }
}