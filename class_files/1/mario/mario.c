#include <stdio.h>
#include <cs50.h>

void printLine(string line, int n);
string blockLine = "####################################################################################################";
string emptyLineWithWall = "##                                                                                                ##";
string platformLine1 = "##      ############                                       ########################               ##";
string platformLine2 = "##                   ########################                                                  ##";
string questionMarks = "##                                      ???????                                                   ##";

int main(void)
{
    printLine(blockLine, 2);
    printLine(emptyLineWithWall, 2);
    printLine(platformLine1, 3);
    printLine(emptyLineWithWall, 2);
    printLine(questionMarks, 1);
    printLine(emptyLineWithWall, 1);
    printLine(blockLine, 2);
    printf("\n");
}

void printLine(string line, int n)
{
    for ( int counter = 0; counter < n; counter ++ )
    {
        printf("%s\n", line);
    }
}