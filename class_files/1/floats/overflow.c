#include <stdio.h>
#include <unistd.h>

int main(void)
{
    for (long i = 1; ; i *= 2)
    {
        printf("%ld\n", i);
        sleep(1);
    }
}