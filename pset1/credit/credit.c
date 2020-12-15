#include <stdio.h>
#include <cs50.h>

void printDigits();
long long power();
int getDigitNum();
bool checksumCheck();
string getIssuer();
int getNumOfDigits();
bool isSingleDigit();
int getDigitAt();
long mod();


int main(void)
{
    long cardNum = get_long("Please enter your card number: ");
    printf("%ld\n", cardNum);
    /*int cardNumDigits = getDigitNum(cardNum);*/
    bool checksum = checksumCheck(cardNum);
    if (checksum)
    {
        string issuer = getIssuer(cardNum);
        printf("%s\n", issuer);
    }
    else
    {
        printf("INVALID\n");
    }
    //long cardNum = get_long("Please enter card number for verification: ");
    //printDigits(cardNum);
}

int getNumOfDigits(long cardNum)
{
    int digits = 1;
    long tens = 10;
    if (isSingleDigit(cardNum)) return 1;
    while ((cardNum%tens)!=cardNum)
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

bool checksumCheck(long cardNum)
{
    int checksumTotal;
    bool numIsEven;
    int cardNumDigits = getNumOfDigits(cardNum);
    printf("Total digits: %i\n", cardNumDigits);
    // If number is even, then first digit will be multiplied; if not, added
    numIsEven = cardNum % 2 == 0 ? true : false;
    printf("Card number is: %s\n", numIsEven ? "even" : "odd");
    if (getNumOfDigits(cardNum) < 13)
    {
        return false;
    }
    int digit;
    for ( int i = 1; i < cardNumDigits; i++ )
    {
        digit = getDigitAt(cardNum, i);
        // multiple if number is odd
        checksumTotal = numIsEven ? checksumTotal + (digit * 2) : checksumTotal + digit;
        /*printf("i: %i, digit: %i, checksum: %i\n", i, digit, checksumTotal);*/
        numIsEven = numIsEven ? false : true;
    }
    /*printf("Checksum total: %i\n", checksumTotal);*/
    return checksumTotal % 10 == 0 ? true : false;
}

int getDigitAt(long cardNum, int place)
{
    int totalDigits = getNumOfDigits(cardNum);
    long upperMod = power(10, (totalDigits - place));
    long digitBase = cardNum / upperMod;
    printf("%ld (cardNum) mod %ld (upperMod) = %ld (digitBase)\n", cardNum, upperMod, digitBase);
    long divisor = power(10, place - 1);
    int digit = mod(digitBase, divisor);
    printf("%ld / %ld = %i\n", digitBase, divisor, digit);
    return (int)digit;
}

string getIssuer(long cardNum)
{
    string amex = "AMEX\n";
    string mc = "MASTERCARD\n";
    string visa = "VISA\n";
    string inv = "INVALID\n";
    int cardNumDigits = getNumOfDigits(cardNum);
    int digit1 = getDigitAt(cardNum, 1);
    int digit2 = getDigitAt(cardNum, 2);
    switch(cardNumDigits)
    {
        case 16:
            if (digit1 == 4)
            {
                return visa;
            }
            else if (digit1 == 5 && digit2 > 0 && digit2 < 6)
            {
                return mc;
            }
            else
            {
                return inv;
            }
        case 13:
            return digit1 == 4 ? visa : inv;
        case 15:
            return (digit1 == 3 && (digit2 == 4 || digit2 == 7)) ? amex : inv;
    }
    return inv;
}

bool isSingleDigit(long n)
{
    return n%10==n;
}

long long power(long x, long y)
{
    if ( y == 0 )
    {
        return 1;
    }
    long long pow = x;
    for ( int counter = 1; counter < y; counter++ )
    {
        pow *= x;
    }
    return pow;
}

long mod(long x, long y)
{
    long ones = x/y;
    double remainder = (x/y) - ones;
    return remainder * y;
}
