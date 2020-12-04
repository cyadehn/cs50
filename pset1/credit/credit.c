#include <stdio.h>
#include <limits.h>
#include <cs50.h>

void printDigits(long cardNum);
double power(double x, double y);
int getDigitNum(long cardNum);
bool isSingleDigit(long n);

int main(void)
{
    long num = 378282246310005;
    double places = getDigitNum(num);
    printf("%f", places);
    printDigits(num);
    //long cardNum = get_long("Please enter card number for verification: ");
    //printDigits(cardNum);
}

void printDigits(long num)
{
    long start = num;
    for ( int counter = 0; counter < getDigitNum(num); counter ++ )
    {
        printf("%li\n", start % 10);
        start /= 10;
        printf("%li\n", start);
    }
}

int getDigitNum(long n)
{
    long digits = 1;
    long tens = 10;
    if (isSingleDigit(n)) return 1;
    while ((n%tens)!=n)
    {
        //printf("Remainder: %li, ", n%tens);
        tens *= 10;
        digits++;
        //printf("Power of ten: %li, Digits: %li\n", tens, digits);
    }
    return digits;
    //if (n < 0) return getDigitNum((n == INT_MIN) ? INT_MAX : -n);
    //if (n < 10) return 1;
    //return 1 + getDigitNum(n/10);
}

bool isSingleDigit(long n)
{
    return n%10==n;
}

double power(double x, double y)
{
    if ( y == 0 )
    {
        return 1;
    }
    double pow = x;
    for ( int counter = 1; counter < y; counter++ )
    {
        pow *= x;
    }
    return pow;
}