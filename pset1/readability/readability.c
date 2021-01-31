#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <cs50.h>

int count_letters();
int count_words();
int count_sentences();
int calculate_cl_index();

int main(void)
{
    // DONE: Prompt user for string of text
    string text = get_string("Text: ");
    // DONE: Count number of letters, words, and sentences (ending in . ! ?)
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    // DONE: Determine grade level (rounded to nearest integer) using the Coleman-Liau formula:
    // index = 0.0588 * L - 0.296 * S - 15.8
    // A grade higher than 16 should output "16+", lower than 1 is "Before Grade 1"
    int grade = calculate_cl_index(letters, words, sentences);
    // DONE: Pround output as "Grade X"
    if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int count_letters(string text)
{
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalnum(text[i]))
        {
            count ++;
        }
    }
    return count;
}

int count_words(string text)
{
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ' || i == (strlen(text) - 1))
        {
            count ++;
        }
    }
    return count;
}
int count_sentences(string text)
{
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!' || i == strlen(text) - 1)
        {
            count ++;
        }
    }
    return count;
}

int calculate_cl_index(int l, int w, int s)
{
    float letters = (float)l;
    float words = (float)w;
    float sentences = (float)s;
    int L = round((letters / words) * 100);
    int S = round((sentences / words) * 100);
    return round(0.0588 * L - 0.296 * S - 15.8);
}
