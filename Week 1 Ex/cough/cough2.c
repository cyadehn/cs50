#include <stdio.h>

int main(void)
{
    cough(19);
}

void cough(int times)
{
    for ( int i = 0; i < times; i++ )
    {
        printf("cough\n");
    }
}

