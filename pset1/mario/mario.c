#include <stdio.h>
#include <cs50.h>

int get_pos_int(string prompt);
void buildPyramid(void);
void buildLevel(void);
void buildLeftSide(void);
void buildRightSide(void);
void printChars(int num, string chars);
int level;
int levels;

int main(void)
{
    levels = get_pos_int("Please enter the desired number of levels: ");
    buildPyramid();
}

int get_pos_int(string prompt)
{
    int n = 0;
    while ( n < 1 )
    {
        n = get_int("%s", prompt);
    }
    return n;
}

void buildPyramid()
{
    for ( int i = 0; i < levels; i++ )
    {
        level = i + 1;
        buildLevel();
    }
    level = 0;
}

void buildLevel()
{
    buildLeftSide();
    printf("  ");
    buildRightSide();
    printf("\n");
}

void buildLeftSide(void)
{
    printChars((levels - level), " ");
    printChars(level, "#");
}

void buildRightSide(void)
{
    printChars(level, "#");
    printChars((levels - level), " ");
}

void printChars(int num, string chars)
{
    for ( int i = 0; i < num; i++ )
    {
        printf("%s", chars);
    }
}