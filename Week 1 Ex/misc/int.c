#include <cs50.h>
#include <stdio.h>

int main(void) //"when green flag clicked" for now
{
    int age = get_int("What is your age? ");
    int days = age * 365;
    int hours = days * 24;
    int minutes = hours * 60;
    int seconds = minutes * 60;
    long ms = seconds * 1000;
    printf("You are at least %i days old!\n", days);
    printf("You are at least %i hours old!\n", hours);
    printf("You are at least %i minutes old!\n", minutes);
    printf("You are at least %i seconds old!\n", seconds);
    printf("You are at least %li milliseconds old!\n", ms);
}