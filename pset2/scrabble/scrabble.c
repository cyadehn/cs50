#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);
string strToUpper(string s);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    string message = (score1 > score2) ? "Player 1 wins!" : "Player 2 wins!";
    printf("%s\n", message);
}

int compute_score(string word)
{
    // Compute and return score for string
    string upper = strToUpper(word);
    int score = 0;
    for (int i = 0, n = strlen(upper); i < n; i++)
    {
        // check if character is an uppercase character
        if(upper[i] >= 'A' && upper[i] <= 'Z')
        {
            score += POINTS[upper[i]-65];
        }
    }
    return score;
}

string strToUpper(string s)
{
    // store in local value to prevent altering original reference array
    string t = s;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // convert passed string chars, assign to respective position in local string
        if (s[i] < 'a' || s[i] > 'z')
        {
            t[i] = s[i];
        }
        else
        {
            t[i] = toupper(s[i]);
        }
    }
    return t;
}
